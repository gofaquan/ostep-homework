#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include <sys/wait.h>

//测试能否分别读取
int main() {
    int fd = open("test.txt", O_CREAT | O_RDWR, S_IRWXU);
    int pid = fork();
    if (pid < 0) {
        printf("error!\n");
        exit(1);
    } else if (pid == 0) {
        char str[1024];
        pread(fd, str, 3, 0); //两者都能读取
//      read(fd, str, 3); //谁先读取谁就显示，后者为空
        printf("child: %s\n", str);
    } else {
        wait(NULL);
        char str[1024];
        pread(fd, str, 3, 0); //两者都能读取
//      pread(fd, str, 3);//谁先读取谁就显示，后者为空
        printf("parent: %s\n", str);   //读取为空，感觉不能分别读取
    }
    return 0;
}