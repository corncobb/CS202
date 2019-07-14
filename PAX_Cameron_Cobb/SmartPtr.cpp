//Cameron Cobb
//CS202
//4/10/2018
//SmartPtr.cpp

//Included libraries
#include <iostream>
#include "SmartPtr.h"
#include "DataType.h"

//Default constructor
SmartPtr::SmartPtr()
{
    m_ptr = new DataType;
    m_refcount = new size_t;
    *m_refcount = 1;
    std::cout << "SmartPtr Default Constructor for new allocation, RefCount=" << *m_refcount << std::endl;
}

//Parameterized constructor
SmartPtr::SmartPtr(DataType * data)
{
    m_ptr = data;
    m_refcount = new size_t;
    *m_refcount = 0;
    if(m_ptr != NULL){ //checks if data was not NULL
        *m_refcount++;
    }
    std::cout << "SmartPtr Parametrized Constructor from data pointer, RefCount=" << *m_refcount << std::endl;
}

//Copy constructor
SmartPtr::SmartPtr(const SmartPtr & other)
{
    m_ptr = other.m_ptr;
    m_refcount = other.m_refcount;
    m_refcount++;
    
    std::cout << "SmartPtr Copy Constructor, RefCount=" << *m_refcount << std::endl;
}

//Destrictor
SmartPtr::~SmartPtr( )
{
    --(*m_refcount);
    if (!(*m_refcount)) {
        delete m_ptr;
        m_ptr = NULL;
    }

    std::cout << "SmartPtr Destrcutor, RefCount=" << *m_refcount << std::endl;
}

// = operator overload
SmartPtr & SmartPtr::operator=(const SmartPtr & rhs)
{
    --(*m_refcount); 
    ++(*rhs.m_refcount); 

    if (!(*m_refcount)) {
        delete m_ptr;
        m_ptr = NULL;
    }

    m_ptr = rhs.m_ptr;
    m_refcount = rhs.m_refcount;

    return (*this);
}


// * operator overload
DataType & SmartPtr::operator*()
{
    return (*this->m_ptr);
}

// -> operator overload
DataType * SmartPtr::operator->()
{
    return this->m_ptr;
}