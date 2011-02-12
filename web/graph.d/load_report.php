<?php

/* Pass in by reference! */
function graph_load_report( &$rrdtool_graph ) 
{
    global $context,
           $cpu_num_color,
           $cpu_user_color,
           $hostname,
           $load_one_color,
           $num_nodes_color,
           $proc_run_color,
           $range,
           $rrd_dir,
           $size,
           $strip_domainname,
           $graphreport_stats;

    if ($strip_domainname) {
       $hostname = strip_domainname($hostname);
    }

    $rrdtool_graph['height'] += ($size == 'medium') ? 28 : 0;
    if ( $graphreport_stats ) {
        $rrdtool_graph['height'] += ($size == 'medium') ? 28 : 0;

        if ( $hostname != '' ) {
            $rrdtool_graph['height'] += ($size == 'medium') ? 12 : 0;
        }
        $rmspace = '\\g';
    } else {
        $rmspace = '';
    }

    $title = 'Load';

    if ($context != 'host') {
       $rrdtool_graph['title'] = $title;
    } else {
       $rrdtool_graph['title'] = "$hostname $title last $range";
    }

    $rrdtool_graph['lower-limit'] = '0';
    $rrdtool_graph['vertical-label'] = 'Load/Procs';
    $rrdtool_graph['extras'] = ($graphreport_stats == true) ? ' --font LEGEND:7' : '';

    if ($size == 'small') {
       $eol1 = '\\l';
       $space1 = ' ';
       $space2 = '         ';
    } else if ($size == 'medium' || $size == 'default') {
       $eol1 = '';
       $space1 = '';
       $space2 = '';
    } else if ($size == 'large') {
       $eol1 = '';
       $space1 = '                 ';
       $space2 = '                 ';
    }

    $series = "DEF:'load_one'='${rrd_dir}/load_one.rrd':'sum':AVERAGE "
            . "DEF:'proc_run'='${rrd_dir}/proc_run.rrd':'sum':AVERAGE "
            . "DEF:'cpu_num'='${rrd_dir}/cpu_num.rrd':'sum':AVERAGE "
            . "AREA:'load_one'#$load_one_color:'1-min${rmspace}' ";

    if ($graphreport_stats ) {
        $series .= "CDEF:load_pos=load_one,0,INF,LIMIT "
                . "VDEF:load_last=load_pos,LAST "
                . "VDEF:load_min=load_pos,MINIMUM "
                . "VDEF:load_avg=load_pos,AVERAGE "
                . "VDEF:load_max=load_pos,MAXIMUM "
                . "GPRINT:'load_last':' ${space1}Now\:%6.1lf%s' "
                . "GPRINT:'load_min':'${space1}Min\:%6.1lf%s${eol1}' "
                . "GPRINT:'load_avg':'${space2}Avg\:%6.1lf%s' "
                . "GPRINT:'load_max':'${space1}Max\:%6.1lf%s\\l' ";
    }

    if ( $context != 'host' ) {
        $series .= "DEF:'num_nodes'='${rrd_dir}/cpu_num.rrd':'num':AVERAGE "
                . "LINE2:'num_nodes'#$num_nodes_color:'Nodes${rmspace}' ";

        if ($graphreport_stats ) {
            $series .= "CDEF:numnod_pos=num_nodes,0,INF,LIMIT "
                    . "VDEF:numnod_last=numnod_pos,LAST "
                    . "VDEF:numnod_min=numnod_pos,MINIMUM "
                    . "VDEF:numnod_avg=numnod_pos,AVERAGE "
                    . "VDEF:numnod_max=numnod_pos,MAXIMUM "
                    . "GPRINT:'numnod_last':' ${space1}Now\:%6.1lf%s' "
                    . "GPRINT:'numnod_min':'${space1}Min\:%6.1lf%s${eol1}' "
                    . "GPRINT:'numnod_avg':'${space2}Avg\:%6.1lf%s' "
                    . "GPRINT:'numnod_max':'${space1}Max\:%6.1lf%s\\l' ";
        }
    }

    $series .="LINE2:'cpu_num'#$cpu_num_color:'CPUs${rmspace}' ";

    if ( $graphreport_stats ) {
        $series .= "CDEF:cpun_pos=cpu_num,0,INF,LIMIT "
                . "VDEF:cpun_last=cpun_pos,LAST "
                . "VDEF:cpun_min=cpun_pos,MINIMUM "
                . "VDEF:cpun_avg=cpun_pos,AVERAGE "
                . "VDEF:cpun_max=cpun_pos,MAXIMUM "
                . "GPRINT:'cpun_last':'  ${space1}Now\:%6.1lf%s' "
                . "GPRINT:'cpun_min':'${space1}Min\:%6.1lf%s${eol1}' "
                . "GPRINT:'cpun_avg':'${space2}Avg\:%6.1lf%s' "
                . "GPRINT:'cpun_max':'${space1}Max\:%6.1lf%s\\l' ";
    }
    $series .="LINE2:'proc_run'#$proc_run_color:'Procs${rmspace}' ";

    if ( $graphreport_stats ) {
        $series .= "CDEF:procr_pos=proc_run,0,INF,LIMIT "
                . "VDEF:procr_last=procr_pos,LAST "
                . "VDEF:procr_min=procr_pos,MINIMUM "
                . "VDEF:procr_avg=procr_pos,AVERAGE "
                . "VDEF:procr_max=procr_pos,MAXIMUM "
                . "GPRINT:'procr_last':' ${space1}Now\:%6.1lf%s' "
                . "GPRINT:'procr_min':'${space1}Min\:%6.1lf%s${eol1}' "
                . "GPRINT:'procr_avg':'${space2}Avg\:%6.1lf%s' "
                . "GPRINT:'procr_max':'${space1}Max\:%6.1lf%s\\l' ";
    }

    $rrdtool_graph['series'] = $series;

    return $rrdtool_graph;
}

?>
