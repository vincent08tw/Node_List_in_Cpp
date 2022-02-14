/*****************************************************************************
[file name]--------------
main.cpp
[editor]----
yu-wen Wang (vincent08tw@gmail.com) (vincent08tw@yahoo.com.tw)
[create date]---
2021-11-06 
[last edit]---
2021-11-06 
*****************************************************************************/ 
/*
    don't over 80 character one line
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include "Node.h"
#include "List.h"
#include "function.h"

using namespace std;

int main(int argc, char** argv)
{
    // set output file "RESULT"
    
    ofstream output_file;
    output_file.open("RESULT");
    my_out myout(cout, output_file);
    myout << "Set output file" 
          << "\"RESULT\""
          << endl << endl;
          
    if(!output_file.is_open())
    {
        myout << "Failed to open the file: " 
              << "RESULT." 
              << endl << endl;
        return 0;
    }
    
    // check if there are two input file
    myout << "Check if there are two input file"
          << endl;
    if(argc != 3)
    {   
        myout << "argc = " 
              << argc
              << " ,it should be 3"
              << endl << endl;
        return 0;
    }
    else
    {
        myout << "Check argc = 3, OK!"
              << endl << endl;
    }
    
    // set input files 
    myout << "Set input files"
          << " \"" << argv[1] << "\""
          << " and" 
          << " \"" << argv[2] <<"\" "
          << endl << endl;
    ifstream input_file, input_file2;
    input_file.open(argv[1]);
    if(!input_file.is_open())
    {
        myout << "Failed to open the file: " 
              << argv[1] 
              << "." 
              << endl << endl;
        return 0;
    }
    input_file2.open(argv[2]);
    if(!input_file2.is_open())
    {
        myout << "Failed to open the file: " 
              << argv[2] 
              << "." 
              << endl << endl;
        return 0;
    }

    //Instantiate one double List
    myout << "Instantiate one double List name list_double1"
          << endl;
    List<double> list_double1;  
    //  Use data in the double file to construct the double List
    input_file >> list_double1;
    myout << "list_double1.getLength() = "
          << list_double1.getLength()
          << "\n"
          << "list_double1's content: "
          << list_double1
          << endl << endl;
    
    //Instantiate two string Lists
    myout << "Instantiate two string Lists ->"
          << "list_string1 and list_string2 "
          << endl;
    List<string> list_string1;
    List<string> list_string2;
    
    //use the data in the string file to construct the first string List.
    myout << "use the data in the string file "
          << "to construct the first string List."
          << endl << endl;
    input_file2 >> list_string1;
    myout << "list_string1.getLength() = "
          << list_string1.getLength()
          << "\n"
          << "list_string1's content: "
          << list_string1
          << endl << endl;
    
    // Use copy constructor to copy the already constructed List 
    // to create a second double List.
    myout << "assign list_double2(list_double1);"
          << endl;
    List<double> list_double2(list_double1);
    
    myout << "list_double2.getLength() = "
          << list_double2.getLength()
          << "\n"
          << "list_double2's content: "
          << list_double2
          << endl << endl;
    // Use assignment operator to 
    // assign the first string List to the second.
    myout << "assign list_string2 = list_string1;"
          << endl;
    list_string2 = list_string1;
    
    myout << "list_string2.getLength() = "
          << list_string2.getLength()
          << "\n"
          << "list_string2's content: "
          << list_string2
          << endl << endl;
          
    // Use operator== to check if the two double List and string List
    // are indeed the same. Use cout to report the comparison result.
    myout << "use (list_double1 == list_double2) to check"
          << endl;
    if (list_double1 == list_double2)
    {
        myout << ">>"
              << "\t"
              << "list_double1 == list_double2"
              << endl << endl;
    }
    else
    {
        myout << ">>"
              << "\t"
              << "list_double1 != list_double2"
              << endl << endl;
    }
    
    myout << "use (list_string1 == list_string2) to check"
          << endl;
    if (list_string1 == list_string2)
    {
        myout << ">>"
              << "\t"
              << "list_string1 == list_string2"
              << endl << endl;
    }
    else
    {
        myout << ">>"
              << "\t"
              << "list_string1 != list_string2"
              << endl << endl;
    }
    
    // Use setElement() to assign values to all Array objects.
    myout << "Use setElement() to assign values to all Array objects."
          << endl << endl;
    double doubleArray[12] = {
               2.648, 30.115, 0.9966,
               4.333, 41.487, 47.487,
               7.448, 77.125, 2.9936,
               4.133, 44.467, 45.247
               };
    string stringArray[12] = {
               "1.488", "33.515","1.9366",
               "2.468", "36.715","2.9566",
               "3.048", "70.188","6.9666",
               "4.498", "10.110","8.9766"
               };
    
    for(unsigned int i = 0; i < list_double1.getLength();i++)
    {
        list_double1.setElement(i, doubleArray[i]);
    }
    myout << "list_double1 was refreshed by doubleArray!"
          << endl;
    for(unsigned int i = 0; i < list_double2.getLength();i++)
    {
        list_double2.setElement(i, doubleArray[i]);
    }
    myout << "list_double2 was refreshed by doubleArray!"
          << endl;
    for(unsigned int i = 0; i < list_string1.getLength();i++)
    {
        list_string1.setElement(i, stringArray[i]);
    }
    myout << "list_string1 was refreshed by stringArray!"
          << endl;
    for(unsigned int i = 0; i < list_string2.getLength();i++)
    {
        list_string2.setElement(i, stringArray[i]);
    }
    myout << "list_string2 was refreshed by stringArray!"
          << endl << endl;
    
    // Check every list
    myout << "Now check every list~"
          << endl << endl;
          
    myout << "list_double1.getLength() = "
          << list_double1.getLength()
          << "\n"
          << "list_double1's content: "
          << list_double1
          << endl << endl;
          
    myout << "list_double2.getLength() = "
          << list_double2.getLength()
          << "\n"
          << "list_double2's content: "
          << list_double2
          << endl << endl;
    
    myout << "list_string1.getLength() = "
          << list_string1.getLength()
          << "\n"
          << "list_string1's content: "
          << list_string1
          << endl << endl;
          
    myout << "list_string2.getLength() = "
          << list_string2.getLength()
          << "\n"
          << "list_string2's content: "
          << list_string2
          << endl << endl;

    return 0;
}



