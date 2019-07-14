#include <iostream>
#include <cstring>

class Cover{
 public:
    Cover() default //constructor, sets m_hard to false
    Cover(bool hard) //parametrized constructor, sets m_hard to hard
    operator<< //overload, outputs m_hard to the calling object(cout,etc…)
    operator>> //overload, assigns m_hard a 0/1 value from calling object input(cin,etc…)
    GetValue() //method, returns m_hard by value and does not modify calling object
 private:
    bool m_hard;
};
class Client{
 public:
    Client() default //constructor, leaves m_name uninitialized
    Client(const char* name) //parametrized constructor, copies c-string name to m_name
    Client(const Client& other);// copy constructor, deep-copies data
    ~Client() //destructor, deallocates memory as necessary
    operator= //overload, deep-copies data and returns reference to calling object
    operator<< //overload, outputs m_name to the calling object(cout,etc…)
    operator>>  //overload, grabs and copies to m_name input from calling object(cin,etc…)
    GetName()   // method, returns m_name by address and does not modify calling object
 private:
    char* m_name;
};

class Book
{   
    friend std::
    private:
        char * m_title;
        Cover m_cover;
        const Client & m_client ;// unsure about this one
        const size_t m_serial;
        static size_t count;

    public:
        Book(); //default ctor
        Book(name, cover, client, serial); //parameterized ctor, come back to this
        Book(const Book & other);
        ~Book();
        Book & operator=(const Book & rhs);
        const Cover & getCover() const;
        void setCover(const Cover & cover);
        const Client & getClient() const;
        void setClient(Client * client);
        void serialize(std::ostream & os) const;
};