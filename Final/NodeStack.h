//This basically comes from project 10...

#ifndef STACK_H_
#define STACK_H_

#include <iostream>

template <typename T> class Stack;
template <typename T> std::ostream & operator<<(std::ostream & os,
                   const Stack<T> & Stack);

template <typename T>
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
	
  //Copy ctor, makes a new Stack with values of provided			(3)            
	Stack(const Stack<T> & other){
		m_top = new Node<T>(other.m_top->data(), NULL);
		Node<T> * othercpy = other.m_top;
		Node<T> * thiscpy = m_top;
		
		while(othercpy->m_next){
			thiscpy->m_next = new Node<T>(othercpy->data(), NULL);
			thiscpy = thiscpy->m_next;
			othercpy = othercpy->m_next;
		}
		
	}
	
  //Dtor, kills Stack object :(										(4)                       
	~Stack(){
		clear();
		std::cout << "Stack DTOR CALLED." << std::endl;
	}                                                 
	
  //Assignment operator, copies one Node Stack object with rhs Stack
  //																	(5)
    Stack &operator=(const Stack<T> & rhs){
		if(this != &rhs){
			m_top = new Node<T>(rhs.m_top->data(), NULL);
			Node<T> * topcpy = m_top;
			Node<T> * rhscpy = rhs.m_top;
			while(rhscpy->m_next != NULL){
				topcpy->m_next = new Node<T>(rhscpy->data(), NULL);
				rhscpy = rhscpy->m_next;
				topcpy = topcpy->m_next;
			}
			return *this;
		}else{
			return *this;
		}
	}
    
  //top function (non-const), returns a usable data value for m_top		(6a) 
	T & top(){
		return m_top->data();
	}                                     
	
  //top function (const), returns a display only data value for m_top 	(6b)
	const T & top() const{
		return m_top->data();
	}                           
	
  //push function, inserts provided value to Stack						(7)   
	void push(const T & value){
		if(!empty()){
			Node<T> * newNode = new Node<T>(value, NULL);
			newNode->m_next = m_top;
			m_top = newNode;
		}else{
			m_top = new Node<T>(value, NULL);
		}
	}          
		
  //pop function, delete top value of Stack								(8) 
	void pop(){
		if(!empty()){
			Node<T> * topNode = m_top;
			m_top = m_top->m_next;
			delete topNode;
			topNode = NULL;
		}else{
			std::cout << "This Stack is empty!" << std::endl;
		}
	}								 
	
  //size function, transverses through Nodes to find sizeof Stack		(9)
	size_t size() const{
		size_t i = 0;
		if(!empty()){
			Node<T> *size = m_top;
			while(size != NULL){
				i++;
				size = size->m_next;
				}
			} 
		return i;
	}                
	
  //empty function, checks if Stack is empty							(10)
	bool empty() const{
		if(m_top == NULL){
			return true;
		}else{
			return false;
		}
	}
	
  //full function, check if the Stack is full							(11)
    bool full() const{return false;}             
    
  //clear function, clears Stack of values								(12)
	void clear(){
		if(!empty()){
			while(!empty()){
				pop();
				if(empty()){
					std::cout << "This Stack is now empty." << std::endl;
				}
			}
		}else{
			std::cout << "This Stack is empty!" << std::endl;
		}
	}                                            
		
  //serialize function, initializes a ostream variable for << operator	(13)
	void serialize(std::ostream & os) const{
		if(!empty()){
			os << '[';
			Node<T> * travel = m_top;
			while(travel != NULL){
				if(travel->m_next == NULL){
					os << travel->data() << ']';
				}else{
					os << travel->data() << ", ";
				}
				travel = travel->m_next;
			}
		}else{
				os << "This Stack is empty!";
			
		}
		os << std::endl; 
	}

  private: 
	Node<T> * m_top;
};	

template<typename T>
std::ostream & operator<< (std::ostream & os,
                   const Stack<T> & Stack){
	Stack.serialize(os); 
	return os;
} 

#endif //STACK_H_
