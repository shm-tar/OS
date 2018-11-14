#include <stdio.h>
#include <pthread.h>


#define NUM_THREADS 4
pthread_mutex_t mutex_wait;

void *print_block(void *threadid) {
 // critical section (exclusive access to std::cout signaled by locking mtx):
    //pthread_mutex_lock(&mutex_wait);
    long tid;
    tid = (long)threadid;
    //cout << "Thread ID: " << tid + 1 << endl;
    printf("thread ID: %d\n", tid+1);

 int size = 10;

 int  * arr[10] = { 0 };


 //cout << "\n" << "Generated Array: " << "[";
 printf("Generated Array: [");
 for (int i = 0; i < 10; ++i) {
  arr[i] = rand() % 100;
  //cout << arr[i] << ", ";
  printf("%d, ", arr[i]);
 }
 //cout << "]\n";
 printf("]\n");

 for (int gap = size / 2; gap > 0; gap /= 2)
 {
  for (int i = gap; i < size; i += 1)
  {
   int temp = arr[i];

   int j;
   for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
    arr[j] = arr[j - gap];

   arr[j] = temp;
  }
 }

 //cout << "\n" << "Shell Sorted: " << "[";
 printf("Shell Sorted: [");
 for (int i = 0; i < size; ++i) {
  //cout << arr[i] << ", ";
  printf("%d, ", arr[i]);
 }

 //cout << "]\n";
 printf("]\n");
 //pthread_mutex_unlock(&mutex_wait);
 pthread_exit(NULL);
}

void start() {
   int INPUT;

   //cout << "number of threads? ";
   printf("number of threads? ");
   scanf("%d", &INPUT);

   //pthread_t threads[NUM_THREADS];
   pthread_t threads[INPUT];

   int th1, th2, th3, th4;

   switch(INPUT){
        case 1: //cout << "main() : creating thread 1" << endl;
                printf("main() : creating thread 1\n");
                th1 = pthread_create(&threads[0], NULL, print_block, (void *)0);
                if (th1) {
                    //cout << "Error:unable to create thread," << th1 << endl;
                    printf("Error:unable to create thread %d\n", th1);
                exit(-1);}
                break;
        case 2: //cout << "main() : creating thread 1" << endl;
                printf("main() : creating thread 1\n");
                pthread_mutex_lock(&mutex_wait);
                th1 = pthread_create(&threads[0], NULL, print_block, (void *)0);
                if (th1) {
                    //cout << "Error:unable to create thread," << th1 << endl;
                    printf("Error:unable to create thread %d\n", th1);
                exit(-1);}
                pthread_mutex_unlock(&mutex_wait);
                //cout << "main() : creating thread 2" << endl;
                printf("main() : creating thread 2\n");
                pthread_mutex_lock(&mutex_wait);
                th2 = pthread_create(&threads[1], NULL, print_block, (void *)1);
                if (th2) {
                    //cout << "Error:unable to create thread," << th2 << endl;
                    printf("Error:unable to create thread %d\n", th2);
                exit(-1);}
                pthread_mutex_unlock(&mutex_wait);
                break;
        case 4: //cout << "main() : creating thread 1" << endl;
                printf("main() : creating thread 1\n");
                pthread_mutex_lock(&mutex_wait);
                th1 = pthread_create(&threads[0], NULL, print_block, (void *)0);
                if (th1) {
                    //cout << "Error:unable to create thread," << th1 << endl;
                    printf("Error:unable to create thread %d\n", th1);
                exit(-1);}
                pthread_mutex_unlock(&mutex_wait);
                //cout << "main() : creating thread 2" << endl;
                printf("main() : creating thread 2\n");
                pthread_mutex_lock(&mutex_wait);
                th2 = pthread_create(&threads[1], NULL, print_block, (void *)1);
                if (th2) {
                    //cout << "Error:unable to create thread," << th2 << endl;
                    printf("Error:unable to create thread %d\n", th2);
                exit(-1);}
                pthread_mutex_unlock(&mutex_wait);
                //cout << "main() : creating thread 3" << endl;
                printf("main() : creating thread 3\n");
                pthread_mutex_lock(&mutex_wait);
                th3 =
pthread_create(&threads[2], NULL, print_block, (void *)2);
                if (th3) {
                    //cout << "Error:unable to create thread," << th3 << endl;
                    printf("Error:unable to create thread %d\n", th3);
                exit(-1);}
                pthread_mutex_unlock(&mutex_wait);
                //cout << "main() : creating thread 4" << endl;
                printf("main() : creating thread 4\n");
                pthread_mutex_lock(&mutex_wait);
                th4 = pthread_create(&threads[3], NULL, print_block, (void *)3);
                if (th4) {
                    //cout << "Error:unable to create thread," << th4 << endl;
                    printf("Error:unable to create thread %d\n", th2);
                exit(-1);}
                pthread_mutex_unlock(&mutex_wait);
                break;
        default: //cout << "Def.";
                printf("Def.");
   }
   /*
   for(int i = 0; i < NUM_THREADS; i++ ) {
      cout << "main() : creating thread, " << i + 1<< endl;
      rc = pthread_create(&threads[i], NULL, print_block, (void *)i);

      if (rc) {
         cout << "Error:unable to create thread," << rc << endl;
         exit(-1);
      }
   }*/
   pthread_exit(NULL);
}
