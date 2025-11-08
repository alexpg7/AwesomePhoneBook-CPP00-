# 📔 AwesomePhoneBook-CPP00- ![Static Badge](https://img.shields.io/badge/Barcelona-black?style=for-the-badge&logo=42&logoColor=%23FFFFFF)
![Static Badge](https://img.shields.io/badge/C++-blue?style=flat&logo=cplusplus)
![Static Badge](https://img.shields.io/badge/Makefile-green?style=flat&logo=AnkerMake)
![Static Badge](https://img.shields.io/badge/status-completed-green?style=flat)

A first exercise as an introduction to C++ syntax.

## ⚒️ Compilation

All exercises can be compilated with the command ``make``
```bash
make
```

## 0️⃣ Ex00

This first exercise is thought to make you understand that from now on, objects in C++ are the main feature you will be using, not like in C, where you didn't have that option.

The ``megaphone`` program has two functionalities:

1. Prints a special message when executing it wothout arguments.

```bash
./megaphone
```
```output
* LOUD AND UNBEARABLE FEEDBACK NOISE *
```
2. Prints your arguments in uppercase and without separation
```bash
./megaphone hello world "!" :D
```
```output
HELLOWORLD!:D
```

And why using C++ instead of C? The main change is that now you don't need to use ```printf()```. A new object is introduced: stream buffers. And, with all this new class concept, a new feature is introduced: operator overloading.

In C++ classes, one can decide which functionality each operator does. For our case, the operator ``<<`` takes a stream buffer (on the left), streams through that buffer the object on the right (a ``string``, in this case) and outputs another stream buffer. That means you can use the result to operate it again with another ``string`` or ``char`` and so on and so on...

```math
\texttt{<<}:\;\;(\texttt{std::ios},\texttt{std::string})\longrightarrow\texttt{std::ios}
```

So, the following two lines are equivalent:
```cpp
char c = '!';
printf("Hello, world%c\n", c);
std::cout << "Hello, world" << c << std::endl;
```

This is useful because stream buffers have a definition for (almost) every class or datatype in C++. We no longer have to care about what datatype we want to print (linke in ``printf``, where we had to choose ``%c``, ``%s``, ``%i``, etc.), we just put it into de stream with ``<<`` and continue coding 😃.

## 1️⃣ Ex01

In this exercise we are asked to make a phonebook using the ``Contact`` and ``PhoneBook`` classes. The new concept here is the use of **methods**. These are functions that are defined inside a class and use the information of that class to output whatever we want. Why not use a general function? There are two main reasons:

1. Classes may have some ``private`` or ``protected`` values, which means that they can only be read/modyfied inside the class. This is just a feature to ensure security, we can only call ``public`` methods from outside the class, and the programmer decides what those methods do with the ``private`` atributes of the class.
2. Organization. Object Oriented Programming came to bring us a more structurated way to make programs. Before, we had datatypes and functions. Now, we also have classes and methods, we create objects and those objects do things 😃.

### The 📔PhoneBook

This phonebook is meant to store a maximum of 8 contacts. Once we execute the program with ``./phonebook``, we are asked to choose one out of three commands:

* ADD: create a new contact and fill their information (name, surname, number, darkest secret 😈).
* SEARCH: display the full information of a contact.
* EXIT: exit the program

That's all, folks! 🫡
