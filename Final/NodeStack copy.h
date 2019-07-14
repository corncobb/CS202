#include <iostream>
#include <cstring>

class Node{
	 
	friend class Stack<T>;
	    
  public: 
	Node(): m_next(NULL){;} 
	Node(const T & data, Node<T> * next = NULL):m_next(next), m_data(data){;}
	T & data(){return m_data;} 
	const T & data() const{return m_data;} 
  private: 
	Node * m_next; 
	T m_data;                                   
}; 

template <typename T>
class Stack{
  friend std::ostream & operator<< <> (std::ostream & os,
                   const Stack<T> & Stack);
  public:
  //Default Ctor, initializes m_top to NULL 							(1) 
	Stack():m_top(NULL){;}
	
  //Parameterized ctor, initializes Stack with providied values		(2)  
	Stack(size_t count, const T & value=T()){
		if(count >= 1){
			size_t i = 0;
			m_top = NULL;
			while(i < count){
				push(value);
				i++;
			}
		}else{
			std::cout << "INVALID COUNT NUMBER, Stack INITIAILZED WITH "
					  << "NULL VALUES." << std::endl;
			m_top = NULL;
		}
	}

template <class T>
void Stack::push(const T & value){
    if(!m_top){
        m_top = new Node<T>(value);
    }
    else{
        Node<T> * tmp = new Node<T>(value);
        tmp->m_next = m_top;
        m_top = tmp;
        tmp = NULL;
    }
}

template <class T>
void Stack::push(const T & value){
    if(!m_top){
        m_top = new Note<T>(value);
    }else{
        Node<T> * tmp = new Node<T>(value);
        tmp->m_next = m_top;
        m_top = tmp;
        tmp = NULL;
    }
}

template <class T>
void Stack::pop(){
    if(m_top){
        Node<T> * del = m_top;
        m_top = m_top->m_next;
        delete del;
        del = NULL;
    }
}

template <class T>
void Stack::pop(){
    if(m_top){
        Node<T> * del = m_top;
        m_top = m_top->m_next;
        delete del;
        del = NULL;
    }
}

template <class T>
void Stack::serialize(std::ostream & os){
    Node<T> * current = m_top;
    size_t count = 0;
    while(current){
        os << "Node " << count << " has " << current->m_date << std::endl;
        current = current->m_next;
        count++;
    }
}

Stack & Stack::operator<<(std::ostream & os, const Stack & rhs){
    rhs.serialize(os);
    return *this;
}