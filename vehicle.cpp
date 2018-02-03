#include "vehicle.h"
Vehicle::Vehicle()
{
    m_engineOn = false;
    m_currentSpeed = 0;
    m_currentState = stopped;
}

Vehicle::Vehicle(VehicleInfo& info, fuelLevel& fLevel)
{
    m_vehicleInfo = info;
    m_engineOn = false;
    m_currentSpeed = 0;
    m_fuelLevel = fLevel;
    m_currentState = stopped;
}

Vehicle::~Vehicle()
{
}
void Vehicle::setVehicleInfo(VehicleInfo& vInfo)
{
    m_vehicleInfo = vInfo;   
}
void Vehicle::setFuelLevel(fuelLevel fLevel)
{
    m_fuelLevel = fLevel;
}
VehicleInfo  Vehicle::getVehicleInfo() const
{
    return m_vehicleInfo;
}
fuelLevel Vehicle::getFuelLevel() const
{
    return m_fuelLevel;
}
void Vehicle::setcurrentSpeed(int speed)
{
    m_currentSpeed = speed;
}
int Vehicle::getcurrentSpeed() const
{
    return m_currentSpeed;
}


