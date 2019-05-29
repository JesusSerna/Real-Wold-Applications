//
//  Globals.h
//  RobbieRobot
//
//  Created by Jesus Serna on 10/11/16.
//  Copyright © 2016 Jesus Serna. All rights reserved.
//

#ifndef Globals_h
#define Globals_h

#include "head.h"
#include "arm.h"
#include "battery.h"
#include "locomotor.h"
#include "torso.h"
#include <vector>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>


class Globals{
private:
    vector<Head> heads;
    vector<Arm> arms;
    vector<Battery> batteries;
    vector<Locomotor> locomotors;
    vector<Torso> torsos;
    
public:
    void create_head();
    void create_battery();
    void create_arm();
    void create_locomotor();
    void create_torso();
    
    void create_head_GUI();
    void create_battery_GUI();
    void create_arm_GUI();
    void create_locomotor_GUI();
    void create_torso_GUI();
    
    void show_heads();
    void show_batteries();
    void show_arms();
    void show_locomotors();
    void show_torsos();
    
    void show_heads_GUI(int x,int y);
    void show_batteries_GUI(int x,int y);
    void show_arms_GUI(int x,int y);
    void show_locomotors_GUI(int x,int y);
    void show_torsos_GUI(int x,int y);
    
    
    Head get_head(int i);
    Head get_head_by_name(string name);
    Arm get_arm(int i);
    Arm get_arm_by_name(string name);
    Torso get_torso(int i);
    Torso get_torso_by_name(string name);
    Battery get_battery(int i);
    Battery get_battery_by_name(string name);
    Locomotor get_locomotor(int i);
    Locomotor get_locomotor_by_name(string name);
    
    int get_size(string part);
    void easter_egg();
    void GUI();
    void add_heads();
    void add_arms();
    void add_torsos();
    void add_locomotors();
    void add_batteries();
};
#endif /* Globals_h */
