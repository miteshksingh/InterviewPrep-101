### Requirements
1. How large can the data be?

## Simple Key Value Store (fits on a machine or disk)
Use Hashtable to store key value pairs.

#### Pros
* read/write K,V in constant time
* easy to use, most languages have built in support

#### Cons
* Store everything in memory which is not possible when the data set is big enough

#### Solution
* Compress data - Store reference instead of actual data, float32 vs float64, different representations like bit array or vectors 
* Storing in a disk -  Frequently visited data in memory and the rest is on the disk

## Distributed Key Value Store
Split the data into multiple machine by some rule and have a coordinator machine that directs clients to the machine with the requested resource

##### Suppose all the key are urls like http://gainlo.co and we have 26 machines. How do we partition data?
* Approach 1
  * Divide all the keys based on the first character of the URL. gainlo.co - Machine A. blog.gainlo.co - Machine B
  * Cons
    * Storage is not distributed equally. Much more URL's starting with 'a' rather than 'z'.
    * Some urls are much more popular than other like google.com
    
* Approach 2
  * Hash the url and then allot machine using %N - URLs will be distributed randomly. So not hotspots.
  * Cons - If you add a new machine, hash will change and whole data will have to be moved

* Approach 3
  * Use Consistent Hashing
  
##### What if a machine crashes due to hardware issue or bug failure?
Solution is Replica. If a single machine has 10% chance to crash in a month, then weith a single backup we reduce the probability to 1% when both are down.
Cons:
* Introducing replicas causes us to think about consistency. How do we make sure A1, A2 and A3 have same data?
3 approaches explained

##### How do increase the read throuput?
* Design a cache system


### B+ Tree Design
Good Balance between read and write

### LSM Trees
1. Buffering new data in memory, batching writes in secondary storage
2. Avoiding global order maintainence

In Memory structures such as bloom filters, fence pointers and Tries help filter queries to avoid disk I/O.
LSM tree based design achieves better writes than B+ tree based designs.
LSM trees give up some read performance(for short range queries) given that we have to look for data through multiple levels.
They also give up some memory amplification to hold enough to hold enough in memory filters to support efficient point queries.

### Log Structured Hash Table (LSH)
1. Excellent write performance but suffers in range based read.
