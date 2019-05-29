//
//  RobbieRobot
//
//  Created by Md Ibrahim Khalil
//  Copyright © 2016 Ibrahim. All rights reserved.


#include <iostream>
#include <string>
#include <vector>

#include "salesAssoc.h"
#include "customer.h"

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Return_Button.H>


using namespace std;

Fl_Menu_Bar *menubar;


void OK_sa_CB(Fl_Widget* w, void* p)
{
    win_error->hide();
    error_display->hide();
    OK->hide();
    error_buffer->replace(7,22, "x");
}


void show_orders_BOSS_rec();
void next_order_BOSS_CB(Fl_Widget* w, void* p){
    if(counter < orders_temp.size()-2)
    {
        counter++;
        show_orders_BOSS_rec();
    }
    else{
        next_model->hide();
        counter++;
        show_orders_BOSS_rec();
    }
    
}
void cancel_orders_BOSS_CB(Fl_Widget* w, void* p){
    model_display->hide();
    next_model->hide();
    cancel_view_model->hide();
    previous_model->hide();
    int j = 0;
    win_model_show->hide();
    
}
void previous_order_BOSS_CB(Fl_Widget* w, void* p){
    if(counter > 0)
    {
        counter--;
        show_orders_BOSS_rec();
        next_model->show();
        if(counter == 0) previous_model -> hide();
    }
    else{
        previous_model->hide();
        counter--;
        show_orders_BOSS_rec();
    }
}


void show_orders_BOSS_rec(){
    
    //make sure to only show the ones from this customer.....
    string Name = "\n\tName: \t\t\t\t";
    string n = orders_temp.at(counter).get_customer_name();
    
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

    
    if(counter != 0)
    {
        previous_model->show();
    }
    
    //make sure there is a previous
    if (counter == orders_temp.size() - 1) next_model->hide();
}
void show_orders_BOSS_GUI(){
    int order_found = 0;
    counter = 0;
    win_model_show = new Fl_Window(x,y);
    model_buffer = new Fl_Text_Buffer();
    model_display = new Fl_Text_Display(0, 30, x, y-90);
    model_display->buffer(model_buffer);
    previous_model = new Fl_Button(10,640,140,50,"Previous");
    previous_model -> callback((Fl_Callback *)previous_order_BOSS_CB, 0);
    next_model = new Fl_Button(150,640,140,50,"Next");
    next_model -> callback((Fl_Callback *)next_order_BOSS_CB, 0);
    cancel_view_model = new Fl_Button(750,640,140,50,"Cancel");
    cancel_view_model -> callback((Fl_Callback *)cancel_orders_BOSS_CB, 0);
    model_buffer->text("Orders:");
    next_model->show();
    cancel_view_model->show();
    previous_model->hide();
    
    //check if there is an order
    if(orders_temp.size() != 0) order_found = 1;
    model_display -> textsize(32);
    
    if(order_found == 1)
        show_orders_BOSS_rec();
    else
    {
        string text_ = "There are no orders!";
        const char* text = text_.c_str();
        model_buffer->replace(0,model_buffer->length(),text);
    }
    
    win_model_show->end();
    win_model_show->set_non_modal();
    win_model_show->show();
    
    Fl::run();
}



////////////////////////////////// Customer ////////////////////////////////////

void create_newCustomer_CB(Fl_Widget* w, void* p);
void cancel_newCustomer_CB(Fl_Widget* w, void* p);
class New_Customer_Dialog;

// Widgets

New_Customer_Dialog *new_customer_dlg;

class New_Customer_Dialog{

public:
    
    New_Customer_Dialog(){
        
        dialog = new Fl_Window(340, 210, "New Customer");
        
        nc_name = new Fl_Input(100, 10, 210, 25, "Name: ");
        nc_name->align(FL_ALIGN_LEFT);
        
        nc_address = new Fl_Multiline_Input(100, 40, 210, 75, "Address: ");
        nc_address->align(FL_ALIGN_LEFT);
        
        nc_phone = new Fl_Input(100, 120, 210, 25, "Phone No.: ");
        nc_phone->align(FL_ALIGN_LEFT);
        
        nc_custmNumber = new Fl_Input(100, 150, 210, 25, "Customer No.: ");
        nc_custmNumber->align(FL_ALIGN_LEFT);
        
        nc_create = new Fl_Return_Button(125, 180, 120, 25, "Create");
        nc_create->callback((Fl_Callback *)create_newCustomer_CB, 0);
        
        nc_cancel = new Fl_Button(250, 180, 60, 25, "Cancel");
        nc_cancel->callback((Fl_Callback *)cancel_newCustomer_CB, 0);
        
        dialog->end();
        dialog->set_non_modal();
    }
    
    void show(){
        dialog->show();
    }
    
    void hide(){
        dialog->hide();
    }
    
    string name(){
        return nc_name->value();
    }
    
    string address(){
        return nc_address->value();
    }
    
    string phone(){
        return nc_phone->value();
    }
    
    string custmNumber(){
        return nc_custmNumber->value();
    }
    

private:
    
    Fl_Window *dialog;
    Fl_Input *nc_name;
    Fl_Multiline_Input *nc_address;
    Fl_Input *nc_phone;
    Fl_Input *nc_custmNumber;
    Fl_Return_Button *nc_create;
    Fl_Button *nc_cancel;

    
};



// Callbacks

void CB(Fl_Widget* w, void* p){ }        // No actions

void menu_create_newCustomer_CB(Fl_Widget* w, void* p){
    new_customer_dlg->show();
}

void create_newCustomer_CB(Fl_Widget* w, void* p){
    cout << "Creating New Customer Profile" << endl;
    cout << "Name        : " << new_customer_dlg->name() << endl;
    cout << "Address     : " << new_customer_dlg->address() << endl;
    cout << "Phone #     : " << new_customer_dlg->phone() << endl;
    cout << "Unique #    : " << new_customer_dlg->custmNumber() << endl;
    Customer a(new_customer_dlg->name(), stoi(new_customer_dlg->custmNumber().c_str()), 0);
    customers_temp.push_back(a);
    new_customer_dlg->hide();
    
}

void cancel_newCustomer_CB(Fl_Widget* w, void* p){
    new_customer_dlg->hide();
}




///////////////////////////// Sales Associate///////////////////////////////


 
void create_newSA_CB(Fl_Widget* w, void* p);
void cancel_newSA_CB(Fl_Widget* w, void* p);
class New_SA_Dialog;


// Widgets

New_SA_Dialog *new_sa_dlg;



class New_SA_Dialog{
public:
    
    New_SA_Dialog(){
        
        dialog2 = new Fl_Window(340, 210, "New Sales Associate");
        
        
        sa_name = new Fl_Input(120, 10, 210, 25, "Name: ");
        sa_name->align(FL_ALIGN_LEFT);
        
        
        sa_address = new Fl_Multiline_Input(120, 40, 210, 75, "Address: ");
        sa_address->align(FL_ALIGN_LEFT);
        
        
        sa_phone = new Fl_Input(120, 120, 210, 25, "Phone No.: ");
        sa_phone->align(FL_ALIGN_LEFT);
        
        
        sa_employee = new Fl_Input(120, 150, 210, 25, "Employee No.: ");
        sa_employee->align(FL_ALIGN_LEFT);
        
        
        sa_create = new Fl_Return_Button(145, 180, 120, 25, "Create");
        sa_create->callback((Fl_Callback *)create_newSA_CB, 0);
        
        
        sa_cancel = new Fl_Button(270, 180, 60, 25, "Cancel");
        sa_cancel->callback((Fl_Callback *)cancel_newSA_CB, 0);
        
        dialog2->end();
        dialog2->set_non_modal();
        
    }
    
    void show(){
        dialog2->show();
    }
    
    void hide(){
        dialog2->hide();
    }
    
    string name(){
        return sa_name->value();
    }
    
    string address(){
        return sa_address->value();
    }
    
    string phone(){
        return sa_phone->value();
    }
    
    string employee(){
        return sa_employee->value();
    }
    
private:
    
    Fl_Window *dialog2;
    Fl_Input *sa_name;
    Fl_Multiline_Input *sa_address;
    Fl_Input *sa_phone;
    Fl_Input *sa_employee;
    Fl_Return_Button *sa_create;
    Fl_Button *sa_cancel;
    
};



// Callbacks

//void CB(Fl_Widget* w, void* p){ }        // No actions

void menu_create_newSA_CB(Fl_Widget* w, void* p){
    new_sa_dlg->show();
}

void create_newSA_CB(Fl_Widget* w, void* p){
    cout << "Creating New Sales Associate Profile" << endl;
    cout << "Name        : " << new_sa_dlg->name() << endl;
    cout << "Address     : " << new_sa_dlg->address() << endl;
    cout << "Phone #     : " << new_sa_dlg->phone() << endl;
    cout << "Employee #  : " << new_sa_dlg->employee() << endl;
    new_sa_dlg->hide();
    SalesAssoc a(new_sa_dlg->name(), stoi(new_sa_dlg->employee().c_str()));
    sales_temp.push_back(a);
    
}

void cancel_newSA_CB(Fl_Widget* w, void* p){
    new_sa_dlg->hide();
}

void show_orders_BOSS_CB(Fl_Widget* w, void* p){
    show_orders_BOSS_GUI();
}





void show_orders_sa_rec();


void next_order_sa_CB(Fl_Widget* w, void* p){
    for(j = counter+1; j < orders_temp.size();j++){
        if(orders_temp[j].get_sales_name() == login)
        {
            counter = j;
            j = orders_temp.size();
        }
    }
    show_orders_sa_rec();
}


void cancel_orders_sa_CB(Fl_Widget* w, void* p){
    model_display->hide();
    next_model->hide();
    cancel_view_model->hide();
    previous_model->hide();
    int j = 0;
    win_model_show->hide();
    

}




void previous_order_sa_CB(Fl_Widget* w, void* p){

    for(j = counter-1;j >= 0;j--){
        if(orders_temp[j].get_sales_name() == login)                //
        {
            counter = j;
            j = 0;
        }
    }
    show_orders_sa_rec();
}



void show_orders_sa_rec(){
    
    //make sure to only show the ones from this customer.....
    string Name = "\n\tName: \t\t\t\t";
    string n = login;
    
    string OrderNumber = "\tOrder number: \t\t\t";
    string o = to_string(orders_temp.at(counter).getOrderNum());
    
    string Model = "\tModel ordered: \t\t\t";
    string m = orders_temp.at(counter).get_model().getName();
    
    string Price = "\tTotal Price of the robot is: \t";
    string p = to_string(orders_temp.at(counter).totalPrice());
    
    string Soldto = "\tSold to: \t\t\t\t";
    string sb = orders_temp.at(counter).get_customer_name();
    
    string newline = "\n";
    
    string text_ = Name + n + newline + OrderNumber + o + newline + Model + m + newline + Price + p + newline + Soldto + sb;
    
    const char* text = text_.c_str();
    model_buffer->replace(7,model_buffer->length(),text);
    
    //make sure there is a previous
    if (counter == orders_temp.size() - 1) next_model->hide();
    if (counter == 0) previous_model->hide();
    for(j = counter-1;j >= 0;j--){
        if(orders_temp[j].get_sales_name() == login)
        {
            previous_model->show();
            j = 0;
        }
        else previous_model->hide();
    }
    
    //make sure there is a next
    for(j = counter+1; j < orders_temp.size();j++){
        if(orders_temp[j].get_sales_name() == login)
        {
            next_model->show();
            j = orders_temp.size();
        }
        else next_model->hide();
    }
}


void show_orders_sa_GUI()
{
    int order_found = 0;
    counter = 0;
    win_model_show = new Fl_Window(x,y);
    model_buffer = new Fl_Text_Buffer();
    model_display = new Fl_Text_Display(0, 30, x, y-90);
    model_display->buffer(model_buffer);
    previous_model = new Fl_Button(10,640,140,50,"Previous");
    previous_model -> callback((Fl_Callback *)previous_order_sa_CB, 0);
    next_model = new Fl_Button(150,640,140,50,"Next");
    next_model -> callback((Fl_Callback *)next_order_sa_CB, 0);
    cancel_view_model = new Fl_Button(750,640,140,50,"Cancel");
    cancel_view_model -> callback((Fl_Callback *)cancel_orders_sa_CB, 0);
    model_buffer->text("Orders:");
    next_model->hide();
    cancel_view_model->show();
    previous_model->hide();
    
    //check if there is an order
    for(j = counter; j < orders_temp.size();j++){
        if(orders_temp[j].get_sales_name() == login)
        {
            order_found = 1;
            j = orders_temp.size();
        }
        counter++;
    }
    model_display -> textsize(32);
    
    counter--;
    if(order_found == 1)
        show_orders_sa_rec();
    else
    {
        string text_ = login + " has no orders!";
        const char* text = text_.c_str();
        model_buffer->replace(0,model_buffer->length(),text);
    }
    
    win_model_show->end();
    win_model_show->set_non_modal();
    win_model_show->show();
    
    Fl::run();
}

void show_orders_sa(Fl_Widget* w, void* p){
    string name = login_input->value();
    
    int found = 0;
    for(j = 0; j < sales_temp.size();j++){
        if (strcmp(name.c_str(), sales_temp.at(j).getName().c_str()) == 0)
        {
            found = 1;
            login = name;
            Submit->hide();
            login_input->hide();
            show_orders_sa_GUI();
            j = sales_temp.size();
        }
    }
    if(!found)
    {
        win_error->show();
        error_display->show();
        OK->callback((Fl_Callback *)OK_sa_CB, 0);
        OK->show();
        error_buffer->replace(7,8, "Sales associate");
    }

}

void show_orders_sa_CB(Fl_Widget* w, void* p){
    Submit->show();
    
    Submit->callback((Fl_Callback *)show_orders_sa, 0);
    login_input->show();
    
}











// Menu for Boss: includes Create(New Customer & New Sales Associate) and Reports(Orders by SA & All Orders).

Fl_Menu_Item menuitems_boss[] = {
    { "&Create", 0, 0, 0, FL_SUBMENU },
    { "New &Customer", FL_ALT + 'c', (Fl_Callback *)menu_create_newCustomer_CB },
    { "New &Sales Associate", FL_ALT + 's', (Fl_Callback *)menu_create_newSA_CB },
    {0},
    
    { "&Reports", 0, 0, 0, FL_SUBMENU },
    { "&Orders by Sales Associate", FL_ALT + 'c', (Fl_Callback *)show_orders_sa_CB },
    { "&All Orders", FL_ALT + 'a', (Fl_Callback *)show_orders_BOSS_CB },
    {0},
    {0}
    
};

void Boss_GUI() {
    
    Fl_Window* win_boss;                        //window for boss
    win_boss = new Fl_Window (360, 220, "Boss");
    win_boss->color(FL_WHITE);
    
    menubar = new Fl_Menu_Bar (0, 0, 360, 30);
    menubar->menu(menuitems_boss);
    
    login_input = new Fl_Input(0,30,140,50,"Name: ");
    login_input->hide();
    Submit = new Fl_Button(0,80,140,50,"Submit");
    Submit->hide();
    
    
    new_customer_dlg = new New_Customer_Dialog();
    
    new_sa_dlg = new New_SA_Dialog();
    
    win_boss->end();
    win_boss->set_non_modal();
    win_boss->show();
   
    win_error = new Fl_Window(350,100);
    win_error->color(FL_RED);
    
    error_display = new Fl_Text_Display(0, 0, 351, 45);
    error_display->color(FL_RED);
    error_buffer = new Fl_Text_Buffer();
    error_display->buffer(error_buffer);
    error_display -> textsize(20);
    error_display->textcolor(FL_WHITE);
    error_buffer->text("Error: x does not exist!");
    
    OK = new Fl_Button(200,45,140,50,"OK");
    OK->hide();
    
    win_error->end();
    win_error->set_non_modal();
    win_error->hide();
    

    
    Fl::run();
    
}






