//
//  RobbieRobot
//
//  Created by Md Ibrahim Khalil
//  Copyright © 2016 Ibrahim. All rights reserved.


#include "order.h"


int Order::getOrderNum() {
    return orderNumber;
}

double Order::get_robotPrice() {
    robotPrice = robotModel.getPrice();
    return robotPrice;
}

double Order::calculateShipping() {
    return shippingCost;
}

double Order::calculateTax() {
    tax = 0.08 * get_robotPrice();
    return tax;
}

double Order::totalPrice() {
    total = (get_robotPrice() + shippingCost + tax);
    return total;
}
string Order::get_customer_name(){
    return customer.getName();
}
string Order:: get_sales_name(){
    return salesAssoc.getName();
}
RobotModel Order::get_model(){
    return robotModel;
}
