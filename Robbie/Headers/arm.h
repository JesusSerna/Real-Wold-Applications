//
//  Arm.h
//  RobbieRobot
//
//  Created by Jesus Serna on 10/4/16.
//  Copyright © 2016 Jesus Serna. All rights reserved.
//

#ifndef Arm_h
#define Arm_h

#include "robotPart.h"
#include <iostream>

class Arm : public RobotPart{
public:
    Arm(string name,int PartNumber, ComponentType type, double weight, double price, string description, double power, double maxSpeed):
    RobotPart(name,PartNumber,type,weight,price,description), PowerRate(power), MaxSpeed(maxSpeed){};
    
    
    double get_max_speed();
    double get_power_rate();
    double get_power_cosumed(double speed);

private:
    double PowerRate;
    double MaxSpeed;
    double PowerCosumed;
};

#endif /* Arm_h */
