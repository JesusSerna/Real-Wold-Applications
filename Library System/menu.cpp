//
//  Menu.cpp
//  Homeword_4
//
//  Created by Jesus Serna on 9/20/16.
//  Copyright © 2016 Jesus Serna. All rights reserved.
//

#include "library.h"
#include "create.h"
#include "view.h"
#include "publications.h"
#include "check_status.h"

int main() {
    int exit = 0;
    int input;
    Library rvector;
    while (exit == 0)
    {
        cout << "Main menu:\n";
        cout << "\t(1) Create a new publication\n";
        cout << "\t(2) List of all publications\n";
        cout << "\t(3) Check out a publication to a patron\n";
        cout << "\t(4) Check in a publication\n";
        cout << "\t(5) Help\n";
        cout << "\t(0) Quit\n";
        cin >> input;
        
        switch (input) {
            case 1:
                
                create(&rvector);
                break;
            case 2:
                view(rvector);
                break;
            case 3:
                check_status(input, &rvector);
                break;
            case 4:
                check_status(input, &rvector);
            case 5:
                //instructions();
                break;
            case 0:
                exit = 1;
                break;
            default:
                break;
        }
    }
    return 0;
}