/* example of programming with POSIX semaphores 
   Producer-Consumer solution with pthreads and thread-safe queue
   to compile:    gcc -o pc_sem pc_sem.c -pthread */

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define QSIZE 6        /* number of slots in shared queue */
#define MAX_ITEMS 20   /* total number of items produced by each producer */
#define MAX_DELAY 3    /* maximum delay (sec) for producing/consuming an item */

pthread_mutex_t mutex;
sem_t empty, full;


/* Queue implementation */

typedef int item_t;  

struct item_queue {
  int front; /* index of front element in arr */
  int count; /* number of element currently stored in arr */
  item_t arr[QSIZE];  
};  /* allocate queue with capacity QSIZE */

void dumpq(struct item_queue *qp) { /* debug print contents of queue */
  printf("*** dumpq *** front=%d count=%d\n", qp->front, qp->count);
  printf("*** dumpq *** contents:  ");
  int i;
  for (i=0; i<QSIZE; i++) printf("%d  ", qp->arr[i]);
  printf("\n");
  return;
}

int addq(struct item_queue *qp, item_t *ip) {
  sem_wait(&empty);  /* down(empty) */
  pthread_mutex_lock(&mutex);   /* mutex_lock more efficient than semaphore */
  assert(qp->count < QSIZE);    /* abort computation if queue is full */
  printf("  adding %d to queue\n", *ip);  /* output to trace activity */
  qp->arr[(qp->front + qp->count)%QSIZE] = *ip;
  qp->count = qp->count+1;
  //dumpq(qp);  /* debug */
  pthread_mutex_unlock(&mutex); 
  sem_post(&full);   /* up(full) */
  return 0;
}

int removeq(struct item_queue *qp, item_t *ip) {
  sem_wait(&full);  /* down(full) */
  pthread_mutex_lock(&mutex);   /* mutex_lock more efficient than semaphore */
  assert(qp->count > 0);    /* abort computation if queue is empty */
  *ip = qp->arr[qp->front];
  printf("    removing %d from queue\n", *ip);  /* output to trace activity */
  qp->front = (qp->front+1)%QSIZE;
  qp->count--; 
  //dumpq(qp);  /* debug */
  pthread_mutex_unlock(&mutex); 
  sem_post(&empty);   /* up(empty) */
  return 0;
}


/* producer and consumer implementations 
   producer generates primes; consumer prints them */

/* shared data structure per thread */

struct data {               /* data structure per thread */
  int id;                      /* id number (index into main() handles[] ) */
  struct item_queue *qp;       /* shared queue access */
};

/* isPrime - helper function for producer
   1 arg - any integer
   return - 1 if arg1 is a prime, 0 otherwise */
int isPrime(int val) {
  if (val <= 1)
    return 0;
  int i;
  for (i=2; i < val; i++) 
    if (val % i == 0)
      return 0;
  return 1;
}

void *producer(void *datap){   /* produces prime numbers */
  struct item_queue *qp = ((struct data*) datap)->qp;
  int id = ((struct data*) datap)->id;
  item_t added[MAX_ITEMS];    /* holds primes found */
			 
  item_t item = id*1000;      /* item holds a potential prime number */
  int count;  	              /* number of items produced so far */
  for (count = 0; count < MAX_ITEMS; count++) { 
    sleep(rand()%MAX_DELAY);  /* random delay */
    while (!isPrime(item))    /* produce an item */
      item++;
    /* item holds the next highest prime number */
    printf("[%d] item %d produced\n", id, item);
    addq((struct item_queue*) qp, &item);  /* put an item in the queue */
    added[count] = item;   /* record item produced */
    item++;                   /* move beyond this prime */
  }
  printf("[%d] producer ENDS, added these %d items:  ", id, MAX_ITEMS);
  int i;  for (i = 0;  i < MAX_ITEMS;  i++) printf("%d  ", added[i]);
  printf("\n");  
  item = -1;                  /* marks end of production */
  addq((struct item_queue*) qp, &item);  /* put end marker at rear of queue */
  return NULL;
}

void *consumer(void *datap){   /* consumes and reports items */
  struct item_queue *qp = ((struct data*) datap)->qp;
  int id = ((struct data*) datap)->id;
  item_t removed[MAX_ITEMS];   /* holds items received */

  item_t item;                 /* for receiving an item from queue */
  int ct = 0;                  /* count of items consumed */
  while (1) {                  /* infinite loop */
    removeq((struct item_queue*) qp, &item); /* take item from queue */
    if (item == -1) {
      /* end marker encountered */
      printf("      [%d] consumer ENDS, removed these %d items:  ", id, ct);
      int i;  for (i=0; i<ct; i++) printf("%d  ", removed[i]);
      printf("\n"); 
      return NULL;
    }
    sleep(rand()%MAX_DELAY);   /* random delay */
    printf("      [%d] item %d consumed\n", id, item);
    removed[ct++] = item;     /* record item removed */
  }
}


/* main program */

#define NTHREADS 2

int main(int argc, char **argv, char**envp) {
  pthread_mutex_init(&mutex, NULL); 
  sem_init(&empty, 0, QSIZE);   /* share among threads, sem integer = QSIZE */
  sem_init(&full, 0, 0);        /* share among threads, sem integer = 0 */
  struct item_queue Q = {0, 0}; /* shared queue */
  srand(time(NULL));            /* seed random number generator */

  pthread_t handles[NTHREADS];  /* access to producer and consumer threads */
  struct data data[NTHREADS];   /* data struct for each thread */
  int i;                        /* loop control */
  for (i=0; i<NTHREADS; i++) {  /* initialize thread data */
    data[i].id = i;
    data[i].qp = &Q;
  };

  pthread_create(&handles[0], NULL, producer, &data[0]);
  pthread_create(&handles[1], NULL, consumer, &data[1]);

  for (i = 0;  i < NTHREADS;  i++)  /* wait for all threads to finish */
    pthread_join(handles[i], NULL); 

  pthread_mutex_destroy(&mutex);
  sem_destroy(&empty);
  sem_destroy(&full);
  return 0;
  
}
