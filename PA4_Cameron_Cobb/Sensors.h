#ifndef SENSOR_H
#define SENSOR_H

class Sensor
{
public:
    // Default Constructor
    Sensor();

    // Parametized Constructor
    Sensor(char* type);

    // Setters
    void setType(char* type);
    void setExtracost();

    // Getters
    char* getType();
    float getExtracost();

    // Overload Operators
    bool operator== (Sensor *sensorRef); // Checks if two sensors are equal

private:
    char m_type[256];
    float m_extracost;
    static int gps_cnt;
    static int camera_cnt;
    static int lidar_cnt;
    static int radar_cnt;
};


#endif