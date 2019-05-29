//
//  check_status.cpp
//  Homeword_4
//
//  Created by Jesus Serna on 9/20/16.
//  Copyright © 2016 Jesus Serna. All rights reserved.
//

#include "check_status.h"

void check_status(int i, Library *rvector) {
    String name, customer, phone_number;
    int j = 0;
    bool found = false;
    cin.ignore();
    if (i == 3)
    {
        cout << "Which publication would you like to check out?\n";
        getline(cin,name);
        for(j=0; j<rvector->records.size();j++)
        {
            if(name == rvector->records[j].get_title())
            {
                if (!rvector->records[j].is_checked_out())
                {
                    
                    cout << "What is your name?\n";
                    getline(cin,customer);;
                    cout << "What is your phone number?\n";
                    cin >> phone_number;
                    rvector->records[j].checkout(customer, phone_number);
                    j = rvector->records.size()+1;
                    found = true;
                }
                else {
                    cout << "Book is already checked out to: ";
                    cout << rvector->records[j].get_customer() << rvector->records[j].get_phone();
                }
            }
        }
            
        
    }
    if (i == 4)
    {
        cout << "Which publication would you like to check in?\n";
        cin >> name;
        for(j=0; j<rvector->records.size();j++)
        {
            if(name == rvector->records[j].get_title())
            {
                if (!rvector->records[j].is_checked_out())
                {
                    rvector->records[j].checkin();
                    j = rvector->records.size()+1;
                    found = true;
                }
                cout << "Book is already checked in.\n";
            }
        }
    }
    if (j == rvector->records.size() && !found)
    {
        cout << "There is no publication by the name: " << name;
    }
}