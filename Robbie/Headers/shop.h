//
//  Shop.h
//  RobbitRobot
//
//  Created by Jesus Serna on 10/4/16.
//  Copyright © 2016 Jesus Serna. All rights reserved.
//

#ifndef Shop_h
#define Shop_h

#include "order.h"
#include "robotModel.h"
#include "globals.h"
#include "view.h"
#include "controller.h"
#include <vector>

class Shop{
public:
    Shop(Globals& parts_contructor,
          vector<RobotModel>& models_contructor,
          View view_contructor, Controller controller_constructor):
         parts(parts_contructor),
         models(models_contructor),
         view(view_contructor),
        controller(controller_constructor){};
    void main_menu();
    void menu_GUI();
private:
        Globals parts;
        vector<RobotModel> models;
        View view;
        Controller controller;
};



#endif /* Shop_h */
