/* $Id$ */
#include "ganglia_private.h"

const char *
my_inet_ntop( int af, void *src, char *dst, size_t cnt )
{
#ifdef HAVE_INET_NTOP
   return inet_ntop(af, src, dst, cnt);
#else
   /* This is not that pretty.. assuming src = sockaddr_in 
      and not really thread-safe on some OS .. blah */
   return strncpy( dst, inet_ntoa( *(struct in_addr *)src ), cnt );
#endif
}
