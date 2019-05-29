//
//  Head.h
//  RobbieRobot
//
//  Created by Jesus Serna on 10/4/16.
//  Copyright © 2016 Jesus Serna. All rights reserved.
//

#ifndef Head_h
#define Head_h

#include "robotPart.h"

class Head: public RobotPart{
public:
    Head(string name,int PartNumber, ComponentType type, double weight, double price, string description):
    RobotPart(name,PartNumber,type,weight,price,description){};
};

#endif /* Head_h */
