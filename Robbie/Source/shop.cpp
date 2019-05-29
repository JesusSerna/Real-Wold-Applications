//
//  Shop.cpp
//  RobbitRobot
//
//  Created by Jesus Serna on 10/4/16.
//  Copyright © 2016 Jesus Serna. All rights reserved.
//


#include "shop.h"

void Shop::menu_GUI(){
    controller.GUI();
    controller.main_menu_GUI();
    
}

void Shop::main_menu(){
    int exit = 1;
    while (exit != 0){
        view.show_main_menu();
        int response;
        cin >> response;
        while(cin.fail() && !(response >= 0 && response <= 4)){
            
            
            //create window with 4 buttons, error checking not needed
            
            
            
            cout << "Please enter a valid option!\n";
            cin.clear();
            cin.ignore();
            cin >> response;
        }
    
        if (response == 1) controller.product_manager();
        if (response == 2) controller.customer();
        if (response == 3) controller.sales_associate();
        if (response == 4) controller.boss();
        if(response == 0) exit = 0;
        if(response == 99) controller.easteregg();
    }
}


