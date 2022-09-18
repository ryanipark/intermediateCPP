#ifndef MYLIST_H
#define MYLIST_H

//**************************************
//
// mylist.h
// CSCI 241 Assignment 10
//
// by Ryan Park z1940877
//
//**************************************


#include <iostream>
#include <stdexcept>

// Forward declarations
template <class T>
class mylist;

template <class T>
std::ostream& operator<<(std::ostream&, const mylist<T>&);

template <class T>
struct node
{
    T value;
    node<T>* prev;
    node<T>* next;

    node(const T& value = T(), node<T>* prev = nullptr, node<T>* next = nullptr)
    {
        this->value = value;
        this->prev = prev;
        this->next = next;
    }
};




template <class T>
class mylist
{

    friend std::ostream& operator<< <>(std::ostream&, const mylist<T>&);


private:

    node<T>* l_front;
    node<T>* l_back;
    size_t l_size;

public:
    // Constructor, Copy, Destructor
    mylist();
    ~mylist();
    mylist(const mylist<T>&);

    //Operator Overload
    mylist<T>& operator=(const mylist<T>&);
    bool operator==(const mylist<T>&) const;
    bool operator<(const mylist<T>& rhs) const;

    // Utility
    void clear();
    bool empty() const;
    void clone(const mylist<T>&);
    void push_front(const T&);
    void push_back(const T&);
    void pop_front();
    void pop_back();

    // Get
    size_t size() const;
    const T& front() const;
    T& front();
    const T& back() const;
    T& back();



};


/* Default contructor
 *
 *@param none
 *@return none
 ************************/
template <class T>
mylist<T>::mylist()
{
    l_front = nullptr;
    l_back = nullptr;
    l_size = 0;
}

/* Copy contructor
 *
 *@param refrence to const obj
 *@return none
 ************************/
template <class T>
mylist<T>::mylist(const mylist<T>& x)
{
    l_front = l_back = nullptr;
    l_size = 0;
    clone(x);
}



/* Destructor
 *
 *@param none
 *@return none
 ************************/
template <class T>
mylist<T>::~mylist()
{
    clear();
}

/* Sets one obj of <T> equal to another
 *
 *@param refrence to const mylist<T>
 *@return refrence to mylist<T>
 ************************/
template <class T>
mylist<T>& mylist<T>::operator=(const mylist<T>& x)
{
    if (this != &x)
    {
        clear();

        clone(x);
    }

    return *this;
}

/* Clears doubly linked list
 *
 *@param none
 *@return none
 ************************/
template <class T>
void mylist<T>::clear()
{
    while (!empty())
    {
        pop_back();
    }
}

/* Checks if list is empty
 *
 *@param none
 *@return bool true or false
 ************************/
template <class T>
bool mylist<T>::empty() const
{
    if (l_size == 0 || l_back == nullptr)
        return true;
    else
        return false;
}

/* Returns private l_size
 *
 *@param none
 *@return size_t of list size
 ************************/
template <class T>
size_t mylist<T>::size() const
{
    return l_size;
}

/* Clones objct to passed objct
 *
 *@param refrenct to const objc
 *@return none
 ************************/
template <class T>
void mylist<T>::clone(const mylist<T>& x)
{
    node<T>* ptr;

    for (ptr = x.l_front; ptr != nullptr; ptr = ptr->next)
    {
        push_back(ptr->value);
    }
}

/* Adds T& value to front of list
 *
 *@param refrence to const T
 *@return none
 ************************/
template <class T>
void mylist<T>::push_front(const T& value)
{
    node<T>* new_node = new node<T>(value);

    if (empty())
        l_back = new_node;
    else
        l_front->prev = new_node;

    new_node->next = l_front;
    l_front = new_node;
    l_size++;
}

/* Adds T & value to back of list
 *
 *@param refrence to const T
 *@return none
 ************************/
template <class T>
void mylist<T>::push_back(const T& value)
{
    node<T>* new_node = new node<T>(value);

    if (empty())
        l_front = new_node;
    else
        l_back->next = new_node;

    new_node->prev = l_back;
    l_back = new_node;
    l_size++;
}

/* Takes node off front of list
 *
 *@param none
 *@return none
 ************************/
template <class T>
void mylist<T>::pop_front()
{
    if (empty())
        throw std::underflow_error("underflow exception on call to pop_front()");

    node<T>* delete_node = l_front;
    l_front = l_front->next;

    if (l_front == nullptr)
        l_back = nullptr;
    else
        l_front->prev = nullptr;

    delete delete_node;
    l_size--;
}

/* Takes node off back of list
 *
 *@param none
 *@return none
 ************************/
template <class T>
void mylist<T>::pop_back()
{
    if (empty())
        throw std::underflow_error("underflow exception on call to pop_back()");

    node<T>* delete_node = l_back;
    l_back = l_back->prev;

    if (l_back == nullptr)
        l_front = nullptr;
    else
        l_back->next = nullptr;

    delete delete_node;
    l_size--;
}

/*Returns value at front of list
 *
 *@param none
 *@return refrence to const T
 ************************/
template <class T>
const T& mylist<T>::front() const
{
    if (empty())
        throw std::underflow_error("underflow exception on call to front()");

    return l_front->value;
}

/*Returns value at front of list
 *
 *@param none
 *@return refrence to T
 ************************/
template <class T>
T& mylist<T>::front()
{
    if (empty())
        throw std::underflow_error("underflow exception on call to front()");

    return l_front->value;
}

/*Returns value at back of list
 *
 *@param none
 *@return refrence to const T
 ************************/
template <class T>
const T& mylist<T>::back() const
{
    if (empty())
        throw std::underflow_error("underflow exception on call to back()");

    return l_back->value;
}

/*Returns vale at back of list
 *
 *@param none
 *@return refrence to T
 ************************/
template <class T>
T& mylist<T>::back()
{
    if (empty())
        throw std::underflow_error("underflow exception on call to back()");

    return l_back->value;
}


/* Checks if lhs is less then rhs
 *
 *@param refrence to const mylist<T> rhs
 *@return bool true or false dependant
 ************************/
template <class T>
bool mylist<T>::operator<(const mylist<T>& rhs) const

{
    node<T>* i;
    node<T>* j;

    for (i = this->l_front, j = rhs.l_front; i != nullptr && j != nullptr; i = i->next, j = j->next)
    {
        if (i->value < j->value)
            return true;

        if (i->value > j->value)
            return false;
    }
    
    //Check
    if (i == nullptr && j != nullptr)
        return true;
    else
        return false;
}


/* Checks if two objects are the same
 *
 *@param rhs obj
 *@return boolean true or false dependant
 **************************/
template <class T>
bool mylist<T>::operator==(const mylist<T>& rhs) const
{
    
      if (this->l_size == rhs.size())
      {
          node<T>* i;
          node<T>* j;

          for (i = this->l_front, j = rhs.l_front; i != nullptr && j != nullptr; i = i->next, j = j->next)
          {
              if (i->value != j->value)
                  return false;
          }

          //Check
          if (i == nullptr && j != nullptr)
              return false;
          else if (i != nullptr && j == nullptr)
              return false;
          else
              return true;
      }
      // If size isnt the same there are not the same already
      else
          return false;
}


/* Friend function, os
 * Operator overload
 *
 * @param left and right obj
 * @return refrence to os
 ***********************/
template <class T>
std::ostream& operator<<(std::ostream& os, const mylist<T>& obj)
{

    node<T>* ptr;

    for (ptr = obj.l_front; ptr != nullptr; ptr = ptr->next)
    {
        os << ptr->value << " ";
    }

    return os;

}


#endif
