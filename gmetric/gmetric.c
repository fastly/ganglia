#include <ganglia.h>
#include <ganglia/hash.h>
#include "metric_typedefs.h"
#include "node_data_t.h"
#include "cmdline.h"
#include <string.h>

extern int optopt;
extern int optind;
extern char *optarg;
extern int opterr;

datum_t type;
datum_t name;
datum_t value;
datum_t units;

struct gengetopt_args_info args_info;

int main ( int argc, char **argv )
{
   int rval, len;
   XDR xhandle;
   char mcast_data[MAX_MCAST_MSG]; 
   int mcastfd;
   uint32_t key = 0; /* user-defined */
   char empty[] = "\0";

   if (cmdline_parser (argc, argv, &args_info) != 0)
      exit(1) ;

   if (!( !strcmp("string", args_info.type_arg)
       || !strcmp("int8", args_info.type_arg)
       || !strcmp("uint8", args_info.type_arg)
       || !strcmp("int16", args_info.type_arg)
       || !strcmp("uint16", args_info.type_arg)
       || !strcmp("int32", args_info.type_arg)
       || !strcmp("uint32", args_info.type_arg)
       || !strcmp("float", args_info.type_arg)
       || !strcmp("double", args_info.type_arg)))
      {
         fprintf(stderr,"\nInvalid type: %s\n\n", args_info.type_arg);
         fprintf(stderr,"Run %s --help\n\n", argv[0]);
         exit(-1);
      }  

   if(args_info.mcast_if_given)
      mcastfd = mcast_connect(args_info.mcast_channel_arg, args_info.mcast_port_arg, 
                              args_info.mcast_if_arg, args_info.mcast_ttl_arg);
   else
      mcastfd = mcast_connect(args_info.mcast_channel_arg, args_info.mcast_port_arg,
                              NULL, args_info.mcast_ttl_arg);
   if ( mcastfd == SYNAPSE_FAILURE )
      {
         err_msg("unable to connect to multicast %s:%d", args_info.mcast_channel_arg, args_info.mcast_port_arg);
         return SYNAPSE_FAILURE;
      }

   name.data = args_info.name_arg;
   name.size = strlen( name.data )+1;
      if (strcspn(name.data," \t") == 0)
              err_quit("gmetric: --name (-n) can't be blank or empty"); 

   value.data = args_info.value_arg;
   value.size = strlen( value.data )+1;
   type.data = args_info.type_arg;
   type.size = strlen(type.data)+1;
   if( args_info.units_given )
      {
         units.data = args_info.units_arg;
         units.size = strlen( units.data )+1;
      }
   else
      {
         units.data = empty;
         units.size = 1;
      }

   xdrmem_create(&xhandle, mcast_data, MAX_MCAST_MSG, XDR_ENCODE);

   rval = xdr_u_int(&xhandle, &key);
   if ( rval == 0 )
      {
         err_ret("xdr_u_int for key failed");
         return SYNAPSE_FAILURE;
      }

   rval = xdr_bytes(&xhandle, (char **)&(type.data), &(type.size), MAX_TYPE_LEN);
   if ( rval == 0 )
      {
         err_ret("xdr_bytes() for type failed");
         return SYNAPSE_FAILURE;
      }
   rval = xdr_bytes(&xhandle, (char **)&(name.data),  &(name.size),  MAX_MCAST_MSG); 
   if ( rval == 0 )
      {
         err_ret("xdr_bytes() for name failed");
         return SYNAPSE_FAILURE;
      }
   rval = xdr_bytes(&xhandle, (char **)&(value.data), &(value.size), MAX_VAL_LEN);
   if ( rval == 0 )
      {
         err_ret("xdr_bytes() for value failed");
         return SYNAPSE_FAILURE;
      }
   rval = xdr_bytes(&xhandle, (char **)&(units.data), &(units.size), MAX_UNITS_LEN);
   if ( rval == 0 )
      {
         err_ret("xdr_bytes() for units failed");
         return SYNAPSE_FAILURE;
      }

   len = xdr_getpos(&xhandle); 

   rval = writen( mcastfd, mcast_data, len );
   if ( rval <0)
      {
         err_ret("unable to send data on multicast channel");
         return SYNAPSE_FAILURE;
      } 

   return 0;
}
