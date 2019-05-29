//
//  RobotPart.cpp
//  RobbieRobot
//
//  Created by Jesus Serna on 10/4/16.
//  Copyright © 2016 Jesus Serna. All rights reserved.
//

#include "robotPart.h"

string RobotPart::getName(){
    return Name;
}

int RobotPart::getPartNumber(){
    return PartNumber;
}

string RobotPart::getDescription(){
    return Description;
}
ComponentType RobotPart::getType(){
    return Type;
}

double RobotPart::getWeight(){
    return Weight;
}

double RobotPart::getPrice(){
    return Price;
}
