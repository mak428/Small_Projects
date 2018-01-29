#include <iostream>
#include <string>
#include "vehicle.h"
#include "car.h"
using std::cout;

int main(void)
{
    string   year = "1998";
    string   make = "Acura";
    string   model = "3.2 TL";
    string   licensePlate = "4BNJ2L";

    Build    build
    {
        .m_wheels = 4,
        .m_windows = 4,
        .m_seats = 4,
        .m_doors = 4,
        .m_lights = HID,
        .m_color = "White"
    };

    Capacity capacity  
    {
        .m_maxSpeed = 160,
        .m_fuelCapacity = 14.0,
        .m_engineCapacity = 3.2,
        .m_passengerCapacity = 4
    };

    bool     hasRadar = false;

    VehicleInfo vInfo;
    vInfo.m_year = year;
    vInfo.m_make = make;
    vInfo.m_model = model;
    vInfo.m_licensePlate = licensePlate;
    vInfo.m_build    = build; 
    vInfo.m_capacity = capacity; 
    vInfo.m_hasRadar = hasRadar; 
    Level level = full;

    Car myNewCar(vInfo, level);
    VehicleInfo carInfo = myNewCar.getVehicleInfo();
    cout << "Built a new car: Year = " << carInfo.m_year
         <<  " Make = " << carInfo.m_make
         <<  " Model = " << carInfo.m_model
         <<  " License Plate = " << carInfo.m_licensePlate
         <<  " color = "  << carInfo.m_build.m_color;
    cout << " The car is in " << myNewCar.start() << " state\n";
   
    cout << "Accelerating to 40 mph...\n";
    myNewCar.accelerate(40);
    cout << "Done accelerating.\n";

    cout << "Adding fuel ...\n"; 
    myNewCar.addFuel();
    cout << "Done fueling.\n";

    cout << "Decelerating to 10 mph...\n";
    myNewCar.decelerate(10);
    cout << "Done decelerating.\n";
    
    cout << "Stopping the car...\n";
    ;
    cout << "The car is now in the  " << myNewCar.stop() << " state\n";
 
     

    return 0;
}


