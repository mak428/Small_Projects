#pragma once
#include "vehicle.h"
#include <chrono>
#include <thread>

static void sleep(int sec)
{
    std::this_thread::sleep_for(std::chrono::seconds(sec));
}
class Car:public Vehicle
{
    public:
        Car();
        Car(VehicleInfo& vInfo, fuelLevel& fLevel);
        state start();
        state stop();
        void accelerate(int speed);
        void decelerate(int speed);
        void addFuel();
    private:
        state m_currentState;
        bool m_engineRunning;    
        

};
