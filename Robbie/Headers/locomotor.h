//
//  Locomotor.h
//  RobbieRobot
//
//  Created by Jesus Serna on 10/4/16.
//  Copyright © 2016 Jesus Serna. All rights reserved.
//

#ifndef Locomotor_h
#define Locomotor_h

#include "robotPart.h"

class Locomotor: public RobotPart{
public:
    Locomotor(string name, int PartNumber, ComponentType type, double weight, double price, string description, double power, double maxSpeed):
        RobotPart(name,PartNumber,type,weight,price,description), PowerRate(power), MaxSpeed(maxSpeed){}
    
    double get_max_speed();
    double get_power_rate();
    double get_power_cosumed(double Speed);
private:
    double MaxSpeed;
    double PowerRate;
    double PowerCosumed;
};

#endif /* Locomotor_h */
