/****************************
[file name]--------------
node.h
[editor]----
yu-wen Wang (vincent08tw@gmail.com) (vincent08tw@yahoo.com.tw)
[create date]---
2021-11-06 
[last edit]---
2021-11-06 
****************************/ 


#ifndef NODE_H
#define NODE_H

#include <assert.h>
using namespace std;

template <class T>
class Node
{
    private:
        // Private section
        // Create a template class called Node with a 
        // template data type T, which has one data member: 
        T *_Node; 
    public:
        // Public Declarations

        Node(); //constructor
        Node(unsigned int _length); //constructor
        ~Node(); //destructor
        
        // Assignment operator
        Node<T>& operator=(const Node<T>&);
        
        void set_Node(T* other);
        T* get_Node(void) const;
        /*
            Allocates for _Node a long array of size _length
            Returns the address of newly allocated _Node
        */
        // long* reCreate(unsigned int _length);
        T* reCreate(unsigned int _length);
        void setElement_Node(unsigned int pos, T val);
        T getElement_Node(unsigned int pos) const;
        
        void delete_Node();

        
    protected:
        // Protected Declarations
};

template <class T>
void Node<T>::delete_Node()
{
    delete [] this->_Node;
}

template <class T>
T Node<T>::getElement_Node(unsigned int pos) const
{
    return this->_Node[pos];
}

/*
Assigns val to _Node[pos].
2021-11-06
*/
template <class T>
void Node<T>::setElement_Node(unsigned int pos, T val)
{
    this->_Node[pos] = val;
}
/*
Set and get function
2021-11-06
*/
template <class T>
void Node<T>::set_Node(T* other)
{
    this->_Node = other;
}
template <class T>
T* Node<T>::get_Node(void) const
{
    return this->_Node;
}

/*
Define the assignment operator.
2021-11-06
*/
template <class T>
Node<T>& Node<T>::operator=(const Node &node)
{
    this->set_Node(node.get_Node() );
    return *this;   
}

/*
Define the constructor.
Initializes _Node as NULL
2021-11-06
*/
template <class T>
Node<T>::Node()
{
    //printf("call Node()\n");
    _Node = NULL;
}
/*
Constructs _Node as an integer array of size _length
2021-11-06
*/
template <class T>
Node<T>::Node(unsigned int _length)
{
    //printf("call Node(unsigned int _length)\n");
    if(_length == 0)
    {
        _Node = NULL;
    }
    else
    {
        _Node = new T [_length];
        assert(_Node != NULL);
    }
}
/*
Define the destructor.
2021-11-06
*/
template <class T>
Node<T>::~Node()
{
    //printf("call ~Node()\n");
    if(_Node == NULL)
    {
        delete _Node;
    }
    else
    {
        delete[] _Node;
    }   
}
/*
Allocates for _Node a long array of size _length
Returns the address of newly allocated _Node
2021-11-06
*/
template <class T>
T* Node<T>::reCreate(unsigned int _length)
{
    if(_length == 0)
    {
        _Node = NULL;
    }
    else if(_length > 0)
    {
        _Node = new T [_length];
        assert(_Node != NULL);
    }
    else
    {
        _Node = NULL;
        cout << "in (Node::reCreate(unsigned int _length))," 
             << " you set a negtive value in _length..." 
             << endl;
    }
    return _Node;
}

#endif
