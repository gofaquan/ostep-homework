#作答前请先仔细阅读 本目录下的 原版英文 README.md

1．用以下标志运行程序：./process-run.py -l 5:100,5:100。CPU 利用率（CPU 使用时间
的百分比）应该是多少？为什么你知道这一点？利用 -c 标记查看你的答案是否正确。
```python
python process-run.py -l 5:100,5:100

python process-run.py -l 5:100,5:100 -c
```
百分之一百，因为是 5:100 , 所以 cpu 占 100%，5:0 将会是 0



2．现在用这些标志运行：./process-run.py -l 4:100,1:0。这些标志指定了一个包含 4 条指
令的进程（都要使用 CPU），并且只是简单地发出 I/O 并等待它完成。完成这两个进程需要
多长时间？利用-c 检查你的答案是否正确。
```python
python process-run.py -l 4:100,1:0

 	#11 个 ticks，结合答案理解，因为 4+1+5+1 = 11 ，4:100 => 4 , 1:0 => 1 * 5,默认*5，-L 可修改, 如  python process-run.py -l 4:100,1:0 -L 1 -c
python process-run.py -l 4:100,1:0 -c
```

3．现在交换进程的顺序：./process-run.py -l 1:0,4:100。现在发生了什么？交换顺序是否
重要？为什么？同样，用-c 看看你的答案是否正确。
```python

python process-run.py -l 1:0,4:100

 	#交换顺序后，在PID0进行io操作的时候，PID1会切换成RUNNING的状态，提高了CPU的利用效率，所以交换顺序重要。具体自行 执行程序 ，清晰可理解
python process-run.py -l 1:0,4:100 -c
```


4．现在探索另一些标志。一个重要的标志是-S，它决定了当进程发出 I/O 时系统如何
反应。将标志设置为 SWITCH_ON_END，在进程进行 I/O 操作时，系统将不会切换到另一
个进程，而是等待进程完成。当你运行以下两个进程时，会发生什么情况？一个执行 I/O，
另一个执行 CPU 工作。（-l 1:0,4:100 -c -S SWITCH_ON_END）
```python
python process-run.py -l 1:0,4:100 -S SWITCH_ON_END


#由于加上了SWITCH_ON_END的标签，此时PID0进行IO操作的时候CPU会空闲等待至IO操作完成，浪费了一定的时间
python process-run.py -l 1:0,4:100 -S SWITCH_ON_END -c
```


5．现在，运行相同的进程，但切换行为设置，在等待 I/O 时切换到另一个进程（-l 1:0,4:100
-c -S SWITCH_ON_IO）。现在会发生什么？利用-c 来确认你的答案是否正确。
```python

python process-run.py -l 1:0,4:100 -S SWITCH_ON_IO

#由于这次会在等待IO的时候进行进程的切换，所以在io操作时，CPU没有等待，而是切换到了另外一个进程上继续工作，提高了利用率
python process-run.py -l 1:0,4:100 -S SWITCH_ON_IO -c
```


6．另一个重要的行为是 I/O 完成时要做什么。利用-I IO_RUN_LATER，当 I/O 完成时，
发出它的进程不一定马上运行。相反，当时运行的进程一直运行。当你运行这个进程组合
时会发生什么？（./process-run.py -l 3:0,5:100,5:100,5:100 -S SWITCH_ON_IO -I IO_RUN_
LATER -c -p）系统资源是否被有效利用？
```python
python process-run.py -l 3:0,5:100,5:100,5:100 -S SWITCH_ON_IO -I IO_RUN_LATER -c -p
#由于IO操作的优先级不是最高的，即使io操作的WAITING结束了，也会等待CPU先将其他进程执行之后，再对IO进行切换，由于IO操作需要消耗比较多的额外时间，而这部分时间没有被CPU利用，所以系统资源没有得到有效利用
#ps: 这里的有效利用应该是在 3 个 IO 期间来 分别运行 1个 cpu操作，事实上是只有第一个，后面两个IO 时间段 空闲的cpu 没有得到有效利用

```
7．现在运行相同的进程，但使用-I IO_RUN_IMMEDIATE 设置，该设置立即运行发出
I/O 的进程。这种行为有何不同？为什么运行一个刚刚完成 I/O 的进程会是一个好主意？
```python
python process-run.py -l 3:0,5:100,5:100,5:100 -S SWITCH_ON_IO -I IO_RUN_IMMEDIATE -c -p
#在使用了IMMEDIATE标签后，每次io_done之后CPU都会先切换io操作，然后用io处理的时间来处理其他进程，提高了系统资源的利用率
#是上题中 ps 中的情况
```

8．现在运行一些随机生成的进程，例如-s 1 -l 3:50,3:50, -s 2 -l 3:50,3:50, -s 3 -l 3:50,3:50。
看看你是否能预测追踪记录会如何变化？当你使用-I IO_RUN_IMMEDIATE 与-I IO_RUN_
LATER 时会发生什么？当你使用-S SWITCH_ON_IO 与-S SWITCH_ON_END 时会发生什么？