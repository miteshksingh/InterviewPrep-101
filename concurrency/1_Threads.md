## Concurrent System

Example of a concurrent system - Single Processor Machine running your favourite IDE. You edit and click save. 
IO Thread gets descheduled and UI Thread gets scheduled, giving you a responsive UI.
Threads give you an illusion of multitasking even though at any point in time only 1 thread is executing in the CPU.

## Program
It is a set of instructions and associated data that resides on the disk and is loaded by the OS to perform some task.
Ex - executables, python script

## Process
* A process is a program in execution. OS creates an execution environment in which the program executes.
* The execution environment consists of instructions, memory, CPU cycles, user data, system data segments, address space, disk and network I/O required at runtime.
* In multiprocessing systems, there's more than 1 CPU or core (extra hardware support). Thus multiple processes gets scheduled on more than one CPU.


## Threads
* Thread is a smallest unit of execution in a process. 
* A process can have multiple threads running as part of it.
* A thread simple executes instructions serially
* Within a process, there's some globally shared state among all threads. Programming languages offer constructs to safeguard
these global states when any thread tries to read or write to these.

### Benefits of Thread
1. Higher Throughput
2. Responsive Applications
3. Efficient Utilization of Resources

### Problems with Threads
1. Usually very hard to find bugs
Since the execution of the threads can't be predicted and is entirely up to the operating system, 
we can't make any assumptions about the order in which threads get scheduled and executed.
2. Higher cost of code maintainence
3. Increased utilization of system resources like memory, CPU cycles, waste of time in context switches
4. Programs may experience slowdown

### Process vs Threads
Processes don't share any resources amongst themselves whereas threads of a process can share the resources allocated to that particular process, including memory address space. 
However, languages do provide facilities to enable inter-process communication.



