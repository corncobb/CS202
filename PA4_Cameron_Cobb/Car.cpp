#include <iostream>
#include "Car.h"
#include "Sensors.h"
#include "Stringlib.h"

// Default Constructor
Car::Car()
{
    setYear(0000);
    setMake("BLANK");
    setModel("BLANK");
    setBaseprice(0.00);
    setAvailability(0);
}

// Paramatized Constructor
Car::Car(int year, char *make, char *model, float price, bool available)
{
    setYear(year);
    setMake(make);
    setModel(model);
    setBaseprice(price);
    setAvailability(available);
}

// Copy Constructor
Car::Car(const Car & other) :
    m_year(other.m_year) ,
    m_baseprice(other.m_baseprice) ,
    m_available(other.m_available)
{
    setMake(other.m_make);
    setModel(other.m_model);
}

// Setters
void Car::setYear(const int year)
{
    m_year = year;
}

void Car::setMake(const char *make)
{
    myStringCopy(m_make, make);
}

void Car::setModel(const char *model)
{
    myStringCopy(m_model, model);
}

void Car::setBaseprice(float baseprice)
{
    m_baseprice = baseprice;
}

void Car::setAvailability(bool available)
{
    m_available = available;
}

void Car::setOwner(char* owner)
{
    myStringCopy(m_owner, owner);
}

void Car::setSensors(Sensor *sensors)
{
    for(int i = 0; i < 3; i++)
    {
        m_sensors[i].setType(sensors->getType());
        m_sensors[i].setExtracost();
        sensors++;
    }
    
}

// Getters
int     Car::getYear()
{
    return m_year;
}

char*   Car::getMake()
{
    return m_make;
}

char*   Car::getModel()
{
    return m_model;
}

Sensor* Car::getSensors()
{
    return m_sensors;
}

float   Car::getBaseprice()
{
    return m_baseprice;
}

float   Car::getFinalprice()
{
    return m_finalprice;
}

bool    Car::getAvailability()
{
    return m_available;
}

char*   Car::getOwner()
{
    return m_owner;
}


// Other methods
void Car::addLessee()
{

}

void Car::operator+ (char *type)
{
    m_sensors->setType(type);
}

float Car::estimateCost(const int num_of_days)
{

}

void Car::print()
{
    std::cout << getYear() << ' '
            << getMake() << ' '
            << getModel() << ' '
            << "Base price is: $"
            << getBaseprice() << ' '
            << "Final price is: $"
            << getFinalprice() << ' '
            << "Sensors are/is: { ";
            Sensor * ptr = this->getSensors();
            bool hasSensors = 0;
            for(int i = 0; i < 3; i++)
            {
                if (myStringCompare( ptr->getType(), "none") != 0)
                {
                    std::cout << ptr->getType() << ' ';
                    hasSensors = 1;
                }
                ptr++;
            }
            if (!hasSensors)
            {
                std::cout << "none ";
            }
            std::cout << "} , Available: " << std::boolalpha
            << getAvailability() << "\n";
}

void Car::updatePrice(float price)
{

}