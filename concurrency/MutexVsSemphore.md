## Mutex (Mutual Exclusion)
 * A mutex is used to guard shared data such as a linked list, an array or any primitive type. 
 * A mutex allows only a single thread to access a resource or critical section.
 * Once a thread acquires a mutex, all other threads attempting to acquire the same mutex are blocked until the 
 first thread releases the mutex. 
 * Once released, most implementations arbitrarily choose one of the waiting threads and make progress
 
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





 
 

