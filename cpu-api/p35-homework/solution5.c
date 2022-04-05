# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
#include <sys/wait.h>

int main() {
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        int fake_ws = wait(NULL);
        printf("I am child process %d\n", getpid());
        printf("fake_ws = %d\n", fake_ws);
        printf("Test\n");
    } else {
        int ws = wait(NULL);
        printf("I am parent process %d\n", getpid());
        printf("Return Value of wait() is %d\n", ws);
    }
    return 0;
}