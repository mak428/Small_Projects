#pragma once
#include "vehicle.h"
#include <chrono>
#include <thread>
#include <iostream>
using std::cout;

static void sleep(int sec)
{
      cout << "zzzZZZzzz ...\n";
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
        bool m_engineRunning;    
        

};

