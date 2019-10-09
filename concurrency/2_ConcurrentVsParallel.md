## Serial Execution

When programs are serially executed, they are scheduled one at a time on the CPU. Once a task gets completed, the next one gets a chance to run.
Each task is run from the beginning to the end without interruption.

Analogy - Its like a circus juggler who can only juggle one ball at a time

## Concurrency

* A concurrent program is one that can be decomposed into constituent parts and each part can be executed in partial order without affecting the 
final outcome.
* A system capable of running several distinct programs or more than one independent unit of the same program in 
overlapping time intervals is called a concurrent system. The execution of the 2 program may not happen simultaneously.
* Concurrent systems achieve lower latency and higher throughput when programs running on the system require frequent network or disk I/O
Ex - An operating system running on a single CPU is a concurrent system
* Analogy - A Juggler who can juggle multiple balls at the same time but at one point he has just one ball in his hand.

## Parallel
* A system which has the ability to execute multiple programs at the same time.
* Usually its provided by hardware in the form of multicore processors on individual machines or computing clusters where 
several machines are hooked together to solve independent pieces of a problem
* An individual problem has to be concurrent in nature, i.e. portions of it has to be worked on independently without 
affecting the final outcome before it can be executed in parallel.Ex - Matrix Multiplication, 3D rendereing, Data Analysis
* Analogy - 2 or more jugglers juggling 1 or more balls
* OS in a 4 CPU core machine can either execute parts of a single program parallelly on multiple CPUs or distinct programs

## Concurrency vs Parallel

1. A concurrent system may not be parallel but a parallel system is inherently concurrent
2. System can be both concurrent and parallel - A multitasking operating system running on multiple machines
3. Concurrency is about dealing with a lot of things and parallelism is about doing a lot of things.
Ex - 1 coffee machine service 2 customer queues alternately (Concurrent)
     2 coffee machine service 2 customer queues parallely (Parallel)
     
##  Preemptive Multitasking vs  Cooperative  Multitasking
* In preemptive multitasking, the operating system preempts a program to allow another waiting task to run on the CPU.
Malicious program cannot harm others.

* Cooperative Multitasking involves well-behaved programs to voluntarily give up control back to the scheduler so that another program can run.
Malicious program can harm others.



