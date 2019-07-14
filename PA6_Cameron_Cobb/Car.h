//Cameron Cobb
//CS202

#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <cstring>
#include "Vehicle.h"

class Car : public Vehicle 
{
private:
    virtual void serialize(std::ostream& os) const override;
    int m_throttle;

protected:
//nothing

public:
    //Default Constructor
    Car();
    
    //Paramatized Constructor
    Car(const float* lla);

    //Copy Constructor
    Car(const Car& obj);

    // Deconstructor
    virtual ~Car() override;

    //Setter
    void setThrottle(const int throttle);
    //void setPlates(const char* plates);
    //static const int getIdgen();

    //Getter
    const int getThrottle() const;

    //other methods
    virtual void Move(const float* lla) override;
    void drive(const int throttle);
    void operator=(const Car &other);

};

#endif