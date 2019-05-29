//
//  customer.cpp
//  RobbieRobot
//
//  Created by Jesus Serna on 11/18/16.
//  Copyright © 2016 Jesus Serna. All rights reserved.
//

#include <iostream>
#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Return_Button.H>

string login = "";

int counter;
int j;
int k;
int balance;
int x = 900;
int y = 700;
Fl_Window* win_model_show;
Fl_Input* login_input;
Fl_Text_Buffer *model_buffer;
Fl_Text_Display *model_display;
Fl_Text_Display *balance_display;
Fl_Text_Buffer *balance_buffer;
Fl_Button* next_model;
Fl_Button* cancel_view_model;
Fl_Button* previous_model;
Fl_Window* win_customer;
Fl_Button *Submit;
Fl_Button *Cancel;
Fl_Button *OK;

Globals a;
Globals& parts_temp = a;
vector<RobotModel> b;
vector<RobotModel>&  models_temp = b;
vector<Customer> c;
vector<Customer>& customers_temp = c;
vector<SalesAssoc> d;
vector<SalesAssoc>& sales_temp = d;
vector<Order> e;
vector<Order>& orders_temp = e;

////////////////Prototypes////////////////////////////
void show_balance();
void show_orders();
void show_models_GUI();

////////////////CALLBACKS/////////////////////////////
void view_models_CB(Fl_Widget* w, void* p) {show_models_GUI();}
void quit_customer_CB(Fl_Widget* w, void* p){win_customer->hide();}
void submit_name_CB(Fl_Widget* w, void* p)
{
    string name = login_input->value();
    for(j = 0; j < customers_temp.size();j++){
        if (strcmp(name.c_str(), customers_temp.at(j).getName().c_str()) == 0)
        {
            login = name;
            Submit->hide();
            login_input->hide();
        }
            }
}
void login_CB(Fl_Widget* w, void* p){
    Submit->show();
    
    Submit->callback((Fl_Callback *)submit_name_CB, 0);
    login_input->show();
}
void view_balance_CB(Fl_Widget* w, void* p){
    if (strcmp(login.c_str(),"") != 0)
        show_balance();
}

void view_orders_CB(Fl_Widget* w, void* p){
    if (strcmp(login.c_str(),"") != 0)
        show_orders();
}
void close_balance_CB(Fl_Widget* w, void* p){OK->hide(); balance_display->hide();}
//////////////////////////////////////////////////////

Fl_Menu_Bar *menubar_customer;

Fl_Menu_Item menuitems_customer[] = {
    { "&File", 0, 0, 0, FL_SUBMENU },
    { "&Log in", FL_ALT + 'r', (Fl_Callback *)login_CB },
    { "&Quit", FL_ALT + 'q', (Fl_Callback *)quit_customer_CB },
    {0},
    
    { "&View", 0, 0, 0, FL_SUBMENU },
    { "&Models", FL_ALT + 'm', (Fl_Callback *)view_models_CB } ,
    { "&Orders", FL_ALT + 'o', (Fl_Callback *)view_orders_CB },
    { "&Balance", FL_ALT + 'b', (Fl_Callback *)view_balance_CB },
    {0},
    {0}
};

void Customer_GUI(vector<RobotModel> models_temp, vector<Order> orders_temp, vector<Customer> customers_temp) {
    
    models_temp = models_temp;
    orders_temp = orders_temp;
    customers_temp = customers_temp;
    
    win_customer = new Fl_Window (360, 220, "Customer");
    win_customer->color(FL_WHITE);
    
    menubar_customer = new Fl_Menu_Bar (0, 0, 360, 30);
    menubar_customer->menu(menuitems_customer);
    
    balance_display = new Fl_Text_Display(0, 30, 360, 140);
    balance_buffer = new Fl_Text_Buffer();
    balance_display->buffer(balance_buffer);
    balance_buffer->text("Your balance is: $");
    OK = new Fl_Button(0,170,360,50,"OK");
    OK->hide();
    balance_display->hide();
    
    login_input = new Fl_Input(50,40,140,50,"Name: ");
    login_input->hide();
    Submit = new Fl_Button(80,100,140,50,"Submit");
    Submit->hide();
    
    win_customer->end();
    win_customer->set_non_modal();
    win_customer->show();
    Fl::run();
}

void show_models_rec();
void next_model_CB(Fl_Widget* w, void* p){
    if(counter < models_temp.size()-2)
    {
        counter++;
        show_models_rec();
    }
    else{
        next_model->hide();
        counter++;
        show_models_rec();
    }
    
}
void cancel__model_CB(Fl_Widget* w, void* p){
    model_display->hide();
    next_model->hide();
    cancel_view_model->hide();
    previous_model->hide();
    int j = 0;
    win_model_show->hide();
    
}
void previous_model_CB(Fl_Widget* w, void* p){
    if(counter > 0)
    {
        counter--;
        show_models_rec();
        next_model->show();
        if(counter == 0) previous_model -> hide();
    }
    else{
        previous_model->hide();
        counter--;
        show_models_rec();
    }
}

void show_models_rec(){
    string name = "\n\tName: \t\t";
    string n = models_temp.at(counter).getName();
    
    string ModelNumber = "\tModel number: \t";
    string M = to_string(models_temp.at(counter).getModelNumber());
    
    string cost = "\tCost: \t\t";
    string c = to_string(models_temp.at(counter).getPrice());
    
    string description = "\tDescription: \t";
    string des = models_temp.at(counter).get_description();
    
    string newline = "\n";
    
    string text_ = name + n + newline + ModelNumber + M + newline + cost + c + newline + description + des;
    
    const char* text = text_.c_str();
    model_buffer->replace(7,model_buffer->length(),text);
    
    if(counter != 0)
    {
        previous_model->show();
    }
}
void show_models_GUI(){
    counter = 0;
    int j = 0;
    win_model_show = new Fl_Window(x,y);
    model_buffer = new Fl_Text_Buffer();
    model_display = new Fl_Text_Display(0, 30, x, y-90);
    model_display->buffer(model_buffer);
    previous_model = new Fl_Button(10,640,140,50,"Previous");
    previous_model -> callback((Fl_Callback *)previous_model_CB, 0);
    next_model = new Fl_Button(150,640,140,50,"Next");
    next_model -> callback((Fl_Callback *)next_model_CB, 0);
    cancel_view_model = new Fl_Button(750,640,140,50,"Cancel");
    cancel_view_model -> callback((Fl_Callback *)cancel__model_CB, 0);
    model_buffer->text("Models:");
    next_model->show();
    cancel_view_model->show();
    previous_model->hide();
    
    model_display -> textsize(32);
    
    show_models_rec();
    
    win_model_show->end();
    win_model_show->set_non_modal();
    win_model_show->show();
    
    Fl::run();
}

void show_orders_rec();
void next_order_CB(Fl_Widget* w, void* p){
    for(j = counter+1; j < orders_temp.size();j++){
        if(orders_temp[j].get_customer_name() == login)
        {
            counter = j;
            j = orders_temp.size();
        }
    }
    show_orders_rec();
}
void cancel_orders_CB(Fl_Widget* w, void* p){
    model_display->hide();
    next_model->hide();
    cancel_view_model->hide();
    previous_model->hide();
    int j = 0;
    win_model_show->hide();
    
}
void previous_order_CB(Fl_Widget* w, void* p){
    for(j = counter-1;j >= 0;j--){
        if(orders_temp[j].get_customer_name() == login)
        {
            counter = j;
            j = 0;
        }
    }
    show_orders_rec();
}

void show_orders_rec(){
    
    //make sure to only show the ones from this customer.....
            string Name = "\n\tName: \t\t\t\t";
            string n = login;
 
            string OrderNumber = "\tOrder number: \t\t\t";
            string o = to_string(orders_temp.at(counter).getOrderNum());
    
            string Model = "\tModel ordered: \t\t\t";
            string m = orders_temp.at(counter).get_model().getName();
    
            string Price = "\tTotal Price of the robot is: \t";
            string p = to_string(orders_temp.at(counter).totalPrice());
            
            string SoldBy = "\tSold by: \t\t\t";
            string sb = orders_temp.at(counter).get_sales_name();
    
    string newline = "\n";
    
    string text_ = Name + n + newline + OrderNumber + o + newline + Model + m + newline + Price + p + newline + SoldBy + sb;
    
    const char* text = text_.c_str();
    model_buffer->replace(7,model_buffer->length(),text);
    
    //make sure there is a previous
    if (counter == orders_temp.size() - 1) next_model->hide();
    if (counter == 0) previous_model->hide();
    for(j = counter-1;j >= 0;j--){
        if(orders_temp[j].get_customer_name() == login)
        {
            previous_model->show();
            j = 0;
        }
        else previous_model->hide();
    }
    
    //make sure there is a next
    for(j = counter+1; j < orders_temp.size();j++){
        if(orders_temp[j].get_customer_name() == login)
        {
            next_model->show();
            j = orders_temp.size();
        }
        else next_model->hide();
    }
}


void show_orders()
{
    int order_found = 0;
    counter = 0;
    win_model_show = new Fl_Window(x,y);
    model_buffer = new Fl_Text_Buffer();
    model_display = new Fl_Text_Display(0, 30, x, y-90);
    model_display->buffer(model_buffer);
    previous_model = new Fl_Button(10,640,140,50,"Previous");
    previous_model -> callback((Fl_Callback *)previous_order_CB, 0);
    next_model = new Fl_Button(150,640,140,50,"Next");
    next_model -> callback((Fl_Callback *)next_order_CB, 0);
    cancel_view_model = new Fl_Button(750,640,140,50,"Cancel");
    cancel_view_model -> callback((Fl_Callback *)cancel_orders_CB, 0);
    model_buffer->text("Orders:");
    next_model->hide();
    cancel_view_model->show();
    previous_model->hide();
    
    //check if there is an order
    for(j = counter; j < orders_temp.size();j++){
        if(orders_temp[j].get_customer_name() == login)
        {
            order_found = 1;
            j = orders_temp.size();
        }
        counter++;
    }
    model_display -> textsize(32);
    
    counter--;
    if(order_found == 1)
        show_orders_rec();
    else
    {
        string text_ = login + " you do not have any orders!";
        const char* text = text_.c_str();
        model_buffer->replace(0,model_buffer->length(),text);
    }
    
    win_model_show->end();
    win_model_show->set_non_modal();
    win_model_show->show();
    
    Fl::run();
}

void show_balance()
{
    balance = 0;
    counter = 0;
    for(j = counter; j < orders_temp.size();j++){
        if(orders_temp[j].get_customer_name() == login)
        {
            balance += orders_temp.at(j).totalPrice();
        }
    }
    balance_display->show();
    string text = to_string(balance) + " ";
    balance_buffer->replace(18,balance_buffer->length(),text.c_str());
    OK->show();
    OK->callback((Fl_Callback *)close_balance_CB, 0);
    

}

