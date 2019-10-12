1 Lock - Mutex
2 Synchronization Variables - Semaphore, Condition Variables

## Mutex (Mutual Exclusion)
 * A mutex is a lock. It is used to guard shared data such as a linked list, an array or any primitive type. 
 * A mutex allows only a single thread to access a resource or critical section.
 * Once a thread acquires a mutex, all other threads attempting to acquire the same mutex are blocked until the 
 first thread releases the mutex. 
 * Once released, most implementations arbitrarily choose one of the waiting threads and make progress
 
 ### When to use Mutex?
 When you want to ensure that a piece of code is atomic, put a lock around it. You could theoretically use a binary semaphore to do this, but that's a special case.
 
 ### How is a Mutex implemented?
 Use a flag and a queue.
 Flag - Indicates whether the mutex is held by anyone
 Queue - Tracks which threads are in line waiting to acquire the mutex exclusively
 
 
## Semaphore

* It is used for limiting access to a collection of resources.
* Ex - 10 available DB connections and 50 requesting threads. A semaphore can only give out ten permits or connections 
at any given point in time. Other threads will be blocked.

## Binary Semaphore vs Mutex
* Binary Semaphore can also be used for signalling among threads while a mutex is strictly limited to serializing access 
to shared state among competing threads. For example - in producer consumer problem, 
the producer thread can signal the consumer thread by incrementing the semaphore count to indicate to the consumer thread
to consume the freshly produced item.

* A semaphore can potentially act as a mutex if the permit it can give out is set to 1. But in case of mutex the same thread must call
acquire and release on the mutex. But in case of binary semaphore, different threads can call acquire and release on the semaphore.
* pthread library documentation (pthread_mutex_unlock) states undefined behaviour if thread which did not acquire mutex tries to release it.
* Thus, mutex has a concept of ownership. A mutex is owned by the thread acquiring it till the point the owning thread releases it.
But for semaphore, there's no notion of ownership.

## Condition Variables

* A condition variable is a synchronization variable used to avoid busy waiting(looping repeatedly while checking a condition) while waiting for a resource to become available.

* It needs two elements
  * a predicate (typically implemented by checking a flag or a counter)
  * a mutex that protects the predicate

* Ex - Usually in a multithreaded environment, a thread needs to wait for some program predicte to be true before it can move forward. In a producer consumer problem, a mutex ensures the queue's internals are consistent when accessed by the various producer and consumer threads. However, when the queue is empty, how will a consumer thread know when something is in there for it to work on? If the producer hasn't produced anything, the consumer can't consume anything, so they must wait on the predicte. The busy wait approach would be to poll the queue -   

```
void busyWaitFunction() {
  acquire mutex
  while(predicate is false) {
     release mutex
     acquire mutex
  }
  do something useful
  release mutex
}
```

Problem: You are wasting processor time by having this thread repeatedly check the condition
Solution: Use a synchronization variable that can be signalled to tell the thread that the resource is available

```
void efficientWaitingFunction() {
    mutex.acquire()
    while (predicate == false) {
      condVar.wait()
    }
    // Do something useful
    mutex.release()     
}

void changePredicate() {
    mutex.acquire()
    set predicate = true
    condVar.signal()
    mutex.release()
}
``` 

* Each condition variable exposes 2 methods - wait and signal. This thread will be put in wait queue and mutex will be released. There would be another thread somewhere that is pulling things out of the queue. When the queue has elemnt, that thread can just signal. It is only after the producer thread which calls the signal() method has released the associated mutex that the thread in ready queue starts executing.

### Why the while loop?

* After a producer thread signals, another prodcuer thread may update the value of predicate. A check in while loop ensures that the consumer thread checks on the new updated value again.
* Spurious of Fake wakeups are possible

### Condition Variable vs Semaphore

* Semaphores are better used when you have a shared resource that can be available and unavailable based on some integer number of available things. Semaphores are good for producer/consumer situations where producers are allocating resources and consumers are consuming them.

* Semaphore can be used as it is without external dependencies. You can use it either as a mutex or as a conditional variable.
Therefore, semaphore can be treated as a more sophisticated structure than conditional variable, while the latter is more lightweight and flexible.

### Condition Variable vs Mutex

* A condition variable allows a thread to be signaled when something of interest to that thread occurs. By itself, a mutex doesn't do this. If you just need mutual exclusion, then condition variables don't do anything for you. However, if you need to know when something happens, then condition variables can help.

## Monitors

* A monitor is a mutex and one of more condition variables. They allow threads to excercise mutual exclusion as well as cooperation by allowing them to wait and signal on conditions.
* Monitors are generally language level constructs  whereas mutex and semaphores are OS level constructs.
* Monitors has a mutex and 2 sets - Entry Set and Wait Set. Many threads first sit in entry set. One of them acquires the monitor. It either completes or gets on wait state. On wait(), it moves to wait set and another thread from entry set acquires the monitor. 

#### Java Specific Details
* In Java each object is a Monitor and implicitly has a lock and is a condition variable too. Thus each object has a wait() and signal() method. 
* Before we execute wait() on a java object, we need to lock its hidden mutex. That is done through the synchronized keyword. If you attempt to call wait()/signal() outside of a monitor block, IllegalMonitorStateException would occur. 
* Ways to own a monitor
  * the method the thread is executing has synchronized in signature
  * the thread is executing a block that is synchronized on the object on which notify, wait will be called
  * in case of a class, the thread is executing a static method which is synchronized
* Java uses Mesa monitors(just release the monitor and it's up for grab) instead of Hoare monitors(give monitor to some specific thread), thus the while loop.




## Summary
* Mutex implies mutual exclusion and is used to serialize access to critical sections whereas 
semaphore can potentially be used as a mutex but it can also be used for cooperation and signaling amongst threads. Semaphore also solves the issue of missed signals.
* Mutex is owned by a thread, whereas a semaphore has no concept of ownership.
* Mutex if locked, must necessarily be unlocked by the same thread. A semaphore can be acted upon by different threads. 
This is true even if the semaphore has a permit of one
* Think of semaphore analogous to a car rental service such as Hertz. Each outlet has a certain number of cars, 
it can rent out to customers. It can rent several cars to several customers at the same time but if all the cars are 
rented out then any new customers need to be put on a waitlist till one of the rented cars is returned. 
In contrast, think of a mutex like a lone runway on a remote airport. Only a single jet can land or take-off from the 
runway at a given point in time. No other jet can use the runway simultaneously with the first aircraft.





 
 

