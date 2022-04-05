#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include <sys/wait.h>

//测试能否分别写入
int main() {
    int fd = open("test.txt", O_CREAT | O_RDWR, S_IRWXU);
    int pid = fork();
    if (pid < 0) {
        printf("error!\n");
        exit(1);
    } else if (pid == 0) {
        //如果字符串足够长，那么两个进程写入可能会互相插入，如一个写 `aa` ，一个 `bb`，则可能有 `abab`
        //pwrite 可以解决上述问题
        char *str = "child process\n";
        write(fd, str, sizeof(char) * strlen(str));
        printf("child write success\n");
    } else {
        char *str = "parent process\n";
        write(fd, str, sizeof(char) * strlen(str));
        printf("parent write success\n");
    }
    return 0;
}

