//Cameron Cobb
//CS202
//3/13/2019

//Just want to say that wow, this was kind of a pain and I am glad that it is almost spring breakkkkkk


#include <iostream>
#include <cstring>
#include "Vehicle.h"

// Default Constructor
Vehicle::Vehicle()
{
    std::cout << "Vehicle: Default-ctor" << std::endl;
}

// Paramatized Constructor
Vehicle::Vehicle(const float* lla)
{
    this->SetLLA(lla);
    std::cout << "Vehicle: Parametrized-ctor" << std::endl;
}

// Copy Constructor
Vehicle::Vehicle(const Vehicle& obj)
{
    this->SetLLA(obj.getLLA());
    std::cout << "Vehicle: Copy-ctor" << std::endl;
}

// Deconstructor
Vehicle::~Vehicle()
{
    std::cout << "Vehicle: Dtor" << std::endl;
}

//setters
void Vehicle::SetLLA(const float *lla)
{
    m_lla[0] = lla[0];
    m_lla[1] = lla[1];
    m_lla[2] = lla[2];
}

//getters
const float *Vehicle::getLLA() const { return this->m_lla; }

/*
//Other Methods
int Vehicle::availibleVin(const int vin)
{
    // First looks for deleted vins
    for (int i = 0; i < 256; i++)
    {
        if (s_deleted_vins[i])
        {
            int availible_vin = s_deleted_vins[i];
            s_deleted_vins[i] = 0;
            return availible_vin;
        }
    }

    // Then defers to idgen
    if (vin > s_idgen)
    {
        return vin;
    }
    else
    {
        s_idgen++;
        return s_idgen;
    }
}
*/
std::ostream & operator<< (std::ostream & os, const Vehicle & vehicle)
{
    vehicle.serialize(os);
    return os;
}

void Vehicle::operator= (const Vehicle& other)
{
    this->SetLLA(other.getLLA());
    std::cout << "Vehicle: Assignment" << std::endl;
}

void Vehicle::serialize(std::ostream& os) const
{
    const float *ptr = this->getLLA();
    os << "Vehicle @ [" << *ptr << ", ";
    ptr++;
    os << *ptr << ", ";
    ptr++;
    os << *ptr << ']';
}