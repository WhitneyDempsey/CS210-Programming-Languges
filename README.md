# Corner Grocer Item Tracker
## C++ File Processing & Frequency Analysis Program 
## Project Overview 

The Corner Grocer Item Tracker is a C++ console application designed to analyze daily grocery purchase records and determine how frequemntly each item was purchased. The program reads item data from an imput file and processes it using an STL associative container (map<string, int>) to calculate frequency counts. 
The application provides an interactive menu that allows users to:
* Search for the frequency of a specific item
* Display all item frequencies
* View a text based histogram representation
* Exit the program 
At startup, the program automatically generates a backup file (frequency.dat) to preserve processed data.
This project demonstrates practical application of STL containers, object-oriented design, and structured data processing in C++.

## Key Technical Features

* Object Oriented Design using a GroceryTracker class
* STL (map<string, int>) for efficient frequency tracking
* File input/output using ifstream and ofstream
* Case insensitive searching through string normalization
* Input validataion using cin.fail()
* Modular function design for readability and maintainability

## How to Compile & Run

Using g++:

    g++ CornerGrocerTracker.cpp -o grocer
    ./grocer

Make sure CS210_Project_Three_Input_File.txt is in the same directory before running.


## Project Files 

CornerGrocerTracker.cpp – Main source file
CS210_Project_Three_Input_File.txt – Input data file
frequency.dat – Auto-generated backup file
Corner Grocer Documentation.pdf – Design and project documentation

## Skills Demonstrated 

* File processing & data persistence 
* Associative containers (maps)
* Object oriented programming principles
* Structured menu driven program design
* Input validation & usability improvements
* Clean, maintainable C++ coding practices 
