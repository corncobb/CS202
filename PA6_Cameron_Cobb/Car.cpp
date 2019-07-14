//Cameron Cobb
//CS202
//3/13/2019

#include <iostream>
#include <cstring>
#include "Vehicle.h"
#include "Car.h"



//Default constructor
Car::Car():
    m_throttle(0)
{
    std::cout << "Car: Default-ctor" << std::endl;
}

//Paramatized constructor
Car::Car(const float* lla):
    Vehicle(lla)
{
    std::cout << "Car: Parametized-ctor" << std::endl;
}

//Copy constructor
Car::Car(const Car &obj):
    Vehicle(obj)
{
    std::cout << "Car: Copy-ctor" << std::endl;
}

//Deconstructor
Car::~Car()
{
    std::cout << "Car: Dtor" << std::endl;
}

// Setters
void Car::setThrottle(const int throttle)
{
    m_throttle = throttle;
}

//getters
const int Car::getThrottle() const { return m_throttle; }

// Other Methods
void Car::Move(const float* lla)
{
    
    std::cout << "Car: DRIVE to destination, with throttle @ 75 " << std::endl;

    this->drive( 75 );
    this->SetLLA( lla );
}

void Car::drive(const int throttle)
{
    this->setThrottle(throttle);
}

void Car::operator=(const Car &other)
{
    std::cout << "Car: Assignment" << std::endl;
    this->SetLLA(other.getLLA());
    this->setThrottle(other.getThrottle());
}

//had a little bit of help with this one from a friend
void Car::serialize(std::ostream& os) const
{
    const float *ptr = this->getLLA();
    std::cout << "Car: Throttle: " << this->getThrottle()
    << " @ [" << *ptr << ", ";
    ptr++;
    os << *ptr << ", ";
    ptr++;
    os << *ptr << ']';
}