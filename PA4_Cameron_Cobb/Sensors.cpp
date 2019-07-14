#include "Sensors.h"
#include "Stringlib.h"

// Default Constructor
Sensor::Sensor()
{
    setType("none");
    setExtracost();
}

// Parametized Constructor
Sensor::Sensor(char* type)
{
    myStringCopy(m_type, type);
    setExtracost();
}

// Setters
void Sensor::setType(char* type)
{
    myStringCopy(m_type, type);
    if (myStringCompare(m_type, "gps") == 0)
    {
        gps_cnt++;
    }
    else if (myStringCompare(m_type, "camera") == 0)
    {
        camera_cnt++;
    }
    else if (myStringCompare(m_type, "lidar") == 0)
    {
        lidar_cnt++;
    }
    else if (myStringCompare(m_type, "radar") == 0)
    {
        radar_cnt++;
    }
}

void Sensor::setExtracost()
{
    if (myStringCompare(m_type, "gps") == 0)
    {
        m_extracost = 5.0;
    }
    else if (myStringCompare(m_type, "camera") == 0)
    {
        m_extracost = 10.0;
    }
    else if (myStringCompare(m_type, "lidar") == 0)
    {
        m_extracost = 15.0;
    }
    else if (myStringCompare(m_type, "radar") == 0)
    {
        m_extracost = 20.0;
    }
    else if (myStringCompare(m_type, "none") == 0)
    {
        m_extracost = 0.0;
    }
}

// Getters
char* Sensor::getType()
{
    return m_type;
}

float Sensor::getExtracost()
{
    return m_extracost;
}

// Overload Operators
bool Sensor::operator== (Sensor *sensorRef)
{
    bool result = 1;
    char *sensor_one_type = this->getType();
    char *sensor_two_type = sensorRef->getType();

    while((*sensor_one_type != '\0') && (*sensor_two_type != '\0'))
    {
        if (*sensor_one_type != *sensor_two_type)
        {
            result = 0;
            break;
        }

        sensor_one_type++, sensor_two_type++;
    }
    
    return result;
}