#include <iostream>
#include <cstdlib>
#include <pthread.h>
using namespace std;
#define NUM_THREADS 5
void *PrintHello(void *threadid)
{
   long tid;
   tid = (long)threadid;
   printf("Hello World! Thread ID, %d\n", tid);
   pthread_exit(NULL);
}
int main()
{
   pthread_t threads[NUM_THREADS];
   int rc;
   int i;
   for (i = 0; i < NUM_THREADS; i++)
   {
      cout << "main() : creating thread, " << i << endl;
      rc = pthread_create(&threads[i], NULL, PrintHello,
                          (void *)i);
      if (rc)
      {
         printf("Error:unable to create thread, %d\n",
                rc);
         exit(-1);
      }
   }
   pthread_exit(NULL);
}

// program 5 threads

main() : creating thread, 0 main() : creating thread, 1 main() : creating thread, 2 main() : creating thread, 3 main() : creating thread, 4 Hello World !Thread ID, 0 Hello World !Thread ID, 1 Hello World !Thread ID, 2 Hello World !Thread ID, 3 Hello World !Thread ID, 4