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
Array, the template base class
1. Create a template class called Node with a template data type, which has one data member:
	◦ T *_ Node;
2. And Node has access methods (member functions) as follows:
	◦ Node(); // Initializes _Node as NULL
	◦ Node(unsigned int _length); // Constructs _Node as a long array of size _length
	◦ ~Node(); // Delete Node
	◦ T* reCreate(unsigned int _length); 
		// Allocates for _Node a long array of size _length
		// Returns the address of newly allocated _Node
	
List, the class derived from Node
1. Create a template class called List that is derived from Node with the same template class T.
2. List has one data member:
	◦ unsigned int length;
3. List has access methods (member functions):
	◦ List(); 
		// It must inherits and calls Node() to initialize _Node
		// Initialzes length as 0
	◦ List(unsigned int _length);
		// It must calls Node(_length)to initialize _Node
		// Initializes length as _length
	◦ List(const List &other); // The copy constructor that copies other to *this. 
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
	◦ int setElernent(unsigned int pos, T val);
		// Assigns val to Node [pos].
		// The function returns 1 if pos is legal; otherwise prints an error message and returns 0.
	◦ T getElement(unsigned int pos);
		// Returns the value Of_Node [pos if pos is legal.
		// If pos is illegal, use an assert to check for this condition, prints an error message then exit the program.
	◦ List& operator=(const List &);
	◦ inline bool operator==(const List &);
	◦ friend ostream& operator<<(ostream &, List);

int main(int argv, char *argv[])
1. Use command input (argv[1]) to get the input file name. The first line of the file is the number of integers to be stored in a List. For example
	3
	2523 53 88743
	Means there are 3 inputs, 2523, 53 and 88743.
2. Since it is difficult to check if the input is of double type, and any data can be considered string type and thus no use in checking string's legitimacy. In this assignment you can assume all input data are legal and develop no checking mechanism.
3. When executing your program, the first input argument, argv[1], is the double file name. And argv[2] is the string file name. There should have no other input arguments (use argc to verify.)
4. Instantiate one double Lists and two string Lists. Use data in the double file to construct the double List. And use the data in the string file to construct the first string List.
5. Use copy constructor to copy the already constructed List to create a second double List.
6. Use assignment operator to assign the first string List to the second.
7. Use operator== to check if the two double List and string List are indeed the same. Use cout to report the comparison result.
8. Use setElement() to assign values to all Array objects.
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























