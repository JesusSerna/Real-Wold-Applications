//
//  Arm.cpp
//  RobbieRobot
//
//  Created by Jesus Serna on 10/4/16.
//  Copyright © 2016 Jesus Serna. All rights reserved.
//

#include "arm.h"


double Arm::get_max_speed(){
    return MaxSpeed;
}

double Arm::get_power_rate(){
    return PowerRate;
}

double Arm::get_power_cosumed(double speed){
    if(speed > MaxSpeed){
        
        //create error window
        cout << "Greater than max speed! Please enter a speed less than: ";
        return MaxSpeed;
    }
    return PowerRate * speed;
}

