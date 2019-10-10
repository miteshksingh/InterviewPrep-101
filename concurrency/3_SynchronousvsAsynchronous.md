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



