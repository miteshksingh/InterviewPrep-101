# Scalability
Capability of a system, network or process to grow and manage increased demand

Performance of a system decreases with system size. Why?
1. Network speed may become slower because machines tend to be far apart from one another.
2. Some tasks may be inherently atomic, thus cannot be distributed.

Goal - Scale without performance loss

## Reasons for scaling
1. Increased Data Volume
2. Increased number of transactions per second

## Horizontal Scaling
1. Scale by adding more servers into your pool of resources
2. Scales dynamically
3. Ex. Cassandra and MongoDB - provide an easy way to add more machines to meet needs

## Vertical Scaling
1. Scale by adding more power (CPU, RAM, Storage, etc) to an existing server
2. Often has an upper limit on the capacity of server
3. Involves Downtime
4. Ex. MySQL  - provides an easy way to switch from smaller to bigger machines


# Reliability
* Reliability is a measure of how long an operation performs its intended function. A system is reliable if it keeps delivering its services when one or several of its software/hardware components fail.
* It is the probability a system will fail in a given time period.
* Reliability can be measured by Failure rate. 
  Failure Rate = Number of failures/Total Time In Service
  
* How to make systems reliable?
By redundancy of software components and data (eliminating single point of failure). 
Ex - If a server carrying the user's shopping cart fails, another server that has the exact replica of the shopping cart should replace it.

# Avaliability
* Availability is a measure of the % of time equipment is in an operable state.
* Availability = Uptime/Total Time.
* If a system is reliable, it is available. However if it's available, it is not necessarily reliable. It may be serving bad content.
* Possible to achieve high A but low R by minimizing repair time and ensuring spares come online when needed.
* Low availability (ex. fb going down) results in reputational and financial damage to the customers.


# Efficiency
2 Metrics - Latency (response time) & Throughput (Bandwidth)
Throughput is how much work gets done per unit of time.
Latency is the time required to complete a task or produce a result. It is the delay to obtain the first item.
Latency and Throughput have inverse relationships.

At an atomic level, why is the throughput of a distributed system decreases?
1. Increased number of messages globally sent by the nodes of the system
2. Increased size of the message representing the volume of data exchanges

Ex - Searching for a specific key in a distributed data store uses above 2 operations

# Manageability
How easy is it to operate & mantain a system?
Goal: Helps in decresing downtime and improve developer productivity

1. Ease & Speed of diagonising the problems
2. Ease & Speed of making updates

# Questions

1. How do you improve the scalability of a system?
* Vertical Scaling and Horizontal Scaling (Load Balancing + Sharding)

2. How do you improve the availability of a system?
* Adding Replicas and Active-Passive mode for each node

3. How do you increase the read throughput of a system?
* Add a distributed cache like Cassandra

4. How do you increase the consistency of a system writes?
* Keep a local copy of write data on coordinator node. If any commit fails, try with this data again
* Each write on a host is first kept on a commit log. Commit log can be used to recover to a state
* Resolve conflict on read - When the requested resource locates in A1, A2, A3, the coordinator can ask all 3 machines.
If by any chance the data is different, coordinator can resolve the conflict on the fly.






