## Usecase Diagrams 

* Describe a set of actions that a system can do.
* Example: Online Shopping System
  Actors: Customer, Guest
  Action:
  Customer →  [Checkout Shopping Cart] →  [Make Payment] (Include)
  Guest (a type of Customer) →  [Search Product] ← [Search Product by Category]
	  		                     [Search Product By Name]
* Include → It’s like the invocation of one function by another
* Extend → Extended use case will work exactly like the base use case except that the extended use case will have some new steps


## Class Diagrams

* Describes the attributes and operations of a class
* Describes the constraints imposed on a system
* Class is depicted as a rectangle

##### Example
Flight

Properties
flightNumber: string
departureAirport: Airport
arrivalAirport: Airport
durationInMinutes: int

Operations
cancelFlight(): bool
addFlightSchedule(): bool
getInstances(): list<FlightInstance>

##### Aggregation vs Composition

* Aggregation = Weak Association
Aircraft and Airline have a weak association. Aircraft can exist without Airline.

* Composition = Strong Association
The child class instance lifecycle is dependent on the parent’s class instance lifecycle. 
Example: Weekly schedule is composed in Flight which means when Flight lifecycle ends, WeeklySchedule automatically gets destroyed.



##### Generalization vs Specialization
They occur only when there is Inheritance. We can convert references of one class type to another class type. 
  * Converting a subclass type into a superclass type is called Generalization. 
  We will be able to access all superclass methods but not subclass. 
  This is safe because classes will become more general. 
  For ex, if we say Car is a Vehicle, there is no problem.

  * Converting a superclass type into a subclass type is called Specialization. This is not safe as classes will become more and more narrow. 
  Saying that Vehicle is a Car requires proof. Thus this type of casting is explicit.


##### Dependency
It’s a relationship between objects in which one class depends on another class. 
If the implementation of dependency class changes, the dependent class gets impacted. 
FlightReservation depends on Payment.


## Sequence Diagrams
* They describe interactions among classes in terms of an exchange of messages over time and 
are used to explore the logic of complex operations, functions or procedures.
* At the top of the diagram, identify the classes and put each class on the top. 

## Activity Diagrams
