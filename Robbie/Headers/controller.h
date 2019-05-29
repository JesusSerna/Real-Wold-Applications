//
//  controller.h
//  RobbieRobot
//
//  Created by Jesus Serna on 10/12/16.
//  Copyright © 2016 Jesus Serna. All rights reserved.
//

#ifndef controller_h
#define controller_h

#include <stdio.h>
#include "RobotModel.h"
#include "Globals.h"
#include "view.h"
#include "Customer.h"
#include "SalesAssoc.h"
#include "Customer.h"
#include "Order.h"
#include <locale.h>
#include <iomanip>

class Controller{
private:
    Globals& parts;
    vector<RobotModel>& models;
    View view;
    vector<Customer>& customers;
    vector<SalesAssoc>& sales;
    vector<Order>& orders;
public:
    Controller(Globals& parts_constructor,
               vector<RobotModel>& models_constructor,
               View view_constructor,
               vector<Customer>& customers_constructor,
               vector<SalesAssoc>& sales_constructor,
               vector<Order>& orders):
                        parts(parts_constructor),
                        models(models_constructor),
                        view(view_constructor),
                        customers(customers_constructor),
                        sales(sales_constructor),
                        orders(orders){};
    
    void product_manager();
    void customer();
    void sales_associate();
    void boss();
    void easteregg();
    void main_menu_GUI();
    void GUI();
   
};


#endif /* controller_h */
