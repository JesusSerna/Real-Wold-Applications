//
//  RobbieRobot
//
//  Created by Md Ibrahim Khalil
//  Copyright © 2016 Ibrahim. All rights reserved.

#include <iostream>
#include <string>
using namespace std;

#ifndef HOMEWORK_05_CUSTOMER_H
#define HOMEWORK_05_CUSTOMER_H


class Customer {
private:
    string name;
    int customerNumber;
    double wallet;

public:
    Customer(string custmName, int custmNumber, double custmWallet):
    name(custmName),
    customerNumber(custmNumber),
    wallet(custmWallet){};

    string getName();

    int getNumber();

    double getWallet();

};



#endif //HOMEWORK_05_CUSTOMER_H
