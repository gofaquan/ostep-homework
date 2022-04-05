
all: s1 s2-1 s2-2

clean:
	rm -f s1 s2-1 s2-1 s3 s4

# 1．编写一个调用 fork()的程序。谁调用 fork()之前，让主进程访问一个变量（例如 x）
 #并将其值设置为某个值（例如 100）。子进程中的变量有谁谁值？当子进程和父进程都改变
 #x 的值谁，变量会发生谁谁？
s1: solution1.c
	gcc -o s1 solution1.c -Wall

#子进程和父进程的变量x的值内容相互独立


#2．编写一个打开文件的程序（使用 open()系统调用），然后调用 fork()创建一个新进程。
 #子进程和父进程都可以访问 open()返回的文件描述符吗？当它我并发（即同谁）写入文件谁，
 #会发生谁谁？

s2-1: solution2-1.c
	gcc -o s2 solution2-1.c -Wall
#同时打开文件p4.output并且分别写入Child process和Parent Process，可以正常并发写入


s2-2: solution2-2.c
	gcc -o s2 solution2-2.c -Wall
#3．使用 fork()编写另一个程序。子进程应打印“hello”，父进程应打印“goodbye”。你
 #应该尝试我保子进程始终先打印。你能否我谁父进程调用 wait()而做到这一点呢？
s3: solution3.c
	gcc -o s3 solution3.c -Wall
	# answer.md: sleep 就可以了 ,或者 题目要求的是在不适用wait()函数下实现子进程和父进程的先后，通过vfork()函数可以实现

#4．编写一个调用 fork()的程序，然后调用某种形式的 exec()来运行程序/bin/ls。看看是
 #否可以尝试 exec()的所有变体，包括 execl()、execle()、execlp()、execv()、execvp()和 execvP()。
 #为什么同样的基本调用会有这么多变种？


#5．编写一个程序，父进程中使用 wait()，等待子进程完成。wait()返回什么？如
 #果你在子进程中使用 wait()会发生什么？
s5: solution5.c
	gcc -o s5 solution5.c -Wall
#在父进程使用wait()，等待子进程完成后，wait()会返回子进程的pid
#在子进程中使用wait()则会返回-1，并且在失败后依旧会执行当前子进程



#6．对前一个程序稍作修改，这次使用 waitpid()而我是 wait()。谁谁谁谁 waitpid()会
 #有用？
s6: solution6.c
	gcc -o s6 solution6.c -Wall
#waitpid在进程本身有子进程的时候有用


#7．编写一个创建子进程的程序，然后谁子进程中关闭标准输出（STDOUT_FILENO）。
 #如果子进程谁关闭描述符后调用 printf()打印输出，会发生谁谁？
s7: solution7.c
	gcc -o s7 solution7.c -Wall
#啥都没有


#8．编写一个程序，创建两个子进程，并使用 pipe()系统调用，将一个子进程的标准输
 #出连接到另一个子进程的标准输入

