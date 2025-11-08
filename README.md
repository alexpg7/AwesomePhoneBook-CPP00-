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
./megaphone hello world ! :D
```
```output
HELLOWORLD!:D
```

And why using C++ instead of C? The main change is that now you don't need to use ```printf()```. A new object is introduced: stream buffers. And, with all this new class concept, a new feature is introduced: operator overloading.

In C++ classes, one can decide which functionality each operator does. For our case, the operator ``<<`` 
## 1️⃣ Ex01
