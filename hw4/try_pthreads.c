#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h> 
#include <pthread.h> 

#define NUM_RECT 10000000 
#define NUMTHREADS 1

void *printthread(void* x) {
    for (int i = 0; i < * (int*)x; i++) {
        printf("%d\t", i);
    }
    printf("\n");
}

int main(int argc, char **argv) {
    int ret, ret2;

    printf("I am the MAIN THREAD. My pid is %d\n", getpid());

    pthread_t id; 
    int argument = 5;

    
    if ((ret = pthread_create(&id, NULL, printthread, &argument) < 0)) {
        perror("pthread creation failed");
        return -1;
    }

    printf("I am the PTHREAD. My pid is %d\n", getpid());

    printf("I am the MAIN THREAD, and I successfully launched a pthread\n");

    if ((ret = pthread_join(id, NULL) < 0)) {
        perror("pthread join failed");
        return -1;
    }

    printf("I am the MAIN THREAD, and the pthread has finished\n");

}