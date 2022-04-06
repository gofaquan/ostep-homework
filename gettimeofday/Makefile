all: s1 s2 s3

clean:
	rm -f s1 s2 s3

#测量gettimeofdays()连续调用
s1: solution1.c
	gcc -o s1 solution1.c -Wall

#测量系统调用的成本
s2: solution2.c
	gcc -o s2 solution2.c -Wall
#看来是系统的调用的耗时太少了。这么垃圾的电脑都平均不到一微秒。


#测量上下文切换的成本
s3: solution3.c
	gcc -o s3 solution3.c -Wall

#代码中除了上下文切换，还有系统调用，还有字符串转换数字等成本 ，还有一些系统进程切换的成本，我的电脑时间大概在25微秒。