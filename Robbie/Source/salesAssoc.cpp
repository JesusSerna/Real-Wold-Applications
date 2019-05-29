//
//  RobbieRobot
//
//  Created by Md Ibrahim Khalil
//  Copyright © 2016 Ibrahim. All rights reserved.


#include "salesAssoc.h"

#include <iostream>
#include <string>

using namespace std;


SalesAssoc::SalesAssoc(string empName, int empNumber) {
    name = empName;
    employeeNumber = empNumber;
}


string SalesAssoc::getName(){
    return name;
}

int SalesAssoc::getEmployeeNumber() {
    return employeeNumber;
}

