#pragma once
#include <string>
using std::string;

enum Lights
{
    halogen = 1,
    LED = 2,
    HID = 3
};

using lights = enum Lights;

enum Level 
{
    empty,
    quarter,
    half,
    threeQuarters,
    full
};

using fuelLevel = enum Level;

enum State  
{
    parked,
    moving,
    accelerating,
    deccelerating,
    stopped
};

using state = enum State;


struct Build
{
    int m_wheels;
    int m_windows;
    int m_seats;
    int m_doors;
    lights m_lights;
    string m_color;

};

struct Capacity
{
    int   m_maxSpeed;
    float m_fuelCapacity;
    float m_engineCapacity;
    int   m_passengerCapacity;
};

struct VehicleInfo
{
    string   m_model;
    string   m_year;
    string   m_make;
    string   m_licensePlate;
    Build    m_build;
    Capacity m_capacity;
    bool     m_hasRadar;
}; 



class Vehicle
{
    public:
         Vehicle();
         Vehicle(VehicleInfo& vInfo, fuelLevel& fLevel);
        ~Vehicle();
         virtual VehicleInfo getVehicleInfo() const;
         virtual fuelLevel getFuelLevel() const;
         virtual int  getcurrentSpeed() const;
    protected:
        virtual state start()=0;
        virtual state stop()=0;
        virtual void accelerate(int speed)=0;
        virtual void decelerate(int speed)=0;
        virtual void addFuel()=0;
        virtual void setVehicleInfo(VehicleInfo& vInfo);
        virtual void setFuelLevel(fuelLevel fLevel);
        virtual void setcurrentSpeed(int speed);  
        bool m_engineOn;
        int m_currentSpeed;
        state m_currentState;
    private:
        VehicleInfo m_vehicleInfo;
        fuelLevel m_fuelLevel;
        

};




    


