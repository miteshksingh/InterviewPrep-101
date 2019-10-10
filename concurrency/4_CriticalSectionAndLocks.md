## Critical Section
It is any piece of code that has the possibility of being executed concurrently by more than one thread of the application 
and exposes any shared data or resources used by the application for the access.

## Race Conditions
Race Conditions happen when threads run through the critical section without thread synchronization. The threads "race" through
the critical section to read or write shared resources and depending on the order in which the threads finish the race, the program
output changes.

Possible Scenarios of race conditions
* Test Then Act

## Deadlocks
Deadlocks occur when 2 or more threads aren't able to make any progress because the resource required by the first thread is help by the second
and the resource required by the second thread is help by the first

* Example
```
increment() {
  acquire MUTEX_A
  acquire MUTEX_B
  
  //Do Some Work
  
  acquire MUTEX_B
  acquire MUTEX_A
}

decrement() {
  acquire MUTEX_B
  acquire MUTEX_A
  
  //Do Some Work
  
  acquire MUTEX_B
  acquire MUTEX_A
}
```
Deadlock Scenario:
1. T1 enters function increment
2. T1 acquires MUTEX_A
3. T1 gets context switched by the OS
4. T2 enters function decrement
5. T2 acquires MUTEX_B
6. Both threads are blocked now

## Liveness
Ability of a program to execute in a timely manner is called liveness. If a program experiences a deadlock, then it's not
exhibiting liveness.

## Live Lock
A livelock occurs when 2 threads continously react in response to the actions by the other thread without making any real progress.
Analogy - Two persons trying to cross each other in a hall way. Joh moves left, Arun right, block again.

## Starvation
An application thread can  experience starvation when it never gets CPU time or access to shared resources.



## Demos
1. DemoMultiThreadSpeedUp
2. DemoThreadUnsafe by thread1 - incrementing and thread2 - decrementing counter and counter != 0
3. DemoRaceConditon - By thread1 checking global variable (printer) and thread2 modifying global variable (modifier)

