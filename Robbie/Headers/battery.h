//
//  Battery.h
//  RobbieRobot
//
//  Created by Jesus Serna on 10/4/16.
//  Copyright © 2016 Jesus Serna. All rights reserved.
//

#ifndef Battery_h
#define Battery_h

#include "robotPart.h"

class Battery: public RobotPart{
private:
    double Energy;
public:
    Battery(string name,int PartNumber, ComponentType type, double weight, double price, string description, double energy):
    RobotPart(name,PartNumber,type,weight,price,description),Energy(energy){};
    
    double get_energy();
};

#endif /* Battery_h */
