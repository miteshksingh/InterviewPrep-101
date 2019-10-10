### Simplest Design
Use Hashmap. Simple but all data will be in memory.
Solution - Compress data, store only partial data in cache

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
