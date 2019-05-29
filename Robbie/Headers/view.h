//
//  view.h
//  RobbieRobot
//
//  Created by Jesus Serna on 10/11/16.
//  Copyright © 2016 Jesus Serna. All rights reserved.
//

#ifndef view_h
#define view_h

#include <stdio.h>
#include "Globals.h"
#include "RobotModel.h"

class View {
public:
    View(){ }
    void show_menu_manager();
    void show_menu_customer();
    void show_menu_sales();
    void show_menu_boss();
    void show_main_menu();
    void list_parts(Globals parts);
    void list_models(vector<RobotModel> models);
    
    void help();
};
#endif
