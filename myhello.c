
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS	8

void *PrintHello(void *threadid)
{
   long tid;
   tid = (long)threadid;
   printf("Hello SCR! Written by thread #%ld!\n", tid);
   pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
   pthread_t threads[NUM_THREADS];
   int rc;
   long t;
   for(t=0;t<NUM_THREADS;t++){
     printf("Created thread %ld\n", t);
     rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
     }

   pthread_exit(NULL);
}
