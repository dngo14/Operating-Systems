#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h> 
#include <pthread.h> 

#define NUM_RECT 10000000 
#define NUMTHREADS 1
pthread_mutex_t gLock;

int val = 10;

void *printthread(void* x) {
    
    for (int i = 0; i < * (int*)x; i++) {
        printf("%d\t", i);
    }
    printf("\n");

    pthread_mutex_lock(&gLock);
    val += 1;  
    //pthread_mutex_unlock(&gLock);
}

int main(int argc, char **argv) {
    int ret, ret2;

    printf("I am the MAIN THREAD. My pid is %d\n", getpid());

    pthread_t id; 
    int argument = 5;

    printf("Global Val = %d \n", val);

    pthread_mutex_init(&gLock, NULL);
    if ((ret = pthread_create(&id, NULL, printthread, &argument) < 0)) {
        perror("pthread creation failed");
        return -1;
    }

    //pthread_mutex_lock(&gLock);
    pthread_mutex_unlock(&gLock);

    printf("I am the PTHREAD. My pid is %d\n", getpid());

    printf("I am the MAIN THREAD, and I successfully launched a pthread\n");

    if ((ret = pthread_join(id, NULL) < 0)) {
        perror("pthread join failed");
        return -1;
    }

    //pthread_mutex_unlock(&gLock);

    pthread_mutex_destroy(&gLock); 

    printf("I am the MAIN THREAD, and the pthread has finished\n");

    printf("Global Val = %d \n", val);

    return 0;
}