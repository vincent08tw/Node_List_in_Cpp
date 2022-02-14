# Node_List_in_Cpp - vincent08tw  
###### tags: `C++` `C`  

## Project Description  
Practice Object Oriented Design in C++  
v1: Develop a Node base class and derive a List class. Then a main() that uses List.  
v2_template: Based on the Node and List classes in v1, develop a Node template base class then derive a List template class. Then a main() that uses List.  

* Environment
	* Ubuntu 18.04 / Windows 10

* Specification  
```
Node, the base class
1. Create a class called Node, which has one data member:
	◦ long *_ Node;
2. And Node has access methods (member functions) as follows:
	◦ Node(); // Initializes _Node as NULL
	◦ Node(unsigned int _length); // Constructs _Node as a long array of size _length
	◦ ~Node(); // Delete Node
	◦ long* reCreate(unsigned int _length); 
		// Allocates for _Node a long array of size _length
		// Returns the address of newly allocated _Node
	
List, the class derived from Node
1. Create a class called List that is derived from Node.
2. List has one data member:
	◦ unsigned int length;
3. List has access methods (member functions):
	◦ List(); 
		// It must inherits and calls Node() to initialize _Node
		// Initialzes length as 0
	◦ List(unsigned int _length);
		// It must inherits and calls Node(_length)to initialize _Node
		// Initializes length as _length
	◦ List(const List &other); // The copy constructor that copies other to *this
	◦ ~List();
		// Implicitly calls ~Node()
		// Resets length to 0
	◦ List& operator=(const List& other);
		// Assignment operator that assigns other to *this. 
	◦ int setLength(unsigned int);
		// If the original length isO, the function sets a new length, uses
		// reCreate () to allocates an array of size length to Node, then returns 1.
		// If the original length is not 0, the function prints an error message then returns 0.
	◦ unsigned int getLength();
		// The function returns the value of length.
	◦ int setElernent(unsigned int pos, long val);
		// Assigns val to Node [pos].
		// The function returns 1 if pos is legal; otherwise prints an error message and returns 0.
		// Notice that there is a need to add a respective member function to the base Node class.
	◦ long getElement(unsigned int pos);
		// Returns the value Of_Node [pos if pos is legal.
		// If pos is illegal, prints an error message and returns -99999.
	◦ List operator+(const List &);
	◦ List& operator+=(const List &);
	◦ List operator++();
	◦ List operator++(long);
	◦ List operator--();
	◦ List operator--(long);
	◦ friend ostream& operator<<(ostream &, List);
	◦ friend istream& operator>>(istream, List &);

int main(int argv, char *argv[])
1. Use command input (argv[1]) to get the input file name. The first line of the file is the number of integers to be stored in a List. For example
	3
	2523 53 88743
	Means there are 3 inputs, 2523, 53 and 88743.
2. For the sake of verifying the classes, we must exercise all member functions to do the following:
	-> Use operator>> to read the input file into a List
	-> Copy the List to other 3 Lists using 3 different ways. So, in total you have exactly 4 List objects for below operations. Please be aware that you can elaborate freely what do they mean by 'copy', 'assign', 'add' and 'subtract' in the class List. But remember to explain, by using operator<<, how you implement above mentioned functions.
	-> Add two of the Lists using operator+
	-> Use operator++ to add 1 to another List
	-> Use operator++(long) to add 1 to another List
	-> Use operator+= to add another List to a List
	-> User operator-- to subtract 1 from all elements in a List
	-> Use operator--(long) to subtract 1 from all elements in another List
	-> Every time a new List object is instantiated or changed, use operator<< to write to a file named RESULT. When you print a List please also print some words to explain what operation(s) is (are) applied to the following List to be printed.
```

## Project directory hierachy
```
Node_List_in_Cpp/
    +-- v1/
    |   +-- src/
    |   |    +-- main.cpp
    |   |    +-- makefile
    |   |    +-- List.cpp
    |   |    +-- List.h
    |   |    +-- Node.cpp
    |   |    +-- Node.h
    |   README.md
    +-- v2_template/
    |   +-- src/
    |   |    +-- main.cpp
    |   |    +-- makefile
    |   |    +-- List.cpp
    |   |    +-- List.h
    |   |    +-- Node.cpp
    |   |    +-- Node.h
    |   |    +-- string.txt
    |   |    +-- double.txt
    |   |    +-- function.h
    |   README.md
    |
```























