//Program 1

#include <iostream>
#include <cstring>

using namespace std;

const char* DEFAULT_TITLE = "hunter"; 
const char* DEFAULT_NAME = ""; 

//Part 1
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
    public:

        Animal(const DigestiveSystem & digest, const char* name = DEFAULT_NAME);
        Animal(const Animal& animal);
        Animal& operator=(Animal& rhs);
        //~Animal();
        const size_t getTag() const;
        char * getName() const;
        DigestiveSystem getDigest() const;
        //For part 1, we do not use "virtual", when we want
        //to use the Lion method instead of the default animal method, then
        //we use virtual. Try with and without to see the different outputs.
        void feed(bool food_type) const;

    private:
        bool setName(const char* name);

        char m_name[5];
        const DigestiveSystem m_digest;
        const size_t m_tag;
        static size_t s_count;

};

size_t Animal::s_count = 0;

Animal::Animal(const DigestiveSystem & digest,const char* name):m_tag(s_count), m_digest(digest){
    setName(name);
    s_count++;
}

//copy constructor
Animal::Animal(const Animal& animal):m_tag(s_count), m_digest(animal.m_digest){
    setName(animal.m_name);
    s_count++;
}

//assignment opperator
Animal& Animal::operator=(Animal& rhs){
    setName(rhs.m_name);
    return *this;
}

const size_t Animal::getTag() const{
    return m_tag;
}

bool Animal::setName(const char* name){
    if(strlen(name) <= 5){
        strcpy(m_name, name);
        if(m_name != ""){
            return true;
        }
    }
    return false;
    
}

char * Animal::getName() const {
    char* tmp = NULL;
    strcpy(tmp, m_name);
    return tmp;
}

const DigestiveSystem Animal::getDigest() const{return m_digest;} 

bool Animal::feed(bool food_type) const{
    if(m_digest.getCarnivore() == food_type){
        cout << "Jump in joy!" << endl;
        return true;
    }
    cout << "Turns away indifferently..." << endl;
    return false;
    
}


//*************************************LION CLASS for part 2********************
class Lion: public Animal
{
    public:
        //
        Lion();
        Lion(char * name, const char * title = DEFAULT_TITLE);
        Lion(const Lion& other);
        bool feed(bool food_type) const;
    
    protected: 
        void setTitle(const char* title);
        const char * getTitle() const;

    private:
        char m_title[255];
    
};
Lion::Lion():Animal(DigestiveSystem(true), DEFAULT_NAME){}
Lion::Lion(char * name, const char * title):Animal(DigestiveSystem(true), name){
    strcpy(m_title, title);
}

Lion::Lion(const Lion& other):Animal(other.getDigest(), other.getName()){
    strcpy(m_title, other.m_title);
}

void Lion::setTitle(const char* title){
    strcpy(m_title, title);
}

const char * Lion::getTitle() const {return m_title;}

bool Lion::feed(bool food_type) const{
    if(food_type){
        cout << "Growl!" << endl;
        return true;
    }
    
    return false;
}


//This is for part 3 of program 1
int main(){
    Animal * zoo[3];

    zoo[0] = new Animal(false, "Pumbo");

    zoo[1] = new Lion("Nalu");

    zoo[2] = new Lion("Samba", "King");

    for(size_t i = 0; i<3; ++i){
        cout << "Grass feeding " << zoo[i]->getTag() << endl;
        zoo[i]->feed(false);   
    }

    for(size_t i = 0; i<3; ++i){
        cout << "Meat feeding " << zoo[i]->getTag() << endl;
        zoo[i]->feed(true);
    }

    return 0;
}

/*
This is the output WITHOUT virtual for "bool feed(bool food_type) const;"
inside of the Animal class (line 41)

Grass feeding 0
Jump in joy!
Grass feeding 1
Turns away indifferently...
Grass feeding 2
Jump in joy!
Meat feeding 0
Turns away indifferently...
Meat feeding 1
Jump in joy!
Meat feeding 2
Turns away indifferently...

This is the output WITH virtual for "bool feed(bool food_type) const;"
inside of the Animal class (line 41)

Grass feeding 0
Jump in joy!
Grass feeding 1
Grass feeding 2
Meat feeding 0
Turns away indifferently...
Meat feeding 1
Growl!
Meat feeding 2
Growl!
*/