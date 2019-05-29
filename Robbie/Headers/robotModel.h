//
//  RobotModel.h
//  RobbieRobot
//
//  Created by Jesus Serna on 10/4/16.
//  Copyright © 2016 Jesus Serna. All rights reserved.
//

#ifndef RobotModel_h
#define RobotModel_h

#include "robotPart.h"
#include "globals.h"
#include <iostream>

class RobotModel {
private:
    string Name;
    int ModelNumber;
    double Price;
    vector<RobotPart> robotParts;
    string Description;
    
public:
    RobotModel(string name, int modelNumber, double price): Name(name), ModelNumber(modelNumber), Price(price){Description = "There is no description.\n";};
    
    string has(string part){
        int i;
        string arms="";
        string batteries="";
        if(strcmp(part.c_str(), "head") == 0)
        {
            for(i = 0; i< robotParts.size();i++){
                if(robotParts.at(i).getType() == ComponentType::head) return robotParts.at(i).getName();
            }
        }
        if(strcmp(part.c_str(), "torso") == 0)
        {
            for(i = 0; i< robotParts.size();i++){
                if(robotParts.at(i).getType() == ComponentType::torso) return robotParts.at(i).getName();
            }
        }
        if(strcmp(part.c_str(), "arm") == 0)
        {
            for(i = 0; i< robotParts.size();i++){
                if(robotParts.at(i).getType() == ComponentType::arm && strcmp(robotParts.at(i).getName().c_str(),"default")) arms += robotParts.at(i).getName()+",";
            }
        }
        if(strcmp(part.c_str(), "l") == 0)
        {
            for(i = 0; i < robotParts.size();i++){
                if(robotParts.at(i).getType() == ComponentType::locomotor) return robotParts.at(i).getName();
            }
        }
        if(strcmp(part.c_str(), "battery") == 0){
            for(i = 0; i< robotParts.size();i++){
                if(robotParts.at(i).getType() == ComponentType::battery && strcmp(robotParts.at(i).getName().c_str(),"default")) batteries += robotParts.at(i).getName()+",";
            }
            return batteries +"\0";
        }

        return arms+"\0";
        
    }
    void add(RobotPart part);
    void add_part(Globals parts);
    void viewparts();
    string get_description();
    void set_description(string description);
    void set_price(double price);
    double component_cost();
    double max_speed();
    string getName();
    double getPrice();
    int getModelNumber();
};
#endif /* RobotModel_h */
