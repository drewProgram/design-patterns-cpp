# Design Patterns
In this repo I'll take notes and develop various design patterns using C++.

**Factory x Abstract Factory**: Factory creates a category of object. E.g.: Transport: Airplane, car, ship...

The Abstract Factory creates families of objects. E.g.: Related products: Chair, sofa, Coffee Table, but each one can be part of a family like the style, for example furniture with Art Deco, Victorian or Modern styles.


## Factory
### Purpose
It's a creational design pattern which provides an interface for creating objects in a superclass, but allows sublasses to alter the type of objects that will be created.

### Applicability
* Use the Factory Method when you don't know beforehand the exact types and dependencies of the objects your code should work with.
* The Factory Method separates product construction code from the code that actually uses the product. Therefore it's easier to extend the product construction code independently from the rest of the code. For example, to add a new product type to the app, you'll only need to create a new creator subclass and override the factory method in it.

### Why use this?
* Avoid tight coupling between the creator and the concrete products.
* *Single Responsibility Principle*. You can move the product creation code into the place in the program, making the code easier to support.
* *Open/Closed Principle*. You can introduce new types of products into the program without breaking existing client code.

## Abstract Factory
### Purpose
It's a creational design pattern that lets you produce families of related objects without specifying their concrete classes.

### Applicability
* Use the Abstract Factory when your code needs to work with various families of related products, but you don't want it to depend on the concrete classes of those products - they might be unknown beforehand or you simply want to allow for the future extensibility.
* The Abstract Factory provides you with an interface for creating objects from each class of the product family. As long as your code creates objects via this interface, you don't have to worry about creating the wrong variant of a product which doesn't match the products already created by your app. Consider implementing Abstract Factory when you have a class with a set of Factory Methods that blur its primary responsibility. In a well-designed program each class is responsible only for one thing. When a class deals with multiple product types, it may be worth extracting its factory methods into a stand-alone factory class or a full-blown Abstract Factory implementation.

### Why use this?
* You can be sure that the products you're getting from a factory are compatible with each other.
* You avoid tight coupling between concrete products and client code.
* *Single Responsibility Principle*. You can extract the product creation code into the place in the program, making the code easier to support.
* *Open/Closed Principle*. You can introduce new variants of products into the program without breaking existing client code.
