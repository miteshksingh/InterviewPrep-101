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

* A condition variable is generally used to avoid busy waiting(looping repeatedly while checking a condition) while waiting for a resource to become available.

* Ex - If there are multiple threads that can't continue onward when the queue is empty, the busy waiting approach would be
```
while(!queue.empty()) {
 sleep(1);
}
```

Problem: You are wasting processor time by having this thread repeatedly check the condition
Solution: Use a synchronization variable that can be signalled to tell the thread that the resource is available

```
syncVar.lock.acquire()
while(!queue.empty()) {
 syncVar.wait();
}

//do stuff with the queue
syncVar.lock.release()
```
There would be a thread somewhere that is pulling things out of the queue. When the queue is empty, that thread can just signal.

* Semaphores can be used similarly, but I think they're better used when you have a shared resource that can be available and unavailable based on some integer number of available things. Semaphores are good for producer/consumer situations where producers are allocating resources and consumers are consuming them.

### Condition Variable vs Semaphore

To use a conditional variable, two other elements are needed:
* a condition (typically implemented by checking a flag or a counter)
* a mutex that protects the condition
The protocol then becomes,
* acquire mutex
* check condition
* block and release mutex if condition is true, else release mutex

Semaphore is essentially a counter + a mutex + a wait queue. And it can be used as it is without external dependencies. You can use it either as a mutex or as a conditional variable.
Therefore, semaphore can be treated as a more sophisticated structure than conditional variable, while the latter is more lightweight and flexible.

### Condition Variable vs Mutex

A condition variable allows a thread to be signaled when something of interest to that thread occurs.
By itself, a mutex doesn't do this.
If you just need mutual exclusion, then condition variables don't do anything for you. However, if you need to know when something happens, then condition variables can help.

For example, if you have a queue of items to work on, you'll have a mutex to ensure the queue's internals are consistent when accessed by the various producer and consumer threads. However, when the queue is empty, how will a consumer thread know when something is in there for it to work on? Without something like a condition variable it would need to poll the queue, taking and releasing the mutex on each poll (otherwise a producer thread could never put something on the queue).

Using a condition variable lets the consumer find that when the queue is empty it can just wait on the condition variable indicating that the queue has had something put into it. No polling - that thread does nothing until a producer puts something in the queue, then signals the condition that the queue has a new item.

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





 
 

