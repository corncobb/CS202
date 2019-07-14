
#include <iostream>
#include <cstring>

using namespace std;

const char* DEFAULT_TITLE = "hunter"; 
const char* DEFAULT_NAME = ""; 

class DigestiveSystem{
    public:
    DigestiveSystem(): m_carnivore(false){}//default const
    DigestiveSystem(bool carnivore): m_carnivore(carnivore){}
    DigestiveSystem & operator=(const DigestiveSystem &){}//do-nothing assignment
    bool getCarnivore() const{return m_carnivore;} //const getter method
    friend std::ostream & operator<<(std::ostream & os, const DigestiveSystem & digest)
    {
        os << (digest.m_carnivore ? "carnivore" : "herbivore") << endl;
        return os;
    }
    private:
    const bool m_carnivore; //constant member value
};

class Animal{
    private:
        char m_name[5];
        const DigestiveSystem m_digest;
        const size_t m_tag;
        static size_t s_count;

        bool setName(const char* name) const;
        char * getName() const;
        const DigestiveSystem & getDigest() const;

    public:
        Animal(const DigestiveSystem & digest, const char * name = DEFAULT_NAME);
        Animal(const Animal & other);
        Animal & operator=(Animal & other);
        size_t getTag() const;

        void feed(bool food_type) const;
};

size_t Animal::s_count=0;

Animal::Animal(const DigestiveSystem & digest, const char * name):m_digest(digest), m_tag(s_count++){
    setName(name);
}

Animal::Animal(const Animal & other):m_digest(other.m_digest), m_tag(s_count++){
    setName(other.m_name);
}

Animal & Animal::operator=(Animal & other){
    setName(other.m_name);
    return *this;
}

size_t Animal::getTag() const{return m_tag;}

const DigestiveSystem & Animal::getDigest() const {return m_digest;}

void Animal::feed(bool food_type) const{
    if(m_digest.getCarnivore() == food_type){
        cout << "Jumps in Joy" << endl;
    }
    else{
        cout << "Turns away" << endl;
    }
}

bool Animal::setName(const char* name) const{
    strcpy(m_name,name);


}

class Lion: public Animal{
    public:

    private:


}

