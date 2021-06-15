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

## Builder
### Purpose
It's a creational design pattern that lets you construct complex objects step by step. The pattern allows you to produce different types and representations of an object using the same construction code.

### Applicability
#### Use the Builder pattern to get rid of a "telescopic constructor".
Say you have a constructor with ten optional parameters. Calling such a beast is very inconvenient; therefore, you overload the constructor and create several shorter versions with fewer parameters. These constructors still refer to the main one, passing some default values into any omitted parameters.
```cs
class Pizza
{
    // Creating such a monster is only possible in languages that
    // supports method overloading, such as C# or Java.
    Pizza(int size) {...}
    Pizza(int size, bool cheese) {...}
    Pizza(int size, bool cheese, bool pepperoni) {...}
}
// ...
```
The Builder pattern lets you build objects step by step, using only those steps that you really need. After implementing the pattern, you don't have to cram dozens of parameters into your constructors anymore.

#### Use the Builder to construct Composite trees or ohter complex objects.
The Builder pattern lets you construct products step-by-step. You could defer execution of some steps without breaking the final product. You can even call steps recursively, which comes in handy when you need to build an object tree.

A builder doesn't expose the unfinished product while running construction steps. This prevents the client code from fetching an incomplete result.

### Why use this?
* You can construct objects step-bystep, defer construction steps or run steps recursively.
* You can reuse the same construction code when building various representations of products.
* *Single Responsibility Principle*. You can isolate complex construction code from the business logic of the product.