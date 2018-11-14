//mutex thread synchronization
#include <iostream>
#include <cstdlib>
#include <pthread.h>

using namespace std;

pthread_mutex_t mutex_wait;

void *print_block(void *threadid) {
	// critical section (exclusive access to std::cout signaled by locking mtx):
    //pthread_mutex_lock(&mutex_wait);
    long tid;
    tid = (long)threadid;
    cout << "Thread ID: " << tid + 1 << endl;

	int size = 10;

	int  * arr = new int[10];


	cout << "\n" << "Generated Array: " << "[";
	for (int i = 0; i < 10; ++i) {
		arr[i] = rand() % 100;
		cout << arr[i] << ", ";
	}
	cout << "]\n";

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

	cout << "\n" << "Shell Sorted: " << "[";
	for (int i = 0; i < size; ++i) {
		cout << arr[i] << ", ";
	}

	cout << "]\n";
	//pthread_mutex_unlock(&mutex_wait);
	pthread_exit(NULL);
}

int main () {
   int INPUT;

   cout << "number of threads? ";
   cin >> INPUT;

   //pthread_t threads[NUM_THREADS];
   pthread_t threads[INPUT];

   int th1, th2, th3, th4;

   switch(INPUT){
        case 1: cout << "main() : creating thread 1" << endl;
                th1 = pthread_create(&threads[0], NULL, print_block, (void *)0);
                if (th1) {
                    cout << "Error:unable to create thread," << th1 << endl;
                exit(-1);}
                break;
        case 2: cout << "main() : creating thread 1" << endl;
                pthread_mutex_lock(&mutex_wait);
                th1 = pthread_create(&threads[0], NULL, print_block, (void *)0);
                if (th1) {
                    cout << "Error:unable to create thread," << th1 << endl;
                exit(-1);}
                pthread_mutex_unlock(&mutex_wait);
                cout << "main() : creating thread 2" << endl;
                pthread_mutex_lock(&mutex_wait);
                th2 = pthread_create(&threads[1], NULL, print_block, (void *)1);
                if (th2) {
                    cout << "Error:unable to create thread," << th2 << endl;
                exit(-1);}
                pthread_mutex_unlock(&mutex_wait);
                break;
        case 4: cout << "main() : creating thread 1" << endl;
                pthread_mutex_lock(&mutex_wait);
                th1 = pthread_create(&threads[0], NULL, print_block, (void *)0);
                if (th1) {
                    cout << "Error:unable to create thread," << th1 << endl;
                exit(-1);}
                pthread_mutex_unlock(&mutex_wait);
                cout << "main() : creating thread 2" << endl;
                pthread_mutex_lock(&mutex_wait);
                th2 = pthread_create(&threads[1], NULL, print_block, (void *)1);
                if (th2) {
                    cout << "Error:unable to create thread," << th2 << endl;
                exit(-1);}
                pthread_mutex_unlock(&mutex_wait);
                cout << "main() : creating thread 3" << endl;
                pthread_mutex_lock(&mutex_wait);
                th3 = pthread_create(&threads[2], NULL, print_block, (void *)2);
                if (th3) {
                    cout << "Error:unable to create thread," << th3 << endl;
                exit(-1);}
                pthread_mutex_unlock(&mutex_wait);
                cout << "main() : creating thread 4" << endl;
                pthread_mutex_lock(&mutex_wait);
                th4 = pthread_create(&threads[3], NULL, print_block, (void *)3);
                if (th4) {
                    cout << "Error:unable to create thread," << th4 << endl;
                exit(-1);}
                pthread_mutex_unlock(&mutex_wait);
                break;
        default: cout << "Def.";
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
