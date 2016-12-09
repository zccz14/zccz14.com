---
title: OS Homework 2
date: 2016-10-13 14:02:09
---

# Operating System Homework #2

## Process

1\. Describe the differences among short-term, medium-term, and long-term scheduling.

The main difference is the "distance" from the CPU to the process, which indicates the names of short-term, medium-term and long-term scheduling.

Speed:

Short-term > Medium-term > Long-term

the less distance from the CPU to the process, the faster it is.

Frequency:

Short-term > Medium-term > Long-term

the faster, the more frequent.

Place:

Short-term scheduling focus on inside CPU and main memory only (internal devices).

Long-term scheduling focus on outside CPU and main memory (external devices).

Medium-term scheduling works between internal devices and external devices.

Others:

Short-term scheduling only decides which process in the main memory will be processed by CPU.

Long-term scheduling only decides which process in the external devices can enter main memory to be processed.

Medium-term scheduling considers about if it is necessary to suspend a process to external memory to relief main memory.

2\. Describe the actions taken by a kernel to context-switch between processes. 

Saving and loading context.

1. Saving process segments: text segment, data segment, stack segment and sharing memory.
2. Saving register data: PC, PSW, SP, PCBP, ISP, etc.
3. Saving virtual memory management data and interrupt stack data.

and loading another process's corresponding data from somewhere.

# Thread

1\. Discuss the difference between user-level thread and kernel-level thread.

Implementation:

Kernel-level thread is supported by kernel.

User-level thread is supported by thread programming library.

Visibility:

Kernel knows kernel-level threads, but can notice user-level threads.

Kernel takes user-level threads just as a process. 

So user-level thread blocking makes the whole process blocking, but kernel-level thread not.

And user-level multi-thread can't gain more CPU time slice from kernel, but kernel-level thread can.

Privilege:

Operaing(creating, switching and destroying) kernel-level threads needs kernel privileges but it's free about user-level threads.

Maintainer:

Kernel-level thread's context is maintained by kernal.

User-level thread's context is maintained by user process.


2\. Which of the following components of program state are shared across threads in a multithreaded process?

a\. Register values

b\. Heap memory

c\. Global variables

d\. Stack memory

b and c

Heap memory belongs to the whole process runtime.

Global variables belong to data segment.

Each threads has its own register set and stack.

3\.	The program shown in Figure 4.11 uses the Pthreads API. What would be output from the program at LINE C and LINE P?

{% include_code "Thread-1.c" Operating-System-Reference/Thread-1.c lang:c %}

Outputs:

```
CHILD: value=5
PARENT: value=0
```

## Scheduling

1\. Why is it important for the scheduler to distinguish I/O-bound programs from CPU-bound programs?

I/O-bound programs have more I/O bursts and less CPU bursts than CPU-bound programs.

Scheduling Criteria:

+ Max CPU utilization
+ Max throughput and concurrency
+ Min turnaround time
+ Min waiting time
+ Min response time

Scheduling dynamic process can improve and optimize these rules.

2\. Consider the following set of processes, with the length of the CPU burst given in milliseconds

|Process|Burst Time|Priority|
|-|-|-|
|P1|10|3|
|P2|1|1|
|P3|2|3|
|P4|1|4|
|P5|5|2|

The processes are assumed to have arrived in the order P1, P2, P3, P4, P5, all at time 0.

a\. Draw four Gantt charts that illustrate the execution of these processes using the following scheduling algorithms: FCFS, SJF, nonpreemptive priority (a smaller priority number implies a higher priority), and RR (quantum = 1).

FCFS:

```
| P1 | P2 | P3 | P4 | P5 |
0   10   11   13   14   19
```

SJF (nonpreemptive):

```
| P1 | P2 | P4 | P3 | P5 |
0   10   11   12   14   19
```

SJF (preemptive):

```
| P2 | P4 | P3 | P5 | P1 |
0    1    2    4    9   19
```

nonpreemptive priority:

```
| P1 | P2 | P5 | P3 | P4 |
0   10   11   16   18   19
```

RR (quantum = 1):

```
|P1|P2|P3|P4|P5|P1|P3|P5|P1|P5|P1|P5|P1|P5|P1|
0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 19
```

b\. What is the turnaround time of each process for each of the scheduling algorithms in part a?

FCFS:

|Process|Turnaround Time|
|-|-|
|P1|10|
|P2|11|
|P3|13|
|P4|14|
|P5|19|

SJF (nonpreemptive):

|Process|Turnaround Time|
|-|-|
|P1|10|
|P2|11|
|P3|14|
|P4|12|
|P5|19|

SJF (preemptive):

|Process|Turnaround Time|
|-|-|
|P1|19|
|P2|1|
|P3|4|
|P4|2|
|P5|9|

nonpreemptive priority:

|Process|Turnaround Time|
|-|-|
|P1|10|
|P2|11|
|P3|18|
|P4|19|
|P5|16|

RR:

|Process|Turnaround Time|
|-|-|
|P1|19|
|P2|2|
|P3|7|
|P4|4|
|P5|14|

c\. What is the waiting time of each process for each of the scheduling algorithms in part a?

FCFS:

|Process|Waiting Time|
|-|-|
|P1|0|
|P2|10|
|P3|11|
|P4|13|
|P5|14|

SJF (nonpreemptive):

|Process|Waiting Time|
|-|-|
|P1|0|
|P2|10|
|P3|12|
|P4|11|
|P5|14|

SJF (preemptive):

|Process|Waiting Time|
|-|-|
|P1|9|
|P2|0|
|P3|2|
|P4|1|
|P5|4|

nonpreemptive priority:

|Process|Waiting Time|
|-|-|
|P1|0|
|P2|10|
|P3|16|
|P4|18|
|P5|11|

RR:

|Process|Waiting Time|
|-|-|
|P1|9|
|P2|1|
|P3|5|
|P4|3|
|P5|9|

d\. Which of the algorithms in part a results in the minimum average waiting time (over all processes)?

|Algorithm|Average Waiting Time|
|-|-|
|FCFS|9.6|
|SJF(nonpreemptive)|9.4|
|SJF(preemptive)|3.2|
|nonpreemptive priority|11|
|RR|5.4|

3\. Which of the following scheduling algorithms could result in starvation?

a\. First-come, first-served
b\. Shortest job first
c\. Round robin
d\. Priority

b and d.

4\. The traditional UNIX scheduler enforces an inverse relationship between priority numbers and priorities: The higher the number, the lower the priority. The scheduler recalculates process priorities once per second using the following function: 
Priority = (Recent CPU usage / 2) + Base
where base = 60 and recent CPU usage refers to a value indicating how often a process has used the CPU since priorities were last recalculated. Assume that recent CPU usage for process P1 is 40, process P2 is 18, and process P3 is 10. What will be the new priorities for these three processes when priorities are recalculated? Based on this information, does the traditional UNIX scheduler raise or lower the relative priority of a CPU-bound process?

When priorities are recalculated:

|Process|CPU usage|New Priority|
|-|-|-|
|P1|40|80|
|P2|18|69|
|P3|10|65|

the traditional UNIX scheduler does **not** raise or lower the relative priority of a CPU-bound process.
