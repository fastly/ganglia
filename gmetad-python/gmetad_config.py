from socket import getfqdn
import os
import sys
import optparse

class GmetadRRA:
    def __init__(self, args):
        self.args = args
        
class GmetadDataSource:
    def  __init__(self, name, hosts=['localhost'], interval=15):
        self.name = name
        self.hosts = hosts
        self.interval = interval
        self.time_to_next_read = 0

class GmetadConfig:
    _shared_state = {}
    
    _isInitialized = False
    
    DEBUG_LEVEL = 'debug_level'
    LOGFILE = 'logfile'
    PIDFILE = 'pidfile'
    DATA_SOURCE = 'data_source'
    RRAS = 'RRAs'
    SCALABLE = 'scalable'
    GRIDNAME = 'gridname'
    AUTHORITY = 'authority'
    TRUSTED_HOSTS = 'trusted_hosts'
    ALL_TRUSTED = 'all_trusted'
    SETUID = 'setuid'
    SETUID_USERNAME = 'setuid_username'
    XML_PORT = 'xml_port'
    INTERACTIVE_PORT = 'interactive_port'
    SERVER_THREADS = 'server_threads'
    RRD_ROOTDIR = 'rrd_rootdir'
    
    _cfgDefaults = {
            DEBUG_LEVEL : 2,
            LOGFILE : None,
            PIDFILE : None,
            DATA_SOURCE : [],
            RRAS : [
                    GmetadRRA('AVERAGE:0.5:1:244'),
                    GmetadRRA('AVERAGE:0.5:24:244'),
                    GmetadRRA('AVERAGE:0.5:168:244'),
                    GmetadRRA('AVERAGE:0.5:672:244'),
                    GmetadRRA('AVERAGE:0.5:5760:374')
            ],
            SCALABLE : True,
            GRIDNAME : 'unspecified',
            AUTHORITY : 'http://%s/ganglia/' % getfqdn(),
            TRUSTED_HOSTS : [],
            ALL_TRUSTED : False,
            SETUID : True,
            SETUID_USERNAME : 'nobody',
            XML_PORT : 8651,
            INTERACTIVE_PORT : 8652,
            SERVER_THREADS : 4,
            RRD_ROOTDIR : '/var/lib/ganglia/rrds'
    }
    
    
    def __init__(self, cfgpath=None):
        self.__dict__ = GmetadConfig._shared_state
        
        if cfgpath is not None:
            self.path = cfgpath
            self.resetToDefaults()
            
            self.kwHandlers = {
                GmetadConfig.DEBUG_LEVEL : self.parseDbgLevel,
                GmetadConfig.LOGFILE : self.parseLogfile,
                GmetadConfig.DATA_SOURCE : self.parseDataSource,
                GmetadConfig.RRAS : self.parseRRAs,
                GmetadConfig.SCALABLE : self.parseScalable,
                GmetadConfig.GRIDNAME : self.parseGridname,
                GmetadConfig.AUTHORITY : self.parseAuthority,
                GmetadConfig.TRUSTED_HOSTS : self.parseTrustedHosts,
                GmetadConfig.ALL_TRUSTED : self.parseAllTrusted,
                GmetadConfig.SETUID : self.parseSetuid,
                GmetadConfig.SETUID_USERNAME : self.parseSetuidUsername,
                GmetadConfig.XML_PORT : self.parseXmlPort,
                GmetadConfig.INTERACTIVE_PORT : self.parseInteractivePort,
                GmetadConfig.SERVER_THREADS : self.parseServerThreads,
                GmetadConfig.RRD_ROOTDIR : self.parseRrdRootdir
            }
            self.updateConfig()
            GmetadConfig._isInitialized = True
        
    def updateConfig(self):
        f = open(self.path, 'r')
        prev_line = None
        for line in f.readlines():
            if line.startswith('#'): continue
            if 0 >= len(line.strip()): continue
            if line.strip().endswith('\\'):
                if prev_line is None:
                    prev_line = line.strip().strip('\\')
                else:
                    prev_line += line.strip().strip('\\')
                continue
            elif prev_line is not None:
                prev_line += line.strip()
                line = prev_line
                prev_line = None
            kw, args = line.strip().split(None,1)
            if self.kwHandlers.has_key(kw):
                self.kwHandlers[kw](args)
                
    def __setitem__(self, k, v):
        self.cfg[k] = v
        
    def __getitem__(self, k):
        return self.cfg[k]
        
    def resetToDefaults(self):
        self.cfg = GmetadConfig._cfgDefaults
        
    def parseDbgLevel(self, level):
        v = level.strip()
        if v.isdigit():
            self.cfg[GmetadConfig.DEBUG_LEVEL] = v
            
    def parseLogfile(self, logfile):
        self.cfg[GgmetadConfig.LOGFILE] = logfile.strip().strip('"')
            
    def parseDataSource(self, args):
        a = args.split('"')
        name = a[1]
        a = a[2].strip().split()
        if a[0].isdigit():
            interval = int(a[0])
            hosts = a[1:]
        else:
            interval = 15
            hosts = a[0:]
        self.cfg[GmetadConfig.DATA_SOURCE].append(GmetadDataSource(name, hosts, interval))
        
    def parseRRAs(self, args):
        self.cfg[GmetadConfig.RRAS] = []
        for rraspec in args:
            self.cfg[GmetadConfig.RRAS].append(GmetadRRA(rraspec.strip().strip('"').split(':',1)[1]))
            
    def parseScalable(self, arg):
        v = arg.strip().lower()
        if v == 'off' or v == 'false' or v == 'no':
            self.cfg[GmetadConfig.SCALABLE] = False
        else:
            self.cfg[GmetadConfig.SCALABLE] = True
            
    def parseGridname(self, arg):
        self.cfg[GmetadConfig.GRIDNAME] = arg.strip().strip('"')
        
    def parseAuthority(self, arg):
        self.cfg[GmetadConfig.AUTHORITY] = arg.strip().strip('"')
        
    def parseTrustedHosts(self, args):
        if len(args):
            self.cfg[GmetadConfig.TRUSTED_HOSTS] = args
            
    def parseAllTrusted(self, arg):
        v = arg.strip().lower()
        if v == 'on' or v == 'true' or v == 'yes':
            self.cfg[GmetadConfig.ALL_TRUSTED] = True
        else:
            self.cfg[GmetadConfig.ALL_TRUSTED] = False
            
    def parseSetuid(self, arg):
        v = arg.strip().lower()
        if v == 'off' or v == 'false' or v == 'no':
            self.cfg[GmetadConfig.SETUID] = False
        else:
            self.cfg[GmetadConfig.SETUID] = True
            
    def parseSetuidUsername(self, arg):
        self.cfg[GmetadConfig.SETUID_USERNAME] = arg.strip().strip('"')
        
    def parseXmlPort(self, arg):
        v = arg.strip()
        if v.isdigit():
            self.cfg[GmetadConfig.XML_PORT] = int(v)
            
    def parseInteractivePort(self, arg):
        v = arg.strip()
        if v.isdigit():
            self.cfg[GmetadConfig.INTERACTIVE_PORT] = int(v)
        
    def parseServerThreads(self, arg):
        v = arg.strip()
        if v.isdigit():
            self.cfg[GmetadConfigSERVER_THREADS] = int(v)
        
    def parseRrdRootdir(self, arg):
        v = arg.strip().strip('"')
        if os.path.isdir(v):
            self.cfg[GmetadConfig] = v
        

def getConfig(args=sys.argv):
    if GmetadConfig._isInitialized:
        return GmetadConfig()
    dbgLevelDefault = GmetadConfig._cfgDefaults[GmetadConfig.DEBUG_LEVEL]
    iPortDefault = GmetadConfig._cfgDefaults[GmetadConfig.INTERACTIVE_PORT]
    xPortDefault = GmetadConfig._cfgDefaults[GmetadConfig.XML_PORT]
    parser = optparse.OptionParser()
    parser.add_option('-V', '--version', action='version',
            help='Print version and exit')
    parser.add_option('-d', '--debug', action='store',
            help='Debug level. If five (5) or greater, daemon will stay in foreground.  Values are:\n\
            0 - FATAL\n\
            1 - CRITICAL\n\
            2 - ERROR (default)\n\
            3 - WARNING\n\
            4 - INFO\n\
            5 - DEBUG',
            default='%d' % dbgLevelDefault)
    parser.add_option('-p', '--pid_file', action='store',
            help='Write process-id to file',
            default=None)
    parser.add_option('-c', '--conf', action='store',
            help='Location of gmetad configuration file (default=\'/etc/ganglia/gmetad.conf\')',
            default='/etc/ganglia/gmetad.conf')
    parser.add_option('-l', '--logfile', action='store',
            help='Log messages to this path in addition to syslog; overrides configuration',
            default=None)
    parser.add_option('-i', '--interactive_port', action='store',
            help='Interactive port to listen on (default=%d)' % iPortDefault,
            default='%d' % iPortDefault)
    parser.add_option('-x', '--xml_port', action='store',
            help='XML port to listen on (default=%d)' % xPortDefault,
            default='%d' % xPortDefault)
            
    options, arguments = parser.parse_args()
    
    if not options.debug.isdigit():
        print 'Invalid numeric value for --debug: %s' % options.debug
        parser.print_help()
        sys.exit()
    elif not options.interactive_port.isdigit():
        print 'Invalid numeric value for --interactive_port: %s' % options.interactive_port
        sys.exit()
    elif not options.xml_port.isdigit():
        print 'Invalid numeric value for --xml_port: %s' % options.xml_port
        sys.exit()
    elif not os.path.exists(options.conf):
        print 'No such configuration file: %s' % options.conf
        parser.print_help()
        sys.exit()
        
    cfg = GmetadConfig(options.conf)
    
    # Update configuration if non-default values were provided.
    if dbgLevelDefault != options.debug:
        cfg[GmetadConfig.DEBUG_LEVEL] = options.debug
    if iPortDefault != options.interactive_port:
        cfg[GmetadConfig.INTERACTIVE_PORT] = options.interactive_port
    if xPortDefault != options.xml_port:
        cfg[GmetadConfig.XML_PORT] = options.xml_port
    if options.logfile is not None:
        cfg[GmetadConfig.LOGFILE] = options.logfile
    if options.pid_file is not None:
        cfg[GmetadConfig.PIDFILE] = options.pid_file
        
    return cfg
    
