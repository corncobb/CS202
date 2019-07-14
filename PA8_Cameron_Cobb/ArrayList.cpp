//Cameron Cobb
//4/16/2019
//Array list implemetation

#include <iostream>
#include "ArrayList.h"
#include <cstring>



//Default Ctor
ArrayList::ArrayList()
{
	m_array = NULL;
	m_size = 0;
	m_maxsize = 0;
	std::cout << "ArrayList default ctor test. VALUES: \n " << this << std::endl; 
}								    		

//parameterized Ctor
ArrayList::ArrayList(size_t count, const DataType & value): m_size(count), m_maxsize(count)
{
	size_t i = 0;
	m_array = NULL;
	m_array = new DataType[m_maxsize];
	
	while (i != m_maxsize){
		m_array[i] = value;
		i++;
	}
	
	std::cout << "ArrayList parameterized ctor test. VALUES: \n " << this << std::endl; 

}										

//Copy Ctor
ArrayList::ArrayList(const ArrayList & other): m_size(other.m_size), m_maxsize(other.m_maxsize)
{
	size_t i = 0;
	m_array = NULL;
	m_array = new DataType[m_size];
	while (i != m_maxsize){
		m_array[i] = other.m_array[i];
		i++;
	}
	
	std::cout << "ArrayList copy ctor test. VALUES: \n " << this << std::endl; 
}	


//Destructor				    
ArrayList::~ArrayList()
{
	clear();
	
	std::cout << "Array dtor test, he's dead Jim" << std::endl; 
	
}							    		


// Other methods
DataType * ArrayList::front()
{
	std::cout << "ArrayList front function test." << std::endl; 
	
	if(m_array != NULL){
		return &m_array[0];
	}else{
		std::cout << "List is empty" << std::endl;
		return NULL;
	}
	
}								     	

DataType * ArrayList::back()
{
	std::cout << "ArrayList back function test." << std::endl; 
	if(m_array != NULL){
		return &m_array[m_size];
	}else{
		std::cout << "List is empty" << std::endl;
		return NULL;
	}
}							            
	
DataType * ArrayList::find(const DataType & target, DataType * & previous)
{
	std::cout << "Finding values" << std::endl;
	DataType* arrayPtr = m_array;
    if (arrayPtr != NULL)
    {
		size_t i = 0;
        while (i < m_size)
        {
            if (*arrayPtr == target)
            {
                arrayPtr--;
                if (arrayPtr != NULL)
                {
                    previous = arrayPtr;
                }
                else
                {
                    previous = NULL;
                }
                arrayPtr++;
                return arrayPtr;
            }
            i++;
            arrayPtr++;
        }
    }
    previous = NULL;
    return NULL;
}										
	
DataType * ArrayList::insertAfter(const DataType & target, const DataType & value)
{
	std::cout << "inserting after" << std::endl;
	size_t i = 0;
	DataType *curr = m_array;
	while(curr != NULL){
		if (target == *curr){
			for (size_t k = m_size - 1; k > i; k--){
					m_array[k] = m_array[k - 1];
				}
				m_array[i + 1] = value;
				*curr = m_array[i + 1];
				return curr; 
			}
			i++;
			curr++;
	}
	if (empty()){
		m_array[0] = value;
        *curr = m_array[0];
        m_size++;
        return curr;
	}
	return NULL;
	
	
}
	 
DataType * ArrayList::insertBefore(const DataType & target, const DataType & value)
{
	std::cout << "inserting before" << std::endl;
	size_t i = 0;
	DataType *curr = m_array;
	while(curr != NULL){
		if (target == *curr){
			for (size_t k = m_size - 1; k > i; k--){
					m_array[k] = m_array[k - 1];
				}
				m_array[i] = value;
				return curr; 
			}
			i++;
			curr++;
	}
	if (empty()){
		m_array[0] = value;
        *curr = m_array[0];
        m_size++;
        return curr;
	}
	return NULL;
	
	
}

DataType * ArrayList::erase(const DataType & target)
{
	std::cout << "erasing value target" << std::endl;
	size_t counter = 0;
	DataType *curr = m_array;
	while(curr != NULL){
		if (target == *curr){
			for(size_t i = counter; i < m_size; i++){
				m_array[i-1] = m_array[i];
			}
			if(counter == 0){
				return m_array;
			}
			else{
				return curr--;
			}
		}
		curr++;
		counter++;
	}
	return NULL;
	
}		


//Operators
ArrayList & ArrayList::operator= (const ArrayList & rhs)
{
	if (this != &rhs) {
        m_maxsize = rhs.m_maxsize;
		m_size = rhs.m_size;
        size_t i = 0;
		while (i != m_maxsize){
			m_array[i] = rhs.m_array[i];
			i++;
		}
    } else {
       return *this;
    }

    return *this;
    std::cout << "ArrayList assignment operator test. VALUES: \n " << this << std::endl; 
}											


std::ostream & operator<<(std::ostream & os, const ArrayList & arrayList)
{
	size_t i = 0;
	while (i < arrayList.m_size){
		os << '{' << i << ',' << arrayList.m_array[i] << "} " << std::endl;
		i++;
	}
	return os;
}
	
DataType & ArrayList::operator[] (size_t position)
{
	
	return m_array[position];
}													

// More methods
size_t ArrayList::size() const
{
	return (m_size);
}													
bool ArrayList::empty() const
{
	bool truth = 0;
	if (m_array == NULL){
		truth = 1;
	}
	return truth;
	
}														
void ArrayList::clear()
{
	if (m_array != NULL){
        delete [] m_array;
        m_array = NULL;
    }
    m_size = 0;
    m_maxsize = 0;
}														

void ArrayList::resize(size_t count)
{
	size_t i = 0;
	DataType *placeHolder = new DataType[m_size];
	if(m_array != NULL){
		while (i < m_size){
			placeHolder[i] = m_array[i];
			i++;	
		}
	}else{
		while (i < m_size){
			placeHolder = NULL;
			placeHolder++;
			i++;
		}
	}
	delete [] m_array;
	m_array = NULL;
	

	m_maxsize = m_maxsize + count;
    m_array = new DataType[m_maxsize];
    
	i = 0;
	while (i < m_maxsize){
		if (m_size < m_maxsize && i > m_size){
			m_array = 0;
		}
		
		m_array = placeHolder;
		placeHolder++;
		m_array++;
		i++;
	}
}		               					

