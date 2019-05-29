//
//  RobbieRobot
//
//  Created by Md Ibrahim Khalil
//  Copyright © 2016 Ibrahim. All rights reserved.


#include <iostream>
using namespace std;

#include "salesAssoc.h"


int main3() {

    //Test case for sales associate
    SalesAssoc SA1 ("Graham Brown", 14);
    SalesAssoc SA2("William Fedrick", 25);

    cout << "Sales Associate's name: " << SA1.getName() << ", " << "Employee Number: " << SA1.getEmployeeNumber() << endl;
    cout << "Sales Associate's name: " << SA2.getName() << ", " << "Employee Number: " << SA2.getEmployeeNumber() << endl;


    return 0;
}
