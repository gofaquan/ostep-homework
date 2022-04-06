#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int pi1[2];
    int pi2[2];
    char buf1[30], buf2[30];
    int p1 = pipe(pi1);
    int p2 = pipe(pi2);
    long temptime;
    struct timeval start, end;
    int i;
    //初始化失败
    if (p1 < 0 || p2 < 0) {
        fprintf(stderr, "pipe failed");
        exit(1);
    }

    int rc = fork();
    //fork 失败
    if (rc < 0) {
        fprintf(stderr, "fork failed");
        exit(1);
    }
    for (i = 0; i < 10; ++i) {
        //子进程
        if (rc == 0) {
            //进行一次系统调用，然后测时间
            read(pi1[0], buf1, 25);
            gettimeofday(&end, NULL);
            printf("%d\n", end.tv_usec - atol(buf1));
            //读取调用完的时间
            gettimeofday(&start, NULL);
            sprintf(buf2, "%ld", start.tv_usec);
            write(pi2[1], buf2, 25);
        } else {
            //父进程
            gettimeofday(&start, NULL);
            sprintf(buf1, "%ld", start.tv_usec);
            write(pi1[1], buf1, 25);
            read(pi2[0], buf2, 25);
            gettimeofday(&end, NULL);
            printf("%d\n", end.tv_usec - atol(buf2));
        }
    }
    return 0;
}