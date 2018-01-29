#include "car.h"

Car::Car()
{
}

Car::Car(VehicleInfo& vInfo, fuelLevel& fLevel)
{
    Vehicle::setVehicleInfo(vInfo);
    Vehicle::setFuelLevel(fLevel);
}


state Car::start()
{
    if ((m_currentState == parked) || (m_currentState == stopped) && (Vehicle::getFuelLevel() != empty)) 
    {
        m_engineOn = true;//turns engine on
        return moving;
    }
return stopped;
}
state Car::stop()
{
    if ((m_currentState == moving) || (m_currentState == accelerating))
    {
        m_currentState = deccelerating;
        
(10);
        m_currentState = stopped;
    }
    if (m_currentState == parked)
    {
        m_engineOn = false;//turns engine off
        sleep(2);
        m_currentState = stopped;
    }
    return stopped;
}
void Car::accelerate(int speed)
{
    if (m_currentState == moving)
    {
        m_currentState = accelerating;   
    }
    if (m_currentState == deccelerating)
    {
        sleep(10);
        m_currentState = accelerating;//accelerate
    }

}
void Car::decelerate(int speed)
{
    if ((m_currentState == accelerating) || (m_currentState == moving))
    {
        m_currentState = deccelerating;//deccelerate
    }


}
void Car::addFuel()
{
    if (Vehicle::getFuelLevel() < half)
    {
        Vehicle::setFuelLevel(full);//fill the fuel level to full
    }
}



