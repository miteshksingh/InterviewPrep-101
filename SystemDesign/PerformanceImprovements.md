### Components in an efficient distributed system

1. Load Balancers
2. Have an alert framework - Fabric Alert whenever performance of a system goes down
2. Metric Dashboards - Latency, Throughput in your code
3. Health Checks - For all 3rd party dependency, database dependency
4. Robus API design
   * API Rate Limiter
      * Ask users to space out their request (helpful in case of fire)
      * Load Shedders - Drop low priority requests like Analytics request
   * Add Versioning
   * Idempotency and Idempotency keys on the server
5. Robust API Clients - Exponential Backoff & Jitter based retry logic on the client
5. Caching
6. Data Partitioning
7. Indexes

### What if DB performance is not satisfactory?
* Caching
* Partition Data
* Create Index

### Use Case Specific Improvements

1. Improve the download of a content from a REST API - Return a compressed content (gzip) from the server
2. Allow HTTP Persistant Connections on servers or may be increase it's timeout

### Robust API Design

1. Idempotent APIs
Design APIs that are idempotent, which means that they can be called any number of times while guaranteeing that side effects only occur once. The client just needs to retry to ensure the convergence of its own state with the server. This solves the problem of Ambiguous failure. In HTTP, PUT and DELETE Verbs are idempotent.

Example of Idempotency: Design an API endpoint to charge a customer money
Accidentally calling it twice can happen but the API shouldn’t deduct money. 
Solution: Use an idempotency key per client in each request. This lets the server decide what to do with a duplicate request. Mostly used with POST request.

2. Add Rate Limit to your APIs
3. Add Versions to your APIs

### Robust API Client Design
Designing API Clients:
When a client faces an error from the server, it should follow the Exponential Backoff algorithm instead of hammering the server with repeated requests. The client should wait proportionally to 2^n where n is the number of failures that have occurred.

If there are multiple clients being fired, add some randomness to client requests so that not every server makes a request at the same time. This will space out request across all clients and give the server some breathing room to recover.




