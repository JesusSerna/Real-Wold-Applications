#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

using namespace std;

#include "RobotPart.h"
#include "Locomotor.h"
#include "Arm.h"
#include "Torso.h"
#include "Battery.h"
#include "Head.h"


int main1()
{
    /*Testing locomotor*/
    Locomotor loc("Locomotor", 1, ComponentType::locomotor, 20, 100, "Locomotor",76, 40);
    double speed = 320;
    
    cout << "Locomotor:\n name:" << loc.getName() <<endl<< " weight: " << loc.getWeight() <<endl<< " cost:"<< loc.getPrice()<<endl<<" part Number: "<< loc.getPartNumber() <<endl<< " Description:"<<loc.getDescription()<< endl<< " power: " << loc.get_power_cosumed(speed) << endl<< " maxspeed: " << loc.get_max_speed()<<endl;
    
    cin.get();
    
    /*Testing Arms*/
    Arm arm("Arm1", 2, ComponentType::arm, 10, 50, "First Arm",38,20);
    speed = 20;
    
    cout << "Arm:\n name:" << arm.getName() <<endl<< " weight: " << arm.getWeight() <<endl<< " cost:"<< arm.getPrice()<<endl<<" part Number: "<< arm.getPartNumber() <<endl<< " Description:"<<arm.getDescription()<< endl<< " power: " << arm.get_power_cosumed(speed) << endl;
    
    cin.get();
    
    Arm arm2("Arm2", 3, ComponentType::arm, 10, 50, "Second Arm",38,20);
    speed = 20;

    cout << "Arm:\n name:" << arm2.getName() <<endl<< " weight: " << arm2.getWeight() <<endl<< " cost:"<< arm2.getPrice()<<endl<<" part Number: "<< arm2.getPartNumber() <<endl<< " Description:"<<arm2.getDescription()<< endl<< " power: " << arm2.get_power_cosumed(speed) << endl;
    
    cin.get();
    
    
    /*Testing Torso*/
    Torso tor("Torso", 4, ComponentType::torso, 20, 100,"Torso", 2);

    cout << "Torso:\n name:" << tor.getName() <<endl<< " weight: " << tor.getWeight() <<endl<< " cost:"<< tor.getPrice()<<endl<<" part Number: "<< tor.getPartNumber() <<endl<< " Description:"<<tor.getDescription()<< endl<< " battery compartments: " << tor.get_battery_compartments() << endl;
    
    cin.get();
    
    /*Testing Battery*/
    Battery bat("Battery", 5, ComponentType::battery, 5, 10, "Battery", 110);
    
    cout << "Battery:\n name:" << bat.getName() <<endl<< " weight: " << bat.getWeight() <<endl<< " cost:"<< bat.getPrice()<<endl<<" part Number: "<< bat.getPartNumber() <<endl<< " Description:"<<bat.getDescription()<< endl<< " energy " << bat.get_energy() << endl;
    
    cin.get();
    
    Head head("Head", 6, ComponentType::head, 50, 70, "Head");
    
    cout << "Head:\n name:" << head.getName() <<endl<< " weight: " << head.getWeight() <<endl<< " cost:"<< head.getPrice()<<endl<<" part Number: "<< head.getPartNumber() <<endl<< " Description:"<<head.getDescription()<< endl;
    return 0;
}
