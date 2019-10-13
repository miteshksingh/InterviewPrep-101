When are Rate Limiters needed?
* A misbehaving script which is sending lot of traffic
* The user sending high volume of low priority requests
* Something wrong internally, so you can’t serve regular traffic

How do you design a Rate Limiter?
* Request Rate Limiter - Restrict each user to N requests per second
* Concurrent Requests Limiter - You can only have 20 API requests in progress at the same time. 
In the case of a resource-intensive API, the API takes longer to complete. 
Frustrated users retry which adds more load to the server. This limiter handles such cases.
Before we started using concurrent requests limiter, we regularly dealt with resource contention on our most expensive endpoints caused by users making too many requests at one time

* Fleet Usage Load Shedder -  Ensures that a certain percentage of your fleet will always be available for your most critical API requests
* Worker utilization load shedder -  Shed less critical requests (Critical, POST, GET, test mode)
Implement Rate Limiter using Token Bucket Algorithm and Redis
If Rate Limiter fails, API should be functional. Show clear exceptions to users (503 or 429)
