SFLOW_GMETRIC(SFLOW_M_load_one,"load_one","", GANGLIA_SLOPE_BOTH,"%.2f","load",NULL,"One minute load average")
SFLOW_GMETRIC(SFLOW_M_load_five,"load_five","", GANGLIA_SLOPE_BOTH,"%.2f","load",NULL,"Five minute load average")
SFLOW_GMETRIC(SFLOW_M_load_fifteen,"load_fifteen","", GANGLIA_SLOPE_BOTH,"%.2f","load",NULL,"Fifteen minute load average")
SFLOW_GMETRIC(SFLOW_M_os_release, "os_release", "", GANGLIA_SLOPE_ZERO, "%s", "system", NULL, "Operating System Release" )
SFLOW_GMETRIC(SFLOW_M_machine_type, "machine_type", "", GANGLIA_SLOPE_ZERO, "%s", "system", NULL, "Machine Type" )
SFLOW_GMETRIC(SFLOW_M_os_name, "os_name", "", GANGLIA_SLOPE_ZERO, "%s", "system", NULL, "Operating System" )
SFLOW_GMETRIC(SFLOW_M_uuid, "uuid", "", GANGLIA_SLOPE_ZERO, "%s", "system", NULL, "System UUID" )
SFLOW_GMETRIC(SFLOW_M_heartbeat, "heartbeat", "", GANGLIA_SLOPE_ZERO, "%u", "system", NULL, "Heartbeat" )
SFLOW_GMETRIC(SFLOW_M_proc_run, "proc_run", "", GANGLIA_SLOPE_BOTH, "%u", "process", NULL, "Total Running Processes" )
SFLOW_GMETRIC(SFLOW_M_proc_total, "proc_total", "", GANGLIA_SLOPE_BOTH, "%u", "process", NULL, "Total Processes" )
SFLOW_GMETRIC(SFLOW_M_cpu_num, "cpu_num", "CPUs", GANGLIA_SLOPE_ZERO, "%u", "cpu", NULL, "CPU Count" )
SFLOW_GMETRIC(SFLOW_M_cpu_speed, "cpu_speed", "MHz", GANGLIA_SLOPE_ZERO, "%u", "cpu", NULL, "CPU Speed" )
SFLOW_GMETRIC(SFLOW_M_cpu_boottime, "boottime", "s", GANGLIA_SLOPE_ZERO, "%u", "cpu", NULL, "Last Boot Time" )
SFLOW_GMETRIC(SFLOW_M_cpu_user, "cpu_user", "%", GANGLIA_SLOPE_BOTH, "%.2f", "cpu", NULL, "CPU User" )
SFLOW_GMETRIC(SFLOW_M_cpu_nice, "cpu_nice", "%", GANGLIA_SLOPE_BOTH, "%.2f", "cpu", NULL, "CPU Nice" )
SFLOW_GMETRIC(SFLOW_M_cpu_system, "cpu_system", "%", GANGLIA_SLOPE_BOTH, "%.2f", "cpu", NULL, "CPU System" )
SFLOW_GMETRIC(SFLOW_M_cpu_idle, "cpu_idle", "%", GANGLIA_SLOPE_BOTH, "%.2f", "cpu", NULL, "CPU Idle" )
SFLOW_GMETRIC(SFLOW_M_cpu_wio, "cpu_wio", "%", GANGLIA_SLOPE_BOTH, "%.2f", "cpu", NULL, "CPU I/O Wait" )
SFLOW_GMETRIC(SFLOW_M_cpu_intr, "cpu_intr", "", GANGLIA_SLOPE_BOTH, "%.2f", "cpu", NULL, "CPU Interrupts" )
SFLOW_GMETRIC(SFLOW_M_cpu_sintr, "cpu_sintr", "", GANGLIA_SLOPE_BOTH, "%.2f", "cpu", NULL, "CPU Soft Interrupts" )
SFLOW_GMETRIC(SFLOW_M_interrupts, "interrupts", "", GANGLIA_SLOPE_BOTH, "%.0f", "cpu", NULL, "Interrupts" )
SFLOW_GMETRIC(SFLOW_M_contexts, "contexts", "", GANGLIA_SLOPE_BOTH, "%.0f", "cpu", NULL, "Context Switches" )
SFLOW_GMETRIC(SFLOW_M_mem_total, "mem_total", "KB", GANGLIA_SLOPE_ZERO, "%.0f", "memory", NULL, "Memory Total" )
SFLOW_GMETRIC(SFLOW_M_mem_free, "mem_free", "KB", GANGLIA_SLOPE_BOTH, "%.0f", "memory", NULL, "Free Memory" )
SFLOW_GMETRIC(SFLOW_M_mem_shared, "mem_shared", "KB", GANGLIA_SLOPE_BOTH, "%.0f", "memory", NULL, "Shared Memory" )
SFLOW_GMETRIC(SFLOW_M_mem_buffers, "mem_buffers", "KB", GANGLIA_SLOPE_BOTH, "%.0f", "memory", NULL, "Memory Buffers" )
SFLOW_GMETRIC(SFLOW_M_mem_cached, "mem_cached", "KB", GANGLIA_SLOPE_BOTH, "%.0f", "memory", NULL, "Cached Memory" )
SFLOW_GMETRIC(SFLOW_M_swap_total, "swap_total", "KB", GANGLIA_SLOPE_ZERO, "%.0f", "memory", NULL, "Swap Space Total" )
SFLOW_GMETRIC(SFLOW_M_swap_free, "swap_free", "KB", GANGLIA_SLOPE_BOTH, "%.0f", "memory", NULL, "Free Swap Space" )
SFLOW_GMETRIC(SFLOW_M_page_in, "page_in", "", GANGLIA_SLOPE_BOTH, "%.0f", "memory", NULL, "Pages In" )
SFLOW_GMETRIC(SFLOW_M_page_out, "page_out", "", GANGLIA_SLOPE_BOTH, "%.0f", "memory", NULL, "Pages Out" )
SFLOW_GMETRIC(SFLOW_M_swap_in, "swap_in", "", GANGLIA_SLOPE_BOTH, "%.0f", "memory", NULL, "Swap Pages In" )
SFLOW_GMETRIC(SFLOW_M_swap_out, "swap_out", "", GANGLIA_SLOPE_BOTH, "%.0f", "memory", NULL, "Swap Pages Out" )
SFLOW_GMETRIC(SFLOW_M_disk_total, "disk_total", "GB", GANGLIA_SLOPE_BOTH, "%.3f", "disk", NULL, "Total Disk Space" )
SFLOW_GMETRIC(SFLOW_M_disk_free, "disk_free", "GB", GANGLIA_SLOPE_BOTH, "%.3f", "disk", NULL, "Free Disk Space" )
SFLOW_GMETRIC(SFLOW_M_part_max_used, "part_max_used", "%", GANGLIA_SLOPE_BOTH, "%.2f", "disk", NULL, "Maximum Disk Space Used" )
SFLOW_GMETRIC(SFLOW_M_reads, "reads", "", GANGLIA_SLOPE_BOTH, "%.0f", "disk", NULL, "Reads" )
SFLOW_GMETRIC(SFLOW_M_bytes_read, "bytes_read", "", GANGLIA_SLOPE_BOTH, "%.0f", "disk", NULL, "Bytes Read" )
SFLOW_GMETRIC(SFLOW_M_read_time, "read_time", "%", GANGLIA_SLOPE_BOTH, "%.0f", "disk", NULL, "Read Time" )
SFLOW_GMETRIC(SFLOW_M_writes, "writes", "", GANGLIA_SLOPE_BOTH, "%.0f", "disk", NULL, "Writes" )
SFLOW_GMETRIC(SFLOW_M_bytes_written, "bytes_written", "", GANGLIA_SLOPE_BOTH, "%.0f", "disk", NULL, "Bytes Written" )
SFLOW_GMETRIC(SFLOW_M_write_time, "write_time", "%", GANGLIA_SLOPE_BOTH, "%.0f", "disk", NULL, "Write Time" )
SFLOW_GMETRIC(SFLOW_M_bytes_in, "bytes_in", "bytes/sec", GANGLIA_SLOPE_BOTH, "%.2f", "network", NULL, "Bytes Received" )
SFLOW_GMETRIC(SFLOW_M_pkts_in, "pkts_in", "packets/sec", GANGLIA_SLOPE_BOTH, "%.2f", "network", NULL, "Packets Received" )
SFLOW_GMETRIC(SFLOW_M_errs_in, "errs_in", "errors/sec", GANGLIA_SLOPE_BOTH, "%.2f", "network", NULL, "Input Errors" )
SFLOW_GMETRIC(SFLOW_M_drops_in, "drops_in", "drops/sec", GANGLIA_SLOPE_BOTH, "%.2f", "network", NULL, "Input Drops" )
SFLOW_GMETRIC(SFLOW_M_bytes_out, "bytes_out", "bytes/sec", GANGLIA_SLOPE_BOTH, "%.2f", "network", NULL, "Bytes Sent" )
SFLOW_GMETRIC(SFLOW_M_pkts_out, "pkts_out", "packets/sec", GANGLIA_SLOPE_BOTH, "%.2f", "network", NULL, "Packets Sent" )
SFLOW_GMETRIC(SFLOW_M_errs_out, "errs_out", "errors/sec", GANGLIA_SLOPE_BOTH, "%.2f", "network", NULL, "Output Errors" )
SFLOW_GMETRIC(SFLOW_M_drops_out, "drops_out", "drops/sec", GANGLIA_SLOPE_BOTH, "%.2f", "network", NULL, "Output Drops" )
SFLOW_GMETRIC(SFLOW_M_vnode_mem_total, "vnode_mem_total", "KB", GANGLIA_SLOPE_ZERO, "%.0f", "hypervisor", NULL, "Hypervisor Memory Total" )
SFLOW_GMETRIC(SFLOW_M_vnode_mem_free, "vnode_mem_free", "KB", GANGLIA_SLOPE_BOTH, "%.0f", "hypervisor", NULL, "Hypervisor Free Memory" )
SFLOW_GMETRIC(SFLOW_M_vnode_cpu_speed, "vnode_cpu_speed", "MHz", GANGLIA_SLOPE_ZERO, "%u", "hypervisor", NULL, "Hypervisor CPU Speed" )
SFLOW_GMETRIC(SFLOW_M_vnode_cpu_num, "vnode_cpu_num", "", GANGLIA_SLOPE_ZERO, "%u", "hypervisor", NULL, "Hypervisor CPU Count" )
SFLOW_GMETRIC(SFLOW_M_vnode_domains, "vnode_domains", "", GANGLIA_SLOPE_BOTH, "%u", "hypervisor", NULL, "Hypervisor Domain Count" )
SFLOW_GMETRIC(SFLOW_M_vcpu_state, "vcpu_state", "", GANGLIA_SLOPE_ZERO, "%s", "cpu", NULL, "VM CPU State" )
SFLOW_GMETRIC(SFLOW_M_vcpu_util, "vcpu_util", "%", GANGLIA_SLOPE_BOTH, "%.2f", "cpu", NULL, "VM CPU Utilization" )
SFLOW_GMETRIC(SFLOW_M_vcpu_num, "vcpu_num", "", GANGLIA_SLOPE_ZERO, "%u", "cpu", NULL, "VM CPU Count" )
SFLOW_GMETRIC(SFLOW_M_vmem_total, "vmem_total", "KB", GANGLIA_SLOPE_ZERO, "%.0f", "memory", NULL, "VM Memory Total" )
SFLOW_GMETRIC(SFLOW_M_vmem_util, "vmem_util", "%", GANGLIA_SLOPE_ZERO, "%.2f", "memory", NULL, "VM Memory Utilization" )
SFLOW_GMETRIC(SFLOW_M_vdisk_capacity, "vdisk_capacity", "GB", GANGLIA_SLOPE_ZERO, "%.3f", "disk", NULL, "VDisk Capacity" )
SFLOW_GMETRIC(SFLOW_M_vdisk_total, "vdisk_total", "GB", GANGLIA_SLOPE_BOTH, "%.3f", "disk", NULL, "Total VDisk Space" )
SFLOW_GMETRIC(SFLOW_M_vdisk_free, "vdisk_free", "GB", GANGLIA_SLOPE_BOTH, "%.3f", "disk", NULL, "Free VDisk Space" )
SFLOW_GMETRIC(SFLOW_M_vdisk_reads, "vdisk_reads", "", GANGLIA_SLOPE_BOTH, "%.0f", "disk", NULL, "VM Reads" )
SFLOW_GMETRIC(SFLOW_M_vdisk_bytes_read, "vdisk_bytes_read", "", GANGLIA_SLOPE_BOTH, "%.0f", "disk", NULL, "VM Bytes Read" )
SFLOW_GMETRIC(SFLOW_M_vdisk_writes, "vdisk_writes", "", GANGLIA_SLOPE_BOTH, "%.0f", "disk", NULL, "VM Writes" )
SFLOW_GMETRIC(SFLOW_M_vdisk_bytes_written, "vdisk_bytes_written", "", GANGLIA_SLOPE_BOTH, "%.0f", "disk", NULL, "VM Bytes Written" )
SFLOW_GMETRIC(SFLOW_M_vdisk_errs, "vdisk_errs", "errors/sec", GANGLIA_SLOPE_BOTH, "%.2f", "disk", NULL, "VM Disk Errors" )
SFLOW_GMETRIC(SFLOW_M_vbytes_in, "vbytes_in", "bytes/sec", GANGLIA_SLOPE_BOTH, "%.2f", "network", NULL, "VM Bytes Received" )
SFLOW_GMETRIC(SFLOW_M_vpkts_in, "vpkts_in", "packets/sec", GANGLIA_SLOPE_BOTH, "%.2f", "network", NULL, "VM Packets Received" )
SFLOW_GMETRIC(SFLOW_M_verrs_in, "verrs_in", "errors/sec", GANGLIA_SLOPE_BOTH, "%.2f", "network", NULL, "VM Input Errors" )
SFLOW_GMETRIC(SFLOW_M_vdrops_in, "vdrops_in", "drops/sec", GANGLIA_SLOPE_BOTH, "%.2f", "network", NULL, "VM Input Drops" )
SFLOW_GMETRIC(SFLOW_M_vbytes_out, "vbytes_out", "bytes/sec", GANGLIA_SLOPE_BOTH, "%.2f", "network", NULL, "VM Bytes Sent" )
SFLOW_GMETRIC(SFLOW_M_vpkts_out, "vpkts_out", "packets/sec", GANGLIA_SLOPE_BOTH, "%.2f", "network", NULL, "VM Packets Sent" )
SFLOW_GMETRIC(SFLOW_M_verrs_out, "verrs_out", "errors/sec", GANGLIA_SLOPE_BOTH, "%.2f", "network", NULL, "VM Output Errors" )
SFLOW_GMETRIC(SFLOW_M_vdrops_out, "vdrops_out", "drops/sec", GANGLIA_SLOPE_BOTH, "%.2f", "network", NULL, "VM Output Drops" )
SFLOW_GMETRIC(SFLOW_M_dsi, "dsi", "", GANGLIA_SLOPE_ZERO, "%s", "system", NULL, "Datasource ID" )
SFLOW_GMETRIC(SFLOW_M_parent_dsi, "parent_dsi", "", GANGLIA_SLOPE_ZERO, "%s", "system", NULL, "Parent Datasource ID" )
