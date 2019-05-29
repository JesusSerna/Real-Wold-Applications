//
//  Locomotor.cpp
//  RobbieRobot
//
//  Created by Jesus Serna on 10/4/16.
//  Copyright © 2016 Jesus Serna. All rights reserved.
//

#include "locomotor.h"
#include <iostream>

double Locomotor::get_max_speed(){
    return MaxSpeed;
}

double Locomotor::get_power_rate(){
    return PowerRate;
}

double Locomotor::get_power_cosumed(double Speed){
    if(Speed > MaxSpeed){
        
        cout << "Greater than max speed! Please enter a speed less than: ";
        return MaxSpeed;
    }
    return PowerRate * Speed;
}

