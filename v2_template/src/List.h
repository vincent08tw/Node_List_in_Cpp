/****************************
[file name]--------------
List.h
[editor]----
yu-wen Wang (vincent08tw@gmail.com) (vincent08tw@yahoo.com.tw)
[create date]---
2021-11-06 
[last edit]---
2021-11-06 
****************************/ 


#ifndef LIST_H
#define LIST_H

#include "Node.h"
#include <assert.h>
using namespace std;

template <class T>
class List : public Node<T>
{
    private:
        // Private section
        unsigned int length;
    public:
        // Public Declarations
        
        List(); //constructor 
        List(unsigned int _length); //constructor
        List(const List<T> &other); 
        ~List(); //destructor
        
        // Assignment operator that assigns other to *this.
        List<T>& operator=(const List<T> &other);
        
        // The function returns the value of length.
        unsigned int getLength() const;
        
        int setLength(unsigned int);
        
        int setElement(unsigned int pos, T val);
        
        // If legal, return _Node[pos]; If illegal, return -99999
        T getElement(unsigned int pos) const;
        
        List<T> operator+(const List<T> &other);
        List<T>& operator+=(const List<T> &other);
        List<T> operator++(); // prefix
        List<T> operator++(int); // postfix
        List<T> operator--(); // prefix
        List<T> operator--(int); // postfix
        
        template <class U>
        friend ostream& operator<<(ostream&, List<U>);
        template <class U>
        friend istream& operator>>(istream&, List<U>&);
        template <class U>
        friend ofstream& operator<<(ofstream&, List<U>);
        template <class U>
        friend ifstream& operator>>(ifstream&, List<U>&);
        
        inline bool operator==(const List &);
        
    protected:
        // Protected Declarations
};
/*
Operator>> overloading
2021-11-06
*/
template <class T>
inline bool List<T>::operator==(const List<T> &other)
{
    if(this->length != other.length)
    {
        return false;
    }
    else
    {
        for(unsigned int i = 0; i < this->length;i++)
        {
            if(this->getElement(i) != other.getElement(i))
            {
                return false;
            }
        }
        return true;
    }
}
/*
Operator>> overloading
2021-11-06
*/
template <class T>
ifstream& operator>>(ifstream &in, List<T> &list)
{
//  long temp;
//  for(int i = 0; i < list.getLength(); i++)
//  {
//      in >> temp;
//      list.setElement(i,temp);
//  }
    
//  long temp;
//  if(list.getLength() == 0)
//  {
//      cout << "in ifstream& operator>>(istream &in," 
//           << " List list), list.getLength() == 0" 
//           << endl;
//  }
//  else if (list.getLength() < 0)
//  {
//      cout << "in ifstream& operator>>(istream &in, List list)," 
//           << " list.getLength() < 0" 
//           << endl;
//  }
//  else
//  {
//      in >> temp;
//      list.setLength(temp);
//      for(int i = 0; i < list.getLength(); i++)
//      {
//          in >> temp;
//          list.setElement(i,temp);
//      }
//  }
    unsigned length_temp;
    T temp;
    in >> length_temp;
    list.setLength(length_temp);
    for(unsigned int i = 0; i < list.getLength(); i++)
    {
        in >> temp;
        list.setElement(i,temp);
    }
    
    return in;
}

/*
Operator<< overloading
2021-11-06
*/
template <class T>
ofstream& operator<<(ofstream &out, List<T> list)
{
    if(list.getLength() == 0)
    {
        cout << "in ofstream& operator<<(ofstream &out, List list),"
             << " list.getLength() == 0" 
             << endl;
    }
    else if (list.getLength() < 0)
    {
        cout << "in ofstream& operator<<(ofstream &out, List list)," 
             << " list.getLength() < 0" 
             << endl;
    }
    else
    {
        for(unsigned int i = 0; i < list.getLength(); i++)
        {
            // must be written like this
            static_cast<ostream&>(out) << list.getElement(i) << " "; 
            //out << list.getElement(i) << " "; << this will get error 
        }
        out << endl;
    }
    return out;
}
template <class T>
istream& operator>>(istream &in, List<T> &list)
{
//  long temp;
//  for(int i = 0; i < list.getLength(); i++)
//  {
//      in >> temp;
//      list.setElement(i,temp);
//  }
    
    T temp;
    if(list.getLength() == 0)
    {
        cout << "in istream& operator>>(istream &in," 
             << " List list), list.getLength() == 0" 
             << endl;
    }
    else if (list.getLength() < 0)
    {
        cout << "in istream& operator>>(istream &in, List list)," 
             << " list.getLength() < 0" 
             << endl;
    }
    else
    {
        for(unsigned int i = 0; i < list.getLength(); i++)
        {
            in >> temp;
            list.setElement(i,temp);
        }
    }
    
    return in;
}

/*
Operator<< overloading
2021-11-06
*/
template <class T>
ostream& operator<<(ostream &out, List<T> list)
{
    if(list.getLength() == 0)
    {
        cout << "in ostream& operator<<(ostream &out, List list),"
             << " list.getLength() == 0" 
             << endl;
    }
    else if (list.getLength() < 0)
    {
        cout << "in ostream& operator<<(ostream &out, List list)," 
             << " list.getLength() < 0" 
             << endl;
    }
    else
    {
        for(unsigned int i = 0; i < list.getLength(); i++)
        {
            out << list.getElement(i) << " ";
        }
        out << endl;
    }
    return out;
}

/*
Operator-- overloading
postfix
2021-11-06
*/
template <class T>
List<T> List<T>::operator--(int)
{
    List<T> tmp(*this);
    T tmp_value;
    for(unsigned int i = 0;i < this->length;i++)
    {
        tmp_value = this->getElement(i);
        tmp_value--;
        this->setElement(i, tmp_value);
    }
    return tmp;
}

/*
Operator-- overloading
prefix
2021-11-06
*/
template <class T>
List<T> List<T>::operator--()
{
    T tmp_value;
    for(unsigned int i = 0;i < this->length;i++)
    {
        tmp_value = this->getElement(i);
        this->setElement(i, --tmp_value);
    }
    return *this;
}


/*
Operator++ overloading
postfix
2021-11-06
*/
template <class T>
List<T> List<T>::operator++(int)
{
    List<T> tmp(*this);
    T tmp_value;
    for(unsigned int i = 0;i < this->length;i++)
    {
        tmp_value = this->getElement(i);
        tmp_value++;
        this->setElement(i, tmp_value);
    }
    return tmp;
}

/*
Operator++ overloading
prefix
2021-11-06
*/
template <class T>
List<T> List<T>::operator++()
{
    T tmp_value;
    for(unsigned int i = 0;i < this->length;i++)
    {
        tmp_value = this->getElement(i);
        this->setElement(i, ++tmp_value);
    }
    return *this;
}


/*
Operator+= overloading
2021-11-06
*/
template <class T>
List<T>& List<T>::operator+=(const List<T> &other)
{
    unsigned loop = this->length < other.length ? this->length : other.length;
    for(unsigned int i = 0;i < loop;i++)
    {
        this->setElement(i, this->getElement(i)+other.getElement(i));
    }
    return *this;
}

/*
Operator+ overloading
2021-11-06
*/
template <class T>
List<T> List<T>::operator+(const List<T> &other)
{
    unsigned loop = this->length < other.length ? this->length : other.length;
    List<T> lt(loop);
    for(unsigned i = 0;i < loop;i++)
    {
        lt.setElement(i, this->getElement(i)+other.getElement(i));
    }
    return lt;
}

/*
Returns the value of _Node[pos] if pos is legal.
If pos is illegal, prints an error message and returns -99999.

2021-11-06
*/
template <class T>
T List<T>::getElement(unsigned int pos) const
{
    unsigned int length;
    length = this->getLength();
    if( (pos >= length) || (pos < 0) )
    {
        cout << "(List::getElement Error) pos " 
             << pos 
             << " is illegal " 
             << endl;
             
//      assert( pos < length );
//      assert( pos >= 0 );
        assert( (pos < length) && (pos >= 0) );
        //return -99999;
    }
    return this->getElement_Node(pos);
}

/*
Assigns val to _Node[pos].
The function returns 1 if pos is legal; otherwise prints an error
message and returns 0.
Notice that there is a need to add a respective member function
to the base Node class.

2021-11-06
*/
template <class T>
int List<T>::setElement(unsigned int pos, T val)
{
    unsigned int length;
    length = this->getLength();
    if( (pos >= length) || (pos < 0) )
    {   // if pos over the length or pos is negtive
        cout << "(List::setElement Error) pos "
             << pos 
             << " is illegal " 
             << endl;
        return 0;
    }
    else
    {
        this->setElement_Node(pos,val);
        return 1;
    }
}

/*
If the original length is 0, the function sets a new length, uses
reCreate() to allocates an array of size length to _Node,
then returns 1.

If the original length is not 0, the function prints an error
message then returns 0.
2021-11-06
*/
template <class T>
int List<T>::setLength(unsigned int newLength)
{
    if(this->length == 0)
    {
        this->set_Node(this->reCreate(newLength));
        this->length = newLength;
        return 1;
    }
    else
    {
        cout << "(List::setLength) original length is not 0" 
             << endl; 
        return 0;
    }
}

 
/*
The function returns the value of length.
2021-11-06
*/
template <class T>
unsigned int List<T>::getLength() const
{
    return this->length;
}
/*
Assignment operator that assigns other to *this.
2021-11-06
*/
template <class T>
List<T>& List<T>::operator=(const List<T> &other)
{
//  this->set_Node(other.get_Node() );
    if(this != &other)  
    {
        this->delete_Node(); //array may not be NULL
        this->length = other.length;
        
        if(length > 0)
        {
            this->reCreate(length); 
            for(unsigned int i = 0; i < this->getLength();i++)
            {
                this->setElement(i, other.getElement(i));
            }
        }
        else
        {
            cout << "List::operator=(const List& other) "
                 << "length is not a positive value" 
                 << endl; 
            this->reCreate(length);
        }
    }// if the same one, do nothing

    return *this;   
}

/*
Define the constructor.
It must inherits and calls Node() to initialze _Node
Initializes length as 0
2021-11-06
*/
template <class T>
List<T>::List()
{
    //printf("call List()\n");
    this->length = 0;
}

/*
It must inherits and calls Node(_length) to initailize _Node
Initializes length as _length
2021-11-06
*/
template <class T>
List<T>::List(unsigned int _length) : Node<T>(_length)
{
    //printf("call List(unsigned int _length)\n");
    if(_length == 0)
    {
        this->length = 0;
    }
    else
    {
        this->length = _length;
    }
}

/*
The copy constructor that copies other to *this
2021-11-06
*/
template <class T>
List<T>::List(const List<T> &other)
{
    //printf("call List(const List &other)\n");
    length = other.length;
    if(length > 0)
    {
        this->reCreate(length);
        for(unsigned int i = 0;i < this->getLength();i++)
        {
            this->setElement(i, other.getElement(i));   
        }   
    }
    else
    {
        this->reCreate(length);
        cout << "(List::List(const List &other)) length is <= 0" << endl; 
    } 
} 
/*
Define the destructor.
Implicitly calls ~Node()
Resets length to 0
2021-11-06
*/
template <class T>
List<T>::~List()
{
    //printf("call ~List()\n");
    this->length = 0;
}


#endif
