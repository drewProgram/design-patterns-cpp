# Design Patterns
In this repo I'll take notes and develop various design patterns using C++.

**Factory x Abstract Factory**: Factory creates a category of object. E.g.: Transport: Airplane, car, ship...

The Abstract Factory creates families of objects. E.g.: Related products: Chair, sofa, Coffee Table, but each one can be part of a family like the style, for example furniture with Art Deco, Victorian or Modern styles.


## Factory
### Purpose
It's a creational design pattern which provides an interface for creating objects in a superclass, but allows subclasses to alter the type of objects that will be created.

### Applicability
#### Use the Factory Method when you don't know beforehand the exact types and dependencies of the objects your code should work with.
The Factory Method separates product construction code from the code that actually uses the product. Therefore it's easier to extend the product construction code independently from the rest of the code. For example, to add a new product type to the app, you'll only need to create a new creator subclass and override the factory method in it.

#### Use the Factory Method when you want to provide users of your library or framework with a way to extend its internal components.
Inheritance is probably the easiest way to extend the default behavior of a library or framework. But how would the framework recognize that yout subclass should be used instead of standard component?

The solution is to reduce the code that constructs components across the framework into a single factory method and let anyone override this method in addition to extending the component itself.

### Why use this?
* Avoid tight coupling between the creator and the concrete products.
* *Single Responsibility Principle*. You can move the product creation code into the place in the program, making the code easier to support.
* *Open/Closed Principle*. You can introduce new types of products into the program without breaking existing client code.

## Abstract Factory
### Purpose
It's a creational design pattern that lets you produce families of related objects without specifying their concrete classes.

### Applicability
#### Use the Abstract Factory when your code needs to work with various families of related products, but you don't want it to depend on the concrete classes of those products - they might be unknown beforehand or you simply want to allow for the future extensibility.
The Abstract Factory provides you with an interface for creating objects from each class of the product family. As long as your code creates objects via this interface, you don't have to worry about creating the wrong variant of a product which doesn't match the products already created by your app. Consider implementing Abstract Factory when you have a class with a set of Factory Methods that blur its primary responsibility. In a well-designed program each class is responsible only for one thing. When a class deals with multiple product types, it may be worth extracting its factory methods into a stand-alone factory class or a full-blown Abstract Factory implementation.

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

## Adapter
### Purpose
It's a structural pattern that allows objects with incompatible interfaces to collaborate.

### Applicability
#### Use the Adapter class when you want to use some existing class, but its interface isn't compatible with the rest of your code.
The Adapter pattern lets you create a middle-layer that serves as a translator between your code and a legacy class, a 3rd-party class or any other class with a weird interface.

#### Use the pattern when you want to reuse several existing subclasses that lack some common functionality that can't be added to the superclass.
You could extend each subclass and put the missing functionality into new child classes. However, you'll need to duplicate the code across all of the new classes, which smells really bad.

The much more elegant solution would be to put the missing functionality into an adapter class. Then you would wrap objects with missing features inside the adapter, gaining needed features dynamically. For this to work, the target classes must have a common interface, and the adapter's field should follow that interface. This approach looks very similar to the Decorator pattern.

## Iterator
### Purpose
It's a behavioral pattern that lets you traverse elements of a collection withou exposing its underlying representation (list, stack, tree, etc).

### Applicability
#### Use the Iterator pattern when your collection has a complex data structure under the hood, but you want to hide its complexity from clients (either for convenience or security reasons).
The iterator encapsulates the details of working with a complex data structures, providing the client with several simple methods of accessing te collection elements. While this approach is very convenient for the client, it also protects the collection from careless or malicious actions which the client would be able to perform if working with the collection directly/

#### Use the pattern to reduce duplication of the traversal code across you app.
The code of non-trivial iteration algorithms tends to be very bulky. When placed within the business logic of an app, it may blur the responsability of the original code and make it less maintainable. Moving the traversal code to designated iterators can help you make the code of the application more lean and clean.

#### Use the Iterator when you want your code to be able to traverse different data structures or when types of these structures are unknown beforehand.
The pattern provides a couple of generic interfaces for both collections and iterators. Give that your code now uses these interfaces, it'll still work if you pass it various kinds of collections and iterators that implement these interfaces.