//
//  RobbieRobot
//
//  Created by Md Ibrahim Khalil
//  Copyright © 2016 Ibrahim. All rights reserved.


#include <iostream>
using namespace std;

#include "customer.h"


int main2() {

    //Test case for customer
    Customer customer1 ("Robin", 679247920, 448.50 );
    Customer customer2("Alex", 74797946, 350.30);

    cout << "Customer name: " << customer1.getName() << ", " << "ID Number: " << customer1.getNumber() << ", " << "Balance: " << customer1.getWallet() << endl;
    cout << "Customer name: " << customer2.getName() << ", " << "ID Number: " << customer2.getNumber() << ", " << "Balance: " << customer2.getWallet() << endl;


    return 0;
}
