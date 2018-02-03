#include "car.h"

Car::Car()
{
    Vehicle::m_currentSpeed = 0;
    Vehicle::m_currentState = stopped;
}

Car::Car(VehicleInfo& vInfo, fuelLevel& fLevel)
{
    Vehicle::m_currentSpeed = 0;
    Vehicle::m_currentState = stopped;
    Vehicle::setVehicleInfo(vInfo);
    Vehicle::setFuelLevel(fLevel);
}


state Car::start()
{
    if ((Vehicle::m_currentState == parked) || (Vehicle::m_currentState == stopped) && (Vehicle::getFuelLevel() != empty)) 
    {
        m_engineOn = true;//turns engine on
        return moving;
    }
return stopped;
}
state Car::stop()
{
    if ((Vehicle::m_currentState == moving) || (Vehicle::m_currentState == accelerating))
    {
        Vehicle::m_currentState = deccelerating;
        
(10);
        Vehicle::m_currentState = stopped;
    }
    if (Vehicle::m_currentState == parked)
    {
        m_engineOn = false;//turns engine off
        sleep(2);
        Vehicle::m_currentState = stopped;
    }
    m_currentSpeed = 0;
    return stopped;
}
void Car::accelerate(int speed)
{
    int speedDifference = speed - m_currentSpeed;
    if (Vehicle::m_currentState == moving || 
        Vehicle::m_currentState == stopped)
    {
        Vehicle::m_currentState = accelerating;
        sleep(10);
        m_currentSpeed = speedDifference + m_currentSpeed;   
    }
    if (Vehicle::m_currentState == deccelerating)
    {
        Vehicle::m_currentState = accelerating;//accelerate
        sleep(10);
        m_currentSpeed = speedDifference + m_currentSpeed;
    }

}
void Car::decelerate(int speed)
{
    int speedDifference = m_currentSpeed - speed; 
    if ((Vehicle::m_currentState == accelerating) || (Vehicle::m_currentState == moving))
    {
        sleep(10);
        Vehicle::m_currentState = deccelerating;//deccelerate
        m_currentSpeed = m_currentSpeed - speedDifference;
    }


}
void Car::addFuel()
{
    if (Vehicle::m_currentState ==  stopped && Vehicle::getFuelLevel() < half)
    {
        Vehicle::setFuelLevel(full);//fill the fuel level to full
    }
}



