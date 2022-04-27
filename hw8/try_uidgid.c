#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int realuserid, realgroupid, effectiveuserid, effectivegroupid;
    if((realuserid = getuid()) < 0) {
        perror("getuid()");
        return -1;
    }
    printf("real user ID: %d\n", realuserid);

    if((realgroupid = getgid()) < 0) {
        perror("getgid()");
        return -1;
    }
    printf("real group ID: %d\n", realgroupid);

    if((effectiveuserid = geteuid()) < 0) {
        perror("geteuid()");
        return -1;
    }
    printf("effective real user ID: %d\n", effectiveuserid);

    if((effectivegroupid = getegid()) < 0) {
        perror("getegid()");
        return -1;
    }
    printf("effective real group ID: %d\n", effectivegroupid);

    uid_t uid = 1;
    gid_t gid = 2;
    uid_t euid = 3;
    gid_t egid = 4;
    int ret1, ret2, ret3, ret4;

    if((ret1 = setuid(uid)) < 0) {
        perror("setuid()");
        return -1;
    }
    //printf("real user ID: %d\n", realuserid = getuid());

    if((ret2 = setgid(gid)) < 0) {
        perror("setgid()");
        return -1;
    }
    //printf("real group ID: %d\n", realgroupid = getgid());

    if((ret3 = seteuid(euid)) < 0) {
        perror("seteuid()");
        return -1;
    }
    //printf("effective real user ID: %d\n", effectiveuserid = geteuid());

    if((ret4 = setuid(egid)) < 0) {
        perror("setegid()");
        return -1;
    }
    //printf("effective real group ID: %d\n", effectivegroupid = getuid());

}