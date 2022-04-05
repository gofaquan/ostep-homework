#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int
main(int argc, char *argv[]) {
    int x = 100;
    printf("init x = %d\n\n", x);

    int rc = fork();


    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("child fork come in, x = %d\n", x);
        // child (new process) ,  rc = 0 为子进程
        printf("hello, I am child (pid:%d)\n", (int) getpid());

        x = 0;
        printf("child x = %d\n\n", x);

    } else {
        wait(NULL);
        printf("parent fork come in , x = %d\n", x);
        // parent goes down this path (original process) ,而且 rc = 子进程 pid 29147
        printf("hello, I am parent of %d (pid:%d)\n",
               rc, (int) getpid());
        x = 1;
        printf("parent x = %d\n\n", x);
    }


    return 0;
}
