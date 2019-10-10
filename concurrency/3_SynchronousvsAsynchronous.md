### Synchronous
* Synchronous execution refers to line by line execution of code. If a function is called, program waits.

### Asynchronous 
* Asynchronous programming is a means of parallel programming in which a unit of work runs separately from the main application 
thread and notifies the calling thread of its completion, failure or progress
* It refers to execution that doesn't block when executing subroutines. It can invoke a method and moves onto the next 
line of code without waiting for the method to complete. Such methods can notify to the main thread in 2 ways
  * Return an entry called Future or Promise that is a representation of an in-progress computation
    The program can query the status of the computation via the Future object
  * Pass a callback function to the async function call
* Asynchronous programming is good for apps that do extensive network or disk IO and spend most of their time waiting.
Ex - Javascript enables concurrency using AJAX's asynchronous library


### IO Bound vs CPU Bound

Programs broadly consume the following 4 things - CPU Time, Memory, Networking Resources, Disk Storage
Ex1 - A program that loads gigabytes of data from storage into main memory would hog the main memory of the machine it runs on. 
Ex2 - Another can be writing several gigabytes to permanent storage, requiring abnormally high disk i/o.

### CPU Bound
Programs which are Compute intensive i.e. programs which require very high utilization of the CPU (close to 100%) are called CPU Bound programs. Such programs(data crunching, image processing, matrix multiplication) depend on increasing CPU speed to to decrease program completion time.

### IO Bound
* Programs which spend most of their time waiting for the input/output operations to complete while the CPU sits idle.
* IO operations can consist of reading/writing from memory and network interfaces.
* Because the CPU and main memory are physically separate a data bus exists between the two to transfer bits to and fro. Similarly, data needs to be moved between network interfaces and CPU/memory. Even though the physical distances are tiny, the time taken to move the data across is big enough for several thousand CPU cycles to go waste. This is why I/O bound programs would show relatively lower CPU utilization than CPU bound programs.

### Memory Bound Programs
There are memory bound programs which depend on the amount of memory available in order to speed up the process.

### Support for Multithreading
Ways to achive concurrency
1. Threads
2. Asynchronous Methods

Javascript is single threaded, Java provides full blown multithreading, and Python has somewhat. However, all 3 support asynchrnous programming model (concurrent but not parallel)






