//
//  RobbieRobot
//
//  Created by Md Ibrahim Khalil
//  Copyright © 2016 Ibrahim. All rights reserved.


#include <iostream>
#include <string>

using namespace std;

#ifndef HOMEWORK_05_SALESASSOC_H
#define HOMEWORK_05_SALESASSOC_H


class SalesAssoc {
private:
    string name;
    int employeeNumber;

public:
    SalesAssoc(string empName, int empNumber);

    string getName();

    int getEmployeeNumber();


};


#endif //HOMEWORK_05_SALESASSOC_H
