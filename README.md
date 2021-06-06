# Overview

This program is in some way a ticket system through the use of an SQL database and C++. At the moment, it focuses on the front-end of managing the client's (customer's) info and an event being triggered. When initializing the program, the User or employee is displayed a menu:

1. New Instance (Event)
2. Show Customers
3. Edit Customer
4. Find Customer
5. Delete Customer
6. Add Event
7. Delete Event
8. Edit Event
9. Exit

Every option provides its own use of instructions. It's a simple program with the sole purpose of managing events and customer info; such as "Failed RAM stick" or "Dead Pixels on LCD".

[Software Demo Video](http://youtube.link.goes.here)

# Development Environment

This program was made possible through the use of:
* Visual Studio Code
* C++ language
* MinGW-x64 (Creates an .exe file to compile & run code on VS Code)

The following header files and libraries were used in C++:
* iostream
* windows.h - Functions for Windows API
* cstdio - C Standard Input & Output
* fstream - Creation of Files
* sstream - Stream Style manipulation
* conio.h - Console Input-Output
* cstdlib - General Purpose Functions to String
* string - Declaring Variables
* mysql.h - SQL Integration


# Useful Websites

{Make a list of websites that you found helpful in this project}
* [The C++ Tutorial](https://www.learncpp.com/)
* [C++ Tutorial for Beginners - Full Tutorial](https://www.youtube.com/watch?reload=9&v=vLnPwxZdW4Y&vl=en&ab_channel=freeCodeCamp.org)
* [C++ Tutorial - W3Schools](https://www.w3schools.com/cpp/)
* [C++ Language](https://www.cplusplus.com/doc/tutorial/)

# Future Work

* Fixing several bugs (specifically selection of 1 & 3)
* Integrate SQL Database
* Finish Storing Functions (SQL + C++)