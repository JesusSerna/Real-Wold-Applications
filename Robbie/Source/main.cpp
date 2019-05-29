//
//  testRobotModel.cpp
//  RobbitRobot
//
//  Created by Jesus Serna on 10/5/16.
//  Copyright © 2016 Jesus Serna. All rights reserved.
//

#include <stdio.h>
#include "shop.h"
#include <vector> 
#include "Order.h"

int main(){
    Globals parts;
    vector<RobotModel> models;
    View view;
    vector<Customer> customers;
    vector<SalesAssoc> sales;
    vector<Order> orders;
    Controller controller(parts, models, view, customers, sales, orders);
    Shop shop(parts, models, view, controller);
    controller.easteregg();
    
    //shop.main_menu();
    shop.menu_GUI();
    
    return 1;
}

