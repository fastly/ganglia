/*
 * "Copyright (c) 1999 by Matt Massie and The Regents of the University 
 * of California.  All rights reserved."
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation for any purpose, without fee, and without written agreement is
 * hereby granted, provided that the above copyright notice and the following
 * two paragraphs appear in all copies of this software.
 * 
 * IN NO EVENT SHALL THE UNIVERSITY OF CALIFORNIA BE LIABLE TO ANY PARTY FOR
 * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES ARISING OUT
 * OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF THE UNIVERSITY OF
 * CALIFORNIA HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 * THE UNIVERSITY OF CALIFORNIA SPECIFICALLY DISCLAIMS ANY WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS
 * ON AN "AS IS" BASIS, AND THE UNIVERSITY OF CALIFORNIA HAS NO OBLIGATION TO
 * PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.
 */
#ifndef BARRIER_H
#define BARRIER_H 1

#include <pthread.h>

typedef struct _barrier {
    int             nthrs;      /* # of threads to wait on barrier      */
    int             waiting;    /* # threads waiting in barrier         */
    volatile int    phase;      /* Phase to deal with fast threads      */
    pthread_mutex_t lock;       /* Lock to protect barrier state        */
    pthread_cond_t  wait_cv;    /* CV to wait on until barrier finishes */
} barrier;

int barrier_init(barrier **b, int nthrs);
void barrier_destroy(barrier *b);
void barrier_barrier(barrier *b);

#endif /* __BARRIER_H */
