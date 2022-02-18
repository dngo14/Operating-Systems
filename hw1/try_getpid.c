#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int processid;
    if ((processid = getpid()) < 0) {
        perror("getpid");
        return -1;
    }
    printf("getpid() returned %d \n", processid);

}