//Cameron Cobb
//CS202

#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <cstring>

class Vehicle
{
    protected:
        //Member
        float m_lla[3];

    private:
        //private method
        virtual void serialize(std::ostream & os) const;
    public:

    //Regular CTOR
    Vehicle();

    //Parameterized CTOR
    Vehicle(const float* m_lla);

    //copy constructor
    Vehicle(const Vehicle &obj);

    //deconstructor
    virtual ~Vehicle();

    // Setters
    void SetLLA(const float *lla);

    // Getters
    const float *getLLA() const;

    // Other Methods
    friend std::ostream & operator<<(std::ostream & os, const Vehicle & vehicle);
    void operator=(const Vehicle& other);
    virtual void Move(const float* lla) = 0; //  look at this later

};

#endif