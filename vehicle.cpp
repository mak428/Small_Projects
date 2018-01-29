#include "vehicle.h"
Vehicle::Vehicle()
{
}

Vehicle::Vehicle(VehicleInfo& info, fuelLevel& fLevel)
{
    m_vehicleInfo = info;
    m_engineOn = false;
    m_currentSpeed = 0;
    m_fuelLevel = fLevel;
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



