 #include <semaphore.h>
 #include <stdio.h>
 #include <pthread.h>
 
 using namespace std;
 
 const int loops=10;
 
 const int MAX=2;
 int buffer[MAX];
 int fill = 0;
 int use = 0;

 void put(int value) {
     buffer[fill] = value; // Line F1
     fill = (fill + 1) % MAX; // Line F2
     printf("Put %d\n",value);
 }

 int get() {
     int tmp = buffer[use]; // Line G1
     use = (use + 1) % MAX; // Line G2
     printf("Get %d\n",tmp);
     return tmp;
 }
 
 sem_t empty;
 sem_t full;

 void *producer(void *arg) {
     int i;
     for (i = 0; i < loops; i++) {
     sem_wait(&empty); // Line P1
     put(i); // Line P2
     sem_post(&full); // Line P3
     }
     return arg;
 }

 void *consumer(void *arg) {
     int tmp = 0;
     while (tmp != -1) {
     sem_wait(&full); // Line C1
     tmp = get(); // Line C2
     sem_post(&empty); // Line C3
     printf("%d\n", tmp);
     }
     return arg;
 }

 int main(int argc, char *argv[]) {
     pthread_t p,c;
     sem_init(&empty, 0, MAX); // MAX buffers are empty to begin with...
     sem_init(&full, 0, 0); // ... and 0 are full
     pthread_create(&p,NULL,producer,NULL);
     pthread_create(&c,NULL,consumer,NULL);
     pthread_join(p,NULL);
     pthread_join(c,NULL);
     return 0;
 }

/* Question 4: 10 Points
  Which of the two outputs below is valid output of this program.
  Explain your answer.  A simple yes or no will only receive 1 
  point if it is correct.
 
 Output B because put or get is limited to two at a time. put() and get() also have different variables. put() depends on 'fill' and get() depends on 'use' therefore "Get 6" would come before "Get 7".

Output A:

Put 0
Put 1
Get 0
0
Get 1
1
Put 2
Put 3
Get 2
2
Get 3
3
Put 4
Put 5
Get 4
4
Get 5
5
Get 6
6
Put 6
Put 7
Get 7
7
Put 8
Put 9
Get 8
8
Get 9
9

Output B:

Put 0
Put 1
Get 0
0
Get 1
1
Put 2
Put 3
Get 2
2
Get 3
3
Put 4
Put 5
Get 4
4
Get 5
5
Put 6
Put 7
Get 6
6
Get 7
7
Put 8
Put 9
Get 8
8
Get 9
9
*/
