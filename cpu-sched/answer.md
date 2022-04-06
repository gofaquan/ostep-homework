##### (1．使用 SJF 和 FIFO 调度程序运行长度为 200 的 3 个作业时，计算响应时间和周转时间。)s
```
↳ python scheduler.py -p FIFO  -l 200,200,200 -c                                                   ✔  16:12:18 
ARG policy FIFO
ARG jlist 200,200,200

Here is the job list, with the run time of each job:
    Job 0 ( length = 200.0 )
    Job 1 ( length = 200.0 )
    Job 2 ( length = 200.0 )


** Solutions **

Execution trace:
[ time   0 ] Run job 0 for 200.00 secs ( DONE at 200.00 )
[ time 200 ] Run job 1 for 200.00 secs ( DONE at 400.00 )
[ time 400 ] Run job 2 for 200.00 secs ( DONE at 600.00 )

Final statistics:
Job   0 -- Response: 0.00  Turnaround 200.00  Wait 0.00
Job   1 -- Response: 200.00  Turnaround 400.00  Wait 200.00
Job   2 -- Response: 400.00  Turnaround 600.00  Wait 400.00

Average -- Response: 200.00  Turnaround 400.00  Wait 200.00


↳ python scheduler.py -p SJF  -l 200,200,200 -c                                                    ✔  16:12:31 
ARG policy SJF
ARG jlist 200,200,200

Here is the job list, with the run time of each job:
    Job 0 ( length = 200.0 )
    Job 1 ( length = 200.0 )
    Job 2 ( length = 200.0 )


** Solutions **

Execution trace:
[ time   0 ] Run job 0 for 200.00 secs ( DONE at 200.00 )
[ time 200 ] Run job 1 for 200.00 secs ( DONE at 400.00 )
[ time 400 ] Run job 2 for 200.00 secs ( DONE at 600.00 )

Final statistics:
Job   0 -- Response: 0.00  Turnaround 200.00  Wait 0.00
Job   1 -- Response: 200.00  Turnaround 400.00  Wait 200.00
Job   2 -- Response: 400.00  Turnaround 600.00  Wait 400.00

Average -- Response: 200.00  Turnaround 400.00  Wait 200.00
```



##### (2．现在做同样的事情，但有不同长度的作业，即 100、200 和 300。)
```
↳ python scheduler.py -p FIFO  -l 100,200,300 -c                                                   ✔  16:21:41 
ARG policy FIFO
ARG jlist 100,200,300

Here is the job list, with the run time of each job:
  Job 0 ( length = 100.0 )
  Job 1 ( length = 200.0 )
  Job 2 ( length = 300.0 )


** Solutions **

Execution trace:
  [ time   0 ] Run job 0 for 100.00 secs ( DONE at 100.00 )
  [ time 100 ] Run job 1 for 200.00 secs ( DONE at 300.00 )
  [ time 300 ] Run job 2 for 300.00 secs ( DONE at 600.00 )

Final statistics:
  Job   0 -- Response: 0.00  Turnaround 100.00  Wait 0.00
  Job   1 -- Response: 100.00  Turnaround 300.00  Wait 100.00
  Job   2 -- Response: 300.00  Turnaround 600.00  Wait 300.00

  Average -- Response: 133.33  Turnaround 333.33  Wait 133.33
  
  
↳ python scheduler.py -p SJF  -l 100,200,300 -c                                                    ✔  16:23:28 
ARG policy SJF
ARG jlist 100,200,300

Here is the job list, with the run time of each job:
  Job 0 ( length = 100.0 )
  Job 1 ( length = 200.0 )
  Job 2 ( length = 300.0 )


** Solutions **

Execution trace:
  [ time   0 ] Run job 0 for 100.00 secs ( DONE at 100.00 )
  [ time 100 ] Run job 1 for 200.00 secs ( DONE at 300.00 )
  [ time 300 ] Run job 2 for 300.00 secs ( DONE at 600.00 )

Final statistics:
  Job   0 -- Response: 0.00  Turnaround 100.00  Wait 0.00
  Job   1 -- Response: 100.00  Turnaround 300.00  Wait 100.00
  Job   2 -- Response: 300.00  Turnaround 600.00  Wait 300.00

  Average -- Response: 133.33  Turnaround 333.33  Wait 133.33
```
##### (3．现在做同样的事情，但采用 RR 调度程序，时间片为 1。)
```
↳ python scheduler.py -p RR -q 1 -l 100,200,300 -c
#太长了。。就忽略中间过程了
 Average -- Response: 1.00  Turnaround 465.67  Wait 265.67
```

##### (4．对于什么类型的工作负载，SJF 提供与 FIFO 相同的周转时间？)
* 长度更短的工作负载先到的情况下，SJF和FIFO有相同的周转时间。


##### (5．对于什么类型的工作负载和量子长度，SJF 与 RR 提供相同的响应时间？)
* 量子长度大于最长的工作负载的长度时，RR可以看作是SJF，因此有相同的相应时间。

##### (6．随着工作长度的增加，SJF 的响应时间会怎样？你能使用模拟程序来展示趋势吗？)
* 随着工作长度的增加，响应时间会越来越大。
* python scheduler.py -p SJF  -l 100,100,100 -c
* Average -- Response: 100.00  Turnaround 200.00  Wait 100.00
* python scheduler.py -p SJF  -l 200,200,200 -c
* Average -- Response: 200.00  Turnaround 400.00  Wait 200.00


##### (7．随着量子长度的增加，RR 的响应时间会怎样？你能写出一个方程，计算给定 N 个工作时，最坏情况的响应时间吗？)
* 随着量子长度的增加，响应时间会越来越大。
```
假设n个工作N1,N2,N3…Nn

工作长度为t1,t2…tn且t1>t2>…tn

最坏情况的平均响应时间为

averT=(t1+t1+t2+t1+t2+t3+t1+t2+t3…)/n=((n-1)t1+(n-2)t2+…tn-1)/n
```