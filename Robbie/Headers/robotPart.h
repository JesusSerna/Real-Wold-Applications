//
//  RobotPart.h
//  RobbieRobot
//
//  Created by Jesus Serna on 10/4/16.
//  Copyright © 2016 Jesus Serna. All rights reserved.
//

#ifndef RobotPart_h
#define RobotPart_h

#include "string"
using namespace std;
enum class ComponentType {torso, head, arm, locomotor, battery};
class RobotPart{
private:
    string Name;
    int PartNumber;
    ComponentType Type;
    double Weight;
    double Price;
    string Description;
    
public:
    RobotPart(string name,int PartNumber, ComponentType type, double weight, double price, string description):
    Name(name),
    PartNumber(PartNumber),
    Type(type),
    Weight(weight),
    Price(price),
    Description(description){}
    
    string getName();
    int getPartNumber();
    string getDescription();
    ComponentType getType();
    double getWeight();
    double getPrice();
    
    
};
#endif /* RobotPart_h */
