//
//  Torso.h
//  RobbieRobot
//
//  Created by Jesus Serna on 10/4/16.
//  Copyright © 2016 Jesus Serna. All rights reserved.
//

#ifndef Torso_h
#define Torso_h

#include "robotPart.h"

class Torso: public RobotPart{
private:
    int BatteryCompartments;
    int ArmSockets;
public:
    Torso(string name,int PartNumber, ComponentType type, double weight, double price, string description, int compartments):
    RobotPart(name,PartNumber,type,weight,price,description), BatteryCompartments(compartments){ArmSockets = 2;};
    
    int get_battery_compartments();
    int get_arm_sockets();
    
};


#endif /* Torso_h */
