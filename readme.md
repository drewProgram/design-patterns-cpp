# Design Patterns
In this repo I'll take notes and develop various design patterns using C++.

## Factory
### Purpose
It's a creational design pattern which provides an interface for creating objects in a superclass, but allows sublasses to alter the type of objects that will be created.

### Applicability
* Use the Factory Method when you don't know beforehand the exact types and dependencies of the objects your code should work with.
* The Factory Method separates product construction code from the code that actually uses the product. Therefore it's easier to extend the product construction code independently from the rest of the code. For example, to add a new product type to the app, you'll only need to create a new creator subclass and override the factory method in it.

### Why to use
* Avoid tight coupling between the creator and the concrete products.
* *Single Responsibility Principle*. You can move the product creation code into the place in the program, making the code easier to support.
* *Open/Closed Principle*. You can introduce new types of products into the program without breaking existing client code.