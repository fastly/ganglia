#ifndef GMETAD_TYPEDEFS_H
#define GMETAD_TYPEDEFS_H 1 

/* This was taken from metric_hash.c which was
   generated by gperf */
#define MAX_HASH_VALUE 97

#include <ganglia/net.h> 

typedef struct
   {
      unsigned int index;
      char *name;
      unsigned int num_sources;
      g_inet_addr **sources;
   }
data_source_list_t;

#ifndef SYS_CALL
#define SYS_CALL(RC,SYSCALL) \
   do {                      \
       RC = SYSCALL;         \
   } while (RC < 0 && errno == EINTR);
#endif

#endif
