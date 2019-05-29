//
//  RobbieRobot
//
//  Created by Md Ibrahim Khalil
//  Copyright © 2016 Ibrahim. All rights reserved.


#include <iostream>
#include <string>
#include "customer.h"
#include "salesAssoc.h"
#include "robotModel.h"


using namespace std;

#ifndef HOMEWORK_05_ORDER_H
#define HOMEWORK_05_ORDER_H


class Order {
private:


    int orderNumber;
    double robotPrice;
    double shippingCost;
    double tax;
    double total;
    Customer customer;
    SalesAssoc salesAssoc;
    RobotModel robotModel;
    bool status;

public:
    Order(int orderNo, double price, double sCost, Customer customer, SalesAssoc salesAssoc, RobotModel robotModel)
    : customer(customer), salesAssoc(salesAssoc), robotModel(robotModel){orderNumber = orderNo;
        robotPrice = price;
        shippingCost = sCost;
        status = false;
    };
    int  getOrderNum();
    double get_robotPrice();
    double calculateShipping();
    double calculateTax();
    double totalPrice();
    string get_customer_name();
    string get_sales_name();
    RobotModel get_model();


};


#endif //HOMEWORK_05_ORDER_H
