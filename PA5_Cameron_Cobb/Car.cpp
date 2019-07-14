//Cameron Cobb
//CS202

#include <iostream>
#include <cstring>
#include "Vehicle.h"
#include "Car.h"



//Default constructor
Car::Car():
    m_throttle(0)
{
    std::cout << "Car #" << this->getVin() << ": Default-ctor" << std::endl;
}

//Paramatized constructor
Car::Car(const char* plates, const int vin, const float* lla):
    Vehicle(vin, lla)
{
    this->setPlates(plates);
    std::cout << "Car #" << this->getVin() << ": Parametized-ctor" << std::endl;
}

//Copy constructor
Car::Car(const Car &obj):
    Vehicle(obj)
{
    setPlates(obj.getPlates());
    std::cout << "Car #" << this->getVin() << ": Copy-ctor" << std::endl;
}

//Deconstructor
Car::~Car()
{
    std::cout << "Car #" << this->getVin() << ": Dtor" << std::endl;
}

// Setters
void Car::setThrottle(const int throttle)
{
    m_throttle = throttle;
}

void Car::setPlates(const char* plates)
{
    strcpy(m_plates, plates); // copy the strings
}

//getters
const int Car::getThrottle() const { return m_throttle; }
const char* Car::getPlates() const { return m_plates; }
const int Car::getIdgen() { return Vehicle::getIdgen(); }

// Other Methods
void Car::move(const float* lla)
{
    std::cout << "Car #" << this->getVin()
    << ": DRIVE to destination, with throttle @ 75 "
    << std::endl;

    this->drive( 75 );
    this->setLLA( lla );
}

void Car::drive(const int throttle)
{
    this->setThrottle(throttle);
}

std::ostream & operator<< (std::ostream & os, const Car & car)
{
    const float *lla = car.getLLA();
    
    os << "Car #"
    << car.getVin() << " Plates: "
    << car.getPlates() << ", Throttle: "
    << car.getThrottle() << " @ ["
    << *lla << ", ";
    ++lla;
    os << *lla << ", ";
    ++lla;
    os << *lla << ']';

    return os;
}