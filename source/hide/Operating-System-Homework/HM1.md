---
title: OS Homework 1
---
# Operating System Homework #1
Copyright &copy; zccz14. Follow CC-BY-NC license.

## Introduction

1 What is the main advantage of multiprogramming?

Increasing CPU utilization by dispatching works.

2 Define the essential properties of the following types of operating systems:
   
1. Batch: import several jobs and continually run them.
2. Interactive: support online user operation by I/O devices.
3. Time Sharing: several users or processes share system resource by time.
4. Real time: short latency, swift switch, high real-time availability.
5. Network: processes commucate by network
6. Distributed: abstract logical model, decouple from physical components

3 Consider the various definition of operating system. Consider whether the operating system should include applications such as web browsers and mail programs. Argue both that it should and that it should not, and support your answer.

Operating system **should** include general applications.

1. It's hard to say an application that is absolutely a system application or a general application. (system applications such as `.NET Framework` in Windows) (definition)

2. It makes the operating system much easier to use. Nobody wants to view webpage by `curl`. (user-friendly)

Operating system **should not** include general applications.

General applications are not necessary for operating system. General applications help user working. But operating system should not assume which application users work with. User could choose applications themselves. (for a clean OS)


## OS Structures

1 What is the purpose of system calls?

Providing the interactive interface between a running program and the operating system.

2 What is the main advantage of the layered approach to system design?

1. Serapating layer and layer is convenient to extend functions.
2. Decouple between layers.
3. Simply Requirements. (like a DAG)

3 What is the main advantage of the microkernel approach to system design?

1. Easy to extend.
2. More reliable.
3. Distributed calculations by Remote Procedure Call (sending requests).
