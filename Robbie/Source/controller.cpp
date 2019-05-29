//
//  controller.cpp
//  RobbieRobot
//
//  Created by Jesus Serna on 10/12/16.
//  Copyright © 2016 Jesus Serna. All rights reserved.
//

#include "controller.h"
#include "cust.cpp"
#include "PM.cpp"
#include "boss.cpp"
#include "Sales.cpp"

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <Fl/Fl_Ask.H>

void Controller::GUI(){
    parts_temp = parts;
    models_temp = models;
    customers_temp = customers;
    sales_temp = sales;
    orders_temp = orders;
    parts.GUI();
}

void product_manager_CB(Fl_Widget* w, void* p){
    product_manager_GUI();
}

void customer_CB(Fl_Widget* w, void* p){
    Customer_GUI(models_temp, orders_temp, customers_temp);
}
void sales_CB(Fl_Widget* w, void* p){
    Sales_associate_GUI();
}

void boss_CB(Fl_Widget* w, void* p){
    Boss_GUI();
}

void Controller::main_menu_GUI(){
    MainMenu = new Fl_Window(140,200, "Robbie Robot Shop");
    MainMenu->color(FL_WHITE);
    
    Fl_Button* PM = new Fl_Button(0,0,140,50,"Product Manger");
    PM -> callback((Fl_Callback *)product_manager_CB, 0);
    
    Fl_Button* cust = new Fl_Button(0,50,140,50,"Customer");
    cust -> callback((Fl_Callback *)customer_CB, 0);
    
    Fl_Button* SA = new Fl_Button(0,100,140,50,"Sales Associate");
    SA -> callback((Fl_Callback *)sales_CB, 0);
    
    Fl_Button* boss = new Fl_Button(0,150,140,50,"Boss");
    boss -> callback((Fl_Callback *)boss_CB, 0);
    
    
    MainMenu->end();
    MainMenu->set_non_modal();
    MainMenu->show();
    Fl::run();
}

void Controller::product_manager(){
    int choice = 100,choice2;
    while (choice != 0)
    {
        view.show_menu_manager();
        cin >> choice;
//Making sure right input is provided
        while(cin.fail() || !((choice >= 0 && choice <=6)||choice == 99)){
            cout << "Please pick from one of the choices!\n";
            cin.clear();
            cin.ignore();
            cin >> choice;
        }
        switch (choice) {
            case 1:
            {
                int exit = 1;
                while(exit != 0){
                    cout << "Please specify what part you would like to create: \n";
                    cout << " (1)Head.\n (2)Torso.\n (3)Arm(s).\n (4)Battery(ies).\n (5)Locomotor.\n (0)Exit.\n";
                    cin >> choice2;
//Making sure right input is provided
                    while(cin.fail() || !(choice >= 0 && choice <=5)){
                        cout << "Please pick from one of the choices!\n";
                        cin.clear();
                        cin.ignore();
                        cin >> choice2;
                    }
                    switch (choice2) {
                        case 1:
                            parts.create_head();
                            break;
                        case 2:
                            parts.create_torso();
                            break;
                        case 3:
                            parts.create_arm();
                            break;
                        case 4:
                            parts.create_battery();
                            break;
                        case 5:
                            parts.create_locomotor();
                            break;
                        case 0:
                            exit = 0;
                            break;
                        default:
                            break;
                    }
                }
                break;
            }
            case 2:
            {
                string name;
                int modelnumber;
                double price;
                cout << "Please provide me with the following:"<<endl;
                cout << " Name:  ";
                cin.ignore();
                getline(cin,name);
                cout << " Model number:  ";
                cin >> modelnumber;
//Making sure right input is provided
                while(cin.fail()){
                    cout << " Please enter model number!\n";
                    cin.clear();
                    cin.ignore();
                    cin >> modelnumber;
                }
                cout << " Price (this can be changed later):  ";
                cin >> price;
//Making sure right input is provided
                while(cin.fail()){
                    cout << " Please enter a price in 00.00 form!\n";
                    cin.clear();
                    cin.ignore();
                    cin >> price;
                }
                RobotModel model(name,modelnumber,price);
                models.push_back(model);
                break;
            }
            case 3:
            {
                view.list_parts(parts);
                break;
            }
            case 4:
            {
                view.list_models(models);
                break;
            }
            case 5:
            {
                int i,addmore, found = 0;
                double choice2 = 0;
                view.list_models(models);
                while(found == 0){
                    addmore = 1;
                    if(models.size() != 0){
                        cout <<endl<< "Which model would you like to add parts to? (Please enter model number)" << endl;
                        cin >> choice2;
//Making sure right input is provided
                        while(cin.fail()){
                            cout << "Please enter a model number!\n";
                            cin.clear();
                            cin.ignore();
                            cin >> choice2;
                        }
                        if(choice2 != 0){
                            while(addmore == 1){
                                for (i = 0; i < models.size(); i++){
                                    if (models.at(i).getModelNumber() == choice2){
                                        models.at(i).add_part(parts);
                                        found = 1;
                                    }
                                }
                                if(found == 1){
                                    cout << "Add more parts? [enter 1 for yes, or 0 for no]\n";
                                    cin >> addmore;
//Making sure right input is provided
                                    while(cin.fail() || !(addmore >= 0 && addmore <= 1)){
                                        cout << "Please enter one of the options!\n";
                                        cin.clear();
                                        cin.ignore();
                                        cin >> addmore;
                                    }
                                }
                                else addmore = 0;
                            }
                        }
                        else if (choice2 == 0) found = 1;
                    }
                    else {cout << "No models have been created.\n";found = 1;}
                    if(found == 0){
                        cout << "Please enter a valid model number or press 0 to exit.\n";
                    }
                }
                break;
            }
            case 6:
            {
                int i, found = 0;
                double choice;
                view.list_models(models);
                while(found == 0){
                    if(models.size() != 0){
                        cout << "Which model would you like to show the parts of? (Please enter model number)" << endl;
                        cin >> choice;
                        while(cin.fail()){
                            cout << "Please enter a model number!\n";
                            cin.clear();
                            cin.ignore();
                            cin >> choice;
                        }
                        for (i = 0; i < models.size(); i++){
                            if (models.at(i).getModelNumber() == choice){
                                models.at(i).viewparts();
                                found = 1;
                            }
                        }
                    }
                    else {found = 1;}
                    if(found == 0){
                        cout << "Please enter a valid model number or press 0 to exit.\n";
                    }
                }
                break;
            }
                break;
            default: break;
        }
    }
}
string lowercase(string word){
    int i;
    locale loc;
    for(i = 0; i < word.length(); i++){
        word[i] = tolower(word[i]);
    }
    return word;
}

void Controller::customer(){
    int exit = 100,choice;
    while (exit != 0)
    {
        view.show_menu_customer();
        cin >> choice;
        //Making sure right input is provided
        while(cin.fail() || !((choice >= 0 && choice <=4))){
            cout << "Please pick from one of the choices!\n";
            cin.clear();
            cin.ignore();
            cin >> choice;
        }
        switch (choice) {
            case 0:
                exit = 0;
                break;
            case 1:
                view.list_models(models);
                break;
            case 2:
            {
                int found = 0, found_order = 0, choice;
                if(customers.size() != 0)
                {
                    string name;
                    int i,j;
                    cout << "What is your name?" << endl;
                    cin.ignore();
                    getline(cin,name);
                    for (i = 0; i < customers.size(); i++)
                    {
                        if(lowercase(name) == lowercase(customers.at(i).getName()))
                        {
                            found = 1;
                            for(j = 0; j < orders.size(); j++)
                            {
                                if(lowercase(orders[j].get_customer_name()) == lowercase(name))
                                {
                                    cout << "===================" << endl <<
                                            "Order number: " << orders.at(j).getOrderNum() <<endl<<
                                            "Model ordered: " << orders.at(j).get_model().getName() << endl <<
                                            "Total price of the robot is: " << orders.at(j).totalPrice() << endl <<
                                            "Sold by: " << orders.at(j).get_sales_name() << endl <<
                                            "===================" << endl;
                                    found_order = 1;
                                }
                            }
                        if(found_order == 0) cout << "You have no orders to show."<<endl;
                        else{
                            found_order = 0;
                            cout << "Which order would you like details on? [enter order number]\n";
                            cin >> choice;
                            for(j = 0; j < orders.size(); j++)
                            {
                                if(orders.at(j).getOrderNum() == choice && lowercase(orders[j].get_customer_name()) == lowercase(name))
                                {
                                    cout << endl<<endl<<
                                            "===================" << endl <<
                                            "Order number: " << orders.at(j).getOrderNum() <<endl<<
                                            "Model ordered: " << orders.at(j).get_model().getName() << endl <<
                                            "Total price of the robot is: " << orders.at(j).totalPrice() << endl <<
                                            "Sold by: " << orders.at(j).get_sales_name() << endl <<
                                            "===================" << endl;
                                    cout << "This order includes model " << orders[j].get_model().getModelNumber() << endl;
                                    orders.at(j).get_model().viewparts();
                                    found_order = 1;
                                    }
                                else if (orders.at(j).getOrderNum() == choice && lowercase(orders[j].get_customer_name()) != lowercase(name)){
                                    cout << "This order is not under your name." <<endl;
                                    found_order = 1;
                                    }
                            }
                            if (found_order == 0) cout << "That order number does not exist." << endl;
                            }
                        }
                    }
                    if(found == 0) cout << "You are not yet a registered customer."<<endl;
                }
                else
                {
                    cout << "You are not yet a registered customer."<<endl;
                }
            }
                break;
            case 3:
            {
                string name;
                double wallet;
                int custmnumber;
                cout << "What is your name?\n";
                cin.ignore();
                getline(cin,name);
                cout << "How much would you like to spend?\n";
                cin >> wallet;
                if(customers.size() == 0)
                    custmnumber = 1;
                else
                    custmnumber = customers.at(customers.size() - 1).getNumber() + 1;
                Customer customer1 (name, custmnumber, wallet);
                customers.push_back(customer1);
            }
            case 4:
            {
                int found = 0, found_order = 0;
                if(customers.size() != 0)
                {
                    string name;
                    int i,j;
                    double balance = 0;
                    cout << "What is your name?" << endl;
                    cin.ignore();
                    getline(cin,name);
                    for (i = 0; i < customers.size(); i++)
                    {
                        if(lowercase(name) == lowercase(customers.at(i).getName()))
                        {
                            found = 1;
                            
                            for(j = 0; j < orders.size(); j++)
                            {
                                if(lowercase(orders.at(j).get_customer_name()) == lowercase(name))
                                {
                                    cout << "===================" << endl <<
                                            "Order number: " << orders.at(j).getOrderNum() <<endl<<
                                            "Model ordered: " << orders.at(j).get_model().getName() << endl <<
                                            "Total price of the robot is: " << orders.at(j).totalPrice() << endl <<
                                            "Sold by: " << orders.at(j).get_sales_name() << endl <<
                                            "===================" << endl;
                                    balance += orders.at(j).totalPrice();
                                    found_order = 1;
                                }
                            }
                            if(found_order == 0) cout << "\n\tYour balance is $ 0.00"<<endl;
                        }
                    }
                    if(found == 0) cout << "You are not a registered customer."<<endl;
                    else cout << "\n\tYour total balance is $ " <<fixed << showpoint << setprecision(2) << balance << endl;
                }
                else
                {
                    cout << "You are not a registered customer."<<endl;
                }
            }
            default:
                break;
        }
    }
}

void Controller::sales_associate(){
    int exit_now = 1,choice;
    while (exit_now != 0)
    {
        view.show_menu_sales();
        cin >> choice;
        
        //Making sure right input is provided
        while(cin.fail() || !((choice >= 0 && choice <=3))){
            cout << "Please pick from one of the choices!\n";
            cin.clear();
            cin.ignore();
            cin >> choice;
        }
        switch (choice) {
            case 0:
                exit_now = 0;
                break;
            case 1:
            {
                string sale_associate_name, customer_name;
                int i,j, found_name = 0, found_customer = 0, found_model = 0;
                cout << "Please enter your name." << endl;
                cin.ignore();
                getline(cin, sale_associate_name);
                for (i = 0; i < sales.size(); i++)
                {
                    if(lowercase(sale_associate_name) == lowercase(sales.at(i).getName()))
                    {
                        SalesAssoc sales_toadd = sales.at(i);
                        found_name = 1;
                        cout << "Enter customer name." << endl;
                        while (found_customer == 0){
                            getline(cin,customer_name);
                            if(lowercase(customer_name) == "exit") {found_customer = 1;}
                                
                            for(j=0; j < customers.size(); j++){
                                if(lowercase(customer_name) == lowercase(customers.at(j).getName())){
                                    found_customer = 1;
                                    Customer customer_toadd = customers.at(j);
                                    int ordernumber;
                                    double price;
                                    double shipping;
                                    string model;
                                    ordernumber = orders.at(orders.size()-1).getOrderNum() + 1;
                                    
                                    for(j = 0; j < models.size();j++)
                                        cout << "   " << models.at(j).getName() << endl;
                                    cout << "Which model would " << customer_name << " like to purchase?" << endl;
                                    while(found_model == 0){
                                        getline(cin, model);
                                        for(j = 0; j < models.size();j++){
                                            if(lowercase(models.at(j).getName()) == lowercase(model)){
                                                RobotModel robotmodel_toadd = models.at(j);
                                                found_model = 1;
                                                cout << "Will it be shipped? [y/n]" <<endl;
                                                char shipped;
                                                cin >> shipped;
                                                if(shipped == 'y' || shipped == 'Y')
                                                {
                                                    cout << "Enter Shipping cost." << endl;
                                                    cin >> shipping;
                                                    while(cin.fail()){
                                                        cout << "Please enter shipping charge in 00.00 format!\n";
                                                        cin.clear();
                                                        cin.ignore();
                                                        cin >> shipping;
                                                    }
                                                }
                                                else shipping = 0;
                                                price = robotmodel_toadd.getPrice();
                                                Order order_created(ordernumber,price,shipping,customer_toadd,sales_toadd,robotmodel_toadd);
                                                orders.push_back(order_created);
                                            }
                                        }
                                            if(found_model == 0)
                                                cout << "That model does not exist, please check your spelling. (enter robot name)" << endl;
                                    }
                                    j = customers.size();
                                }
                            }
                            if(found_customer == 0){
                                cout << "That customer does not exist, please check your spelling or enter \"exit\" to cancel this order." << endl;
                            }
                        }
                        
                        i = sales.size();
                    }
                }
                if (found_name == 0){
                    cout << "Your name has not been entered into the system as a sales associate, please see your supervisor." << endl;
                }
            
            }
                break;
            case 2:
            {
                string sale_associate_name;
                int i, j, found_name = 0, found_models = 0;
                cout << "Please enter your name." << endl;
                cin.ignore();
                getline(cin, sale_associate_name);
                for (i = 0; i < sales.size(); i++)
                {
                    if(lowercase(sale_associate_name) == lowercase(sales.at(i).getName()))
                    {
                        found_name = 1;
                        cout << "You have ordered the following parts for various customers:" << endl;
                        for(j = 0; j < orders.size(); j++){
                            if(lowercase(orders.at(j).get_sales_name()) == lowercase(sale_associate_name)){
                                cout << "Name: "<<orders.at(j).get_model().getName() << endl << "\tModel number: " << orders.at(j).get_model().getModelNumber() << endl;
                                found_models = 1;
                            }
                        }
                        if(found_models == 0) cout << "\tYou have not ordered any models."<< endl;
                    }
                }
                if(found_name == 0) cout << "You are not a registered sales associate." << endl;
            }
                break;
            case 3:
            {
                string sale_associate_name;
                int i, j, found_name = 0, found_models = 0;
                cout << "Please enter your name." << endl;
                cin.ignore();
                getline(cin, sale_associate_name);
                for (i = 0; i < sales.size(); i++)
                {
                    if(lowercase(sale_associate_name) == lowercase(sales.at(i).getName()))
                    {
                        found_name = 1;
                        for(j = 0; j < orders.size(); j++){
                            if(lowercase(orders.at(j).get_sales_name()) == lowercase(sale_associate_name)){
                                cout << "===================" << endl <<
                                "Order number: " << orders.at(j).getOrderNum() <<endl<<
                                "Model ordered: " << orders.at(j).get_model().getName() << endl <<
                                "Total price of the robot is: " << orders.at(j).totalPrice() << endl <<
                                "Sold to: " << orders.at(j).get_customer_name() << endl <<
                                "===================" << endl;
                                found_models = 1;
                            }
                        }
                        if(found_models == 0) cout << "You have not ordered any models."<< endl;
                    }
                }
                if(found_name == 0) cout << "You are not a registered sales associate." << endl;
            }
            default:
                break;
        }
    }
}


void Controller::boss(){
    
    int exit = 100, choice;
    while (exit != 0)
    {
        view.show_menu_boss();
        cin >> choice;
        //corrct input is provided
        while(cin.fail() || !((choice >= 0 && choice <=2))){
            cout << "Please pick from one of the choices!\n";
            cin.clear();
            cin.ignore();
            cin >> choice;
        }
        
        switch (choice) {
            case 0:
                exit = 0;
                break;
            case 1:
            {
                int found_order = 0, orders_found = 0;
                double totalSum = 0, profit = 0;
                if (orders.size() > 0 ){
                    for(int i = 0; i < orders.size(); i++){
                        cout << "--------------------" << endl <<
                        "Order number: " << orders.at(i).getOrderNum() <<endl<<
                        "Model ordered: " << orders.at(i).get_model().getName() << endl <<
                        "Total price for the order is: " << orders.at(i).totalPrice() << endl <<
                        "Sold by: " << orders.at(i).get_sales_name() << endl <<
                        "Sold to: " << orders.at(i).get_customer_name() << endl <<
                        "--------------------" << endl <<endl;
                        found_order = 1;
                        orders_found ++;
                        totalSum = totalSum + orders.at(i).totalPrice();
                        profit = profit + (orders.at(i).get_robotPrice() - orders.at(i).get_model().component_cost()); // Assuming there's 15% profit margin for every sale
                        }
                    cout << "Total number of orders found: " << orders_found << endl;
                    cout << "Total gross sale: " <<  totalSum << endl;
                    cout << "Total profit (amount): " << profit << endl;
                            }else{
                                cout << "There are no orders available to show. " << endl;
                            }
            }
                break;
            case 2:
            {
                int found_order = 0, totalSale=0;
                if(sales.size() != 0){
                    string name;
                    int i,j;
                    cout << "What is name of sales associate? " << endl;
                    cin >> name;
                    if(lowercase(name) == lowercase(sales.at(i).getName())){
                        for (i = 0; i < sales.size(); i++){
                            for(j = 0; j < orders.size(); j++){
                                if(lowercase(orders[j].get_sales_name()) == lowercase(name)){
                                    
                                    totalSale = totalSale + orders.at(j).totalPrice();
                                    found_order = found_order + j;
                                }
                            }
                        }
                    }
                    cout << "Name of the sales associate: " << name << endl;
                    cout << "Number of order found: " << found_order << endl;
                    cout << "Total amount of sale for the sales associate: " << totalSale << endl;
                    
                }else{
                    cout << "No sales associate exists. " << endl;
                }
            }
        }
    }
}


void Controller::easteregg(){
    //adding parts
    parts.easter_egg();
    //adding models
    RobotModel model1("model1",1,10);
    RobotModel model2("model2",2,20);
    RobotModel model3("model3",3,30);
    //adding parts to model
    model1.add(parts.get_head(1));
    model1.add(parts.get_torso(1));
    model1.add(parts.get_arm(1));
    model1.add(parts.get_arm(2));
    model1.add(parts.get_locomotor(1));
    model1.add(parts.get_battery(1));
    model1.add(parts.get_battery(2));
    model1.add(parts.get_battery(2));
    
    model2.add(parts.get_head(2));
    model2.add(parts.get_torso(2));
    model2.add(parts.get_arm(3));
    model2.add(parts.get_arm(4));
    model2.add(parts.get_locomotor(2));
    model2.add(parts.get_battery(2));
    
    models.push_back(model1);
    models.push_back(model2);
    models.push_back(model3);
    //adding customers
    Customer customer1 ("Alex", 20000, 550.00);
    Customer customer2 ("Rice", 20001, 50.00);
    customers.push_back(customer1);
    customers.push_back(customer2);
    //adding salesAssociates
    SalesAssoc salesAssoc ("Jones", 100224);
    SalesAssoc salesAssoc2 ("Bob", 100225);
    sales.push_back(salesAssoc);
    sales.push_back(salesAssoc2);
    //adding orders
    Order orders1 (153, 22.99,1, customer1, salesAssoc, model1);
    Order orders2 (154, 22.99,10, customer1, salesAssoc, model2);
    Order orders3 (155, 22.99,10, customer1, salesAssoc, model3);
    Order orders4 (156, 22.99,1, customer1, salesAssoc, model1);
    Order orders5 (157, 22.99,1, customer1, salesAssoc, model2);
    Order orders6 (158, 22.99,1, customer1, salesAssoc, model3);
    orders.push_back(orders1);
    orders.push_back(orders2);
    orders.push_back(orders3);
    orders.push_back(orders4);
    orders.push_back(orders5);
    orders.push_back(orders6);
}




