Caching is based on locality of reference principle: Recently requested data is likely to be requested again
It is used in
1. Hardware (L1, L2 cache)
2. Operating System (Dentry cache, Inode cache, Page Cache, etc)
3. Web Browser
4. Web Applications (Network area cache used in DNS lookup, Webserver cache for frequent requests)

### Application Server Cache
Cache on one request layer node could be located both in memory (which is very fast) and on the node's local disk 
(faster than going to network storage).

If you load balancer randomly distributes requests across the nodes, the same request will got to different nodes thus increasing cache misses.
2 ways to fix this is using Global Cache and Distributed Cache

### Content Distribution Network (CDN)
CDNs are a kind of cache that comes into play for sites that serving large amounts of static media.
Request -> CDN -> Backend servers
Future Planning - If the system we are building isn't yet large enough, we can put the static media files on a separate website
like static.mitesh.com and then later bring up CDN at that url.

### Cache Invalidation Schemes
If data is modified in the source of truth(database), cache must be invalidated.

#### Write Through Cache
Data is written into the cache and the corresponding database at the same time.

* Pros - DB and Cache are consistent always, No data lost in case of power crash, failures
* Cons - Higher Latency for write operations
* You can also write in DB and delete the data from cache. When cache miss occurs, latest data can be read from DB.

#### Write Around Cache
Data is not written into cache, just in the database
This can reduce the cache being flooded with write operations that will not be re-read.

#### Write Back Cache
Data is written only in the cache, leading to low latency and high throughput.
Cons - Risk of data loss in case of crash

### Cache Eviction Policies
FIFO, LIFO, LRU, MRU (Most Recently Used), LFU, RR(Random Replacement)

Common ones are:
1. LRU
2. LFU (Least Frequently Used) - Keep a count of how frequently each item is requested and delete the one which is least frequently used. Problem is that sometimes an item is only used frequently in the past, but LFU will still keep this item for a long while
3. W-tinyLFU - Calculate frequency within a time window

#### LRU Design
1. list<int> (Deque)
2. map <int, list<int>:: iterator> mp (key, location in list map)
3. map <int, int> cache (key value map)

### Concurrency
Problem: When multiple clients are trying to update the same cache slot at the same time, the one who updates last wins leaving cache in inconsistent state. It's a classic reader writer problem.

* Solution 1: Use a lock on the whole cache but it affects performance
* Solution 2: Split a cache into multiple shards and have a lock on each of them so that clients won't wait for each other if they are updating cache from different shards. Shards with hotspots will be more often locked than other.
* Solution 3: Use commit logs. To update the cache, store all mutations into logs first and then some background process will update all logs asynchronously. This is common in DB design.

### Examples
Reladomo has an write-through object cache. It gurantees that cache will always be updated in a transaction.
It supports 2 types of Caches

1. Full Cache -> This is for tiny static tables. If you make changes in such tables, you will have to restart the app.
2. Partial Cache -> Reladomo will not have re-read the same object over and over again. Once fetched in a transaction is enough. It will cache its results using soft references.
If you know, you must go to the database, you can bypass the cache
FooList list = new FooList(someOp);
list.setBypassCache(true);

### Distributed Cache
Distribute the cache to multiple machines and store the mapping in a hash table in corrdinator machine.
Machine M may need to fetch the data from DB if it does not exist and then return back.

#### Memcached Design
Distributed Hash Table - Key is 250 bytes and value is 1 MB.
Client Server Architecture
1. Client first hashes the key to get the machine name
2. Server machine again hashes to get where the record exists in RAM








