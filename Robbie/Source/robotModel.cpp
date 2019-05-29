//
//  RobotModel.cpp
//  RobbieRobot
//
//  Created by Jesus Serna on 10/4/16.
//  Copyright © 2016 Jesus Serna. All rights reserved.
//

#include "robotModel.h"

void RobotModel::add(RobotPart part){
    robotParts.push_back(part);
}

void RobotModel::add_part(Globals parts){
    
    //add a menu, choices will be sub menu, based on what is clicked, create a window with specific fields
    int choice,i,choice2, execute, torso = 0;
    cout << "Please specify what part you would like to add: \n";
    cout << " (1)Head.\n (2)Torso.\n (3)Arm(s).\n (4)Battery(ies).\n (5)Locomotor.\n";
    cin >> choice;
    while(cin.fail() || !(choice >= 1 && choice <= 5)){
        cout << "Please enter from one of the choices!\n";
        cin.clear();
        cin.ignore();
        cin >> choice;
    }
    
    //
    
    
    for (i = 0; i < robotParts.size(); i++){
        if(robotParts.at(i).getType() == ComponentType::torso)
            torso = 1;
    }
    
    switch(choice){
        case 1:
        {
            execute = 1;
            for (i = 0; i < robotParts.size(); i++){
                if(robotParts.at(i).getType() == ComponentType::head){
                    cout << "A head already exists on this model.\n";      //check is head exists
                    execute = 0;
                }
            }
            
            //create window with all heads and their fields, and let them enter 1 input
            
            if (execute == 1 && torso == 1){
                if(parts.get_size("head") != 0){
                    cout << "Which head would you like to add.(Please enter the PartNumber)\n\n";
                    parts.show_heads();
                    cin >> choice2;
                    while(cin.fail()){
                        cout << "Please enter a model number!\n";
                        cin.clear();
                        cin.ignore();
                        cin >> choice2;
                    }
                    robotParts.push_back(parts.get_head(choice2));
                }
                else cout << "Please create a head before trying to add it to this model.\n";
            }
            else if (torso == 0) cout << "Please add a torso first.\n";
            break;
        }
        case 2:
        {
            execute = 1;
            for (i = 0; i < robotParts.size(); i++){
                if(robotParts.at(i).getType() == ComponentType::torso){
                    cout << "A torso already exists on this model.\n";
                    execute = 0;
                }
            }
            if (execute == 1){
                if(parts.get_size("torso") != 0){
                    cout << "Which torso would you like to add.(Please enter the PartNumber)\n\n";
                    parts.show_torsos();
                    cin >> choice2;
                    while(cin.fail()){
                        cout << "Please enter a model number!\n";
                        cin.clear();
                        cin.ignore();
                        cin >> choice2;
                    }
                    robotParts.push_back(parts.get_torso(choice2));
                }
                else cout << "Please create a torso before trying to add it to this model.\n";
            }
            break;
        }
        case 3:
        {
            execute = 1;
            int counter = 0;
            for (i = 0; i < robotParts.size(); i++){
                if(robotParts.at(i).getType() == ComponentType::arm){
                    counter++;
                    if ( counter == 2)
                    {
                    cout << "This model has two arms.\n";
                    execute = 0;
                    }
                }
            }
            if (execute == 1 && torso == 1){
                if(parts.get_size("arm") != 0){
                    cout << "Which arm would you like to add.(Please enter the PartNumber)\n\n";
                    parts.show_arms();
                    cin >> choice2;
                    while(cin.fail()){
                        cout << "Please enter a model number!\n";
                        cin.clear();
                        cin.ignore();
                        cin >> choice2;
                    }
                    robotParts.push_back(parts.get_arm(choice2));
                }
                else cout << "Please create an arm before trying to add it to this model.\n";
            }
            else if (torso == 0) cout << "Please add a torso first.\n";
            break;
        }
        case 4:
        {
            execute = 1;
            int torsonumber = 0, counter = 0,j;
            if(robotParts.size() == 0){execute = 0; counter= 0;}
            
            for (i = 0; i < robotParts.size(); i++){
                if(robotParts.at(i).getType() == ComponentType::torso){
                    torsonumber = robotParts.at(i).getPartNumber();
                    Torso a = parts.get_torso(torsonumber);
                    torsonumber = a.get_battery_compartments();
                    for (j = 0; j < robotParts.size(); j++)
                    {
                        if(robotParts.at(j).getType() == ComponentType::battery)
                        {
                            counter++;
                            if ( counter == torsonumber)
                            {
                                cout << "This model has no open battery compartments.\n";
                                execute = 0;
                            }
                        }
                    }
                }
            }
            if (execute == 1 && torso == 1){
                cout << "Which battery would you like to add.(Please enter the PartNumber)\n\n";
                parts.show_batteries();
                cin >> choice2;
                while(cin.fail()){
                    cout << "Please enter a model number!\n";
                    cin.clear();
                    cin.ignore();
                    cin >> choice2;
                }
                robotParts.push_back(parts.get_battery(choice2));
            }
            else if(torso == 0) cout << "Please add a torso first.\n";
            break;
        }
        case 5:
        {
            execute = 1;
            for (i = 0; i < robotParts.size(); i++){
                if(robotParts.at(i).getType() == ComponentType::locomotor){
                        cout << "This model has a locomotor.\n";
                        execute = 0;
                }
            }
            if (execute == 1 && torso == 1){
                cout << "Which locomotor would you like to add.(Please enter the PartNumber)\n\n";
                parts.show_locomotors();
                cin >> choice2;
                while(cin.fail()){
                    cout << "Please enter a model number!\n";
                    cin.clear();
                    cin.ignore();
                    cin >> choice2;
                }
                robotParts.push_back(parts.get_locomotor(choice2));
            }
            else if (torso == 0) cout << "Please add a torso first.\n";
            break;
        }
    }
}

void RobotModel::viewparts(){
    //create window with all parts and all all fields for each part
    if(robotParts.size() == 0)
    {
        cout << "This model does not yet have parts, please add parts first.\n";
        return;
    }
    int i;
    cout << "\nModel " << getModelNumber() << " has the following parts: " << endl;
    cout << "========================================\n";
    for (i = 0; i < robotParts.size(); i++){
        cout << " name:" << robotParts.at(i).getName() <<endl<< " weight: " << robotParts.at(i).getWeight() <<endl<< " cost:"<< robotParts.at(i).getPrice()<<endl<<" part Number: "<< robotParts.at(i).getPartNumber() <<endl<< " Description:"<<robotParts.at(i).getDescription()<< endl << endl;
    }
}

int RobotModel::getModelNumber(){
    return ModelNumber;
}

string RobotModel::getName(){
    return Name;
}

double RobotModel::getPrice(){
    Price = component_cost() + component_cost()*.15;
    return Price;
}
double RobotModel::component_cost(){
    int i;
    double cost = 0;
    for (i = 0; i < robotParts.size(); i++){
        cost = cost + robotParts.at(i).getPrice();
        }
    return cost;
}

void RobotModel::set_price(double price){
    Price = price;
}

string RobotModel::get_description(){
    return Description;
}

void RobotModel::set_description(string description){
    Description = description;
}
