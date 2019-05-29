//
//  Globals.cpp
//  RobbieRobot
//
//  Created by Jesus Serna on 10/11/16.
//  Copyright © 2016 Jesus Serna. All rights reserved.
//

#include "globals.h"

#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Text_Display.H>

//all classes need getters for "specified fields"
vector<Head> heads_temp;
vector<Arm> arms_temp;
vector<Battery> battery_temp;
vector<Locomotor> l_temp;
vector<Torso> torso_temp;

vector<Head>& heads_=heads_temp;
vector<Arm>& arms_=arms_temp;
vector<Battery>& batteries_=battery_temp;
vector<Locomotor>& locomotors_=l_temp;
vector<Torso>& torsos_=torso_temp;

//These are used to show parts
Fl_Window* Window_show;
Fl_Text_Buffer *buff;
Fl_Text_Display *disp;
Fl_Button* next_button;
Fl_Button* cancel_button;
Fl_Button* previous_button;
int i;

//////////////////////////////

void Globals::GUI(){
    heads_ = heads;
    arms_ = arms;
    batteries_ = batteries;
    locomotors_ = locomotors;
    torsos_ = torsos;
    
    Arm default_("default",0,ComponentType::arm,0,0,"This is a Default, please replace",0,0);
    arms.push_back(default_);
    Battery default_bat("default",0,ComponentType::battery,0,0,"This is a Default, please replace",0);
    batteries.push_back(default_bat);
    Head default_head("default",0,ComponentType::head,0,0,"This is a Default, please replace");
    heads.push_back(default_head);
    Torso default_torso("default",0,ComponentType::torso,0,0,"This is a Default, please replace",0);
    torsos.push_back(default_torso);
    Locomotor default_locomotor("default",0,ComponentType::locomotor,0,0,"This is a Default, please replace",0,0);
    locomotors.push_back(default_locomotor);
}

//                                  //
//                                  //
//  ALL THIS FOR CREATING A HEAD    //
//                                  //
//                                  //
void cancel_head_CB(Fl_Widget* w, void* p);
void create_head_CB(Fl_Widget* w, void* p);


class Create_head_class{
    public:
    Create_head_class(){
        dialog = new Fl_Window(340, 240, "Robot Part Head");
        
        rp_name = new Fl_Input(120, 10, 210, 25, "Name:");
        rp_name->align(FL_ALIGN_LEFT);
        
        rp_part_number = new Fl_Input(120, 40, 210, 25, "Part Number:");
        rp_part_number->align(FL_ALIGN_LEFT);

        rp_weight = new Fl_Input(120, 70, 210, 25, "Weight:");
        rp_weight->align(FL_ALIGN_LEFT);
        
        rp_cost = new Fl_Input(120, 100, 100, 25, "Cost:");
        rp_cost->align(FL_ALIGN_LEFT);
        
        rp_description = new Fl_Multiline_Input(120, 130, 210, 75, "Description:");
        rp_description->align(FL_ALIGN_LEFT);
        
        rp_create = new Fl_Return_Button(145, 210, 120, 25, "Create");
        rp_create->callback((Fl_Callback *)create_head_CB, 0);
        
        rp_cancel = new Fl_Button(270, 210, 60, 25, "Cancel");
        rp_cancel->callback((Fl_Callback *)cancel_head_CB, 0);
        
        dialog->end();
        dialog->set_non_modal();
    }
    void show() {dialog->show();}
    void hide() {dialog->hide();}
    string name() {return rp_name->value();}
    
    string part_number() {if(strcmp(rp_part_number->value(),"") == 0) return "0";
        return rp_part_number->value();}
    string weight() {if(strcmp(rp_weight->value() , "") == 0) return "0";
        return rp_weight->value();}
    string cost() {if(strcmp(rp_cost->value() ,"") ==0) return "0";
        return rp_cost->value();}
    
    string description() {return rp_description->value();}
    
private:
    
    Fl_Window *dialog;
    Fl_Input *rp_name;
    Fl_Input *rp_part_number;
    Fl_Input *rp_weight;
    Fl_Input *rp_cost;
    Fl_Input *rp_description;
    Fl_Return_Button *rp_create;
    Fl_Button *rp_cancel;
};

Create_head_class *create_heads;


//Needs work, figure outhow to push to the vector,
//and also find out how to convert sting to int and double
void create_head_CB(Fl_Widget* w, void* p) {
    ComponentType type = ComponentType::head;
    string name = create_heads->name(), description = create_heads->description();
    int PartNumber= stoi (create_heads->part_number());
    double weight=stod (create_heads->weight()),price= stod(create_heads->cost());
    Head a (name,PartNumber,type,weight,price,description);
    create_heads->hide();
    heads_.push_back(a);
    ///figure out how to push back to heads vector
}
void cancel_head_CB(Fl_Widget* w, void* p) {
    create_heads->hide();
}


void Globals::create_head_GUI(){
    create_heads = new Create_head_class;
    create_heads->show();
    
    Fl::run();
    //add_heads();
}



//                                  //
//                                  //
//  end of creating head            //
//                                  //
//                                  //
//////////////////////////////////////
//                                  //
//                                  //
//  ALL THIS FOR CREATING A ARM     //
//                                  //
//                                  //
void cancel_arm_CB(Fl_Widget* w, void* p);
void create_arm_CB(Fl_Widget* w, void* p);


class Create_arm_class{
public:
    Create_arm_class(){
        dialog = new Fl_Window(340, 300, "Robot Part Arm");
        
        rp_name = new Fl_Input(120, 10, 210, 25, "Name:");
        rp_name->align(FL_ALIGN_LEFT);
        
        rp_part_number = new Fl_Input(120, 40, 210, 25, "Part Number:");
        rp_part_number->align(FL_ALIGN_LEFT);
        
        rp_power = new Fl_Input(120, 70, 210, 25, "Power:");
        rp_power->align(FL_ALIGN_LEFT);
        
        rp_max_speed = new Fl_Input(120, 100, 210, 25, "Max Speed:");
        rp_max_speed->align(FL_ALIGN_LEFT);
        
        rp_weight = new Fl_Input(120, 130, 210, 25, "Weight:");
        rp_weight->align(FL_ALIGN_LEFT);
        
        rp_cost = new Fl_Input(120, 160, 210, 25, "Cost:");
        rp_cost->align(FL_ALIGN_LEFT);
        
        rp_description = new Fl_Multiline_Input(120, 190, 210, 75, "Description:");
        rp_description->align(FL_ALIGN_LEFT);
        
        rp_create = new Fl_Return_Button(145, 270, 120, 25, "Create");
        rp_create->callback((Fl_Callback *)create_arm_CB, 0);
        
        rp_cancel = new Fl_Button(270, 270, 60, 25, "Cancel");
        rp_cancel->callback((Fl_Callback *)cancel_arm_CB, 0);
        
        dialog->end();
        dialog->set_non_modal();
    }
    void show() {dialog->show();}
    void hide() {dialog->hide();}
    string name() {return rp_name->value();}
    string part_number() {if(strcmp(rp_part_number->value(),"") == 0) return "0";
        return rp_part_number->value();}
    string weight() {if(strcmp(rp_weight->value() , "") == 0) return "0";
        return rp_weight->value();}
    string cost() {if(strcmp(rp_cost->value() ,"") ==0) return "0";
        return rp_cost->value();}
    string description() {return rp_description->value();}
    string max_speed() {if(strcmp(rp_max_speed->value() ,"") ==0) return "0";
        return rp_max_speed->value();}
    string power() {if(strcmp(rp_power->value() ,"") ==0) return "0";
        return rp_power->value();}
    
private:
    Fl_Window *dialog;
    Fl_Input *rp_name;
    Fl_Input *rp_power;
    Fl_Input *rp_max_speed;
    Fl_Input *rp_part_number;
    Fl_Input *rp_weight;
    Fl_Input *rp_cost;
    Fl_Input *rp_description;
    Fl_Return_Button *rp_create;
    Fl_Button *rp_cancel;
};

Create_arm_class *create_arms;


//Needs work, figure outhow to push to the vector,
//and also find out how to convert sting to int and double
void create_arm_CB(Fl_Widget* w, void* p) {
    ComponentType type = ComponentType::arm;
    string name = create_arms->name(), description = create_arms->description();
    int PartNumber= stoi (create_arms->part_number());
    double weight=stod (create_arms->weight()),price= stod(create_arms->cost()),power= stod (create_arms->power()), maxSpeed=stod(create_arms->max_speed());
    
    Arm a (name,PartNumber,type,weight,price,description,power,maxSpeed);
    arms_.push_back(a);
    create_arms->hide();
    ///figure out how to push back to heads vector
}

void cancel_arm_CB(Fl_Widget* w, void* p) {
    create_arms->hide();
}


void Globals::create_arm_GUI(){
    create_arms = new Create_arm_class;
    create_arms->show();
    Fl::run();
   // add_arms();
}



//                                  //
//                                  //
//  end of creating arm             //
//                                  //
//                                  //
//////////////////////////////////////
//                                  //
//                                  //
//  ALL THIS FOR CREATING A BATTERY //
//                                  //
//                                  //
void cancel_battery_CB(Fl_Widget* w, void* p);
void create_battery_CB(Fl_Widget* w, void* p);


class Create_battery_class{
public:
    Create_battery_class(){
        dialog = new Fl_Window(340, 270, "Robot Part Battery");
        
        rp_name = new Fl_Input(120, 10, 210, 25, "Name:");
        rp_name->align(FL_ALIGN_LEFT);
        
        rp_part_number = new Fl_Input(120, 40, 210, 25, "Part Number:");
        rp_part_number->align(FL_ALIGN_LEFT);
        
        rp_energy = new Fl_Input(120, 70, 210, 25, "Energy");
        rp_energy->align(FL_ALIGN_LEFT);
        
        rp_weight = new Fl_Input(120, 100, 210, 25, "Weight:");
        rp_weight->align(FL_ALIGN_LEFT);
        
        rp_cost = new Fl_Input(120, 130, 210, 25, "Cost:");
        rp_cost->align(FL_ALIGN_LEFT);
        
        rp_description = new Fl_Multiline_Input(120, 160, 210, 75, "Description:");
        rp_description->align(FL_ALIGN_LEFT);
        
        rp_create = new Fl_Return_Button(145, 240, 120, 25, "Create");
        rp_create->callback((Fl_Callback *)create_battery_CB, 0);
        
        rp_cancel = new Fl_Button(270, 240, 60, 25, "Cancel");
        rp_cancel->callback((Fl_Callback *)cancel_battery_CB, 0);
        
        dialog->end();
        dialog->set_non_modal();
    }
    void show() {dialog->show();}
    void hide() {dialog->hide();}
    string name() {return rp_name->value();}
    string part_number() {if(strcmp(rp_part_number->value(),"") == 0) return "0";
        return rp_part_number->value();}
    string weight() {if(strcmp(rp_weight->value() , "") == 0) return "0";
        return rp_weight->value();}
    string cost() {if(strcmp(rp_cost->value() ,"") ==0) return "0";
        return rp_cost->value();}
    string description() {return rp_description->value();}
    string energy() {if(strcmp(rp_energy->value() ,"") ==0) return "0";
        return rp_energy->value();}
    
private:
    Fl_Window *dialog;
    Fl_Input *rp_name;
    Fl_Input *rp_energy;
    Fl_Input *rp_part_number;
    Fl_Input *rp_weight;
    Fl_Input *rp_cost;
    Fl_Input *rp_description;
    Fl_Return_Button *rp_create;
    Fl_Button *rp_cancel;
};

Create_battery_class *create_batteries;


//Needs work, figure outhow to push to the vector,
//and also find out how to convert sting to int and double
void create_battery_CB(Fl_Widget* w, void* p) {
    ComponentType type = ComponentType::battery;
    string name = create_batteries->name(), description = create_batteries->description();
    int PartNumber= stoi (create_batteries->part_number());
    double weight=stod(create_batteries->weight()),price= stod (create_batteries->cost()),energy=stod(create_batteries->energy());
    
    Battery a (name,PartNumber,type,weight,price,description, energy);
    batteries_.push_back(a);
    create_batteries->hide();
    ///figure out how to push back to heads vector
}

void cancel_battery_CB(Fl_Widget* w, void* p) {
    create_batteries->hide();
}


void Globals::create_battery_GUI(){
    create_batteries = new Create_battery_class;
    create_batteries->show();
    Fl::run();
    //add_batteries();
}



//                                  //
//                                  //
//  end of creating battery         //
//                                  //
//                                  //
//////////////////////////////////////
//                                  //
//                                  //
// ALL THIS FOR CREATING A LOCOMOTOR//
//                                  //
//                                  //
void cancel_locomotor_CB(Fl_Widget* w, void* p);
void create_locomotor_CB(Fl_Widget* w, void* p);


class Create_locomotor_class{
public:
    Create_locomotor_class(){
        dialog = new Fl_Window(340, 300, "Robot Part Locomotor");
        
        rp_name = new Fl_Input(120, 10, 210, 25, "Name:");
        rp_name->align(FL_ALIGN_LEFT);
        
        rp_part_number = new Fl_Input(120, 40, 210, 25, "Part Number:");
        rp_part_number->align(FL_ALIGN_LEFT);
        
        rp_power = new Fl_Input(120, 70, 210, 25, "Power:");
        rp_power->align(FL_ALIGN_LEFT);
        
        rp_max_speed = new Fl_Input(120, 100, 210, 25, "Max Speed:");
        rp_max_speed->align(FL_ALIGN_LEFT);
        
        rp_weight = new Fl_Input(120, 130, 210, 25, "Weight:");
        rp_weight->align(FL_ALIGN_LEFT);
        
        rp_cost = new Fl_Input(120, 160, 210, 25, "Cost:");
        rp_cost->align(FL_ALIGN_LEFT);
        
        rp_description = new Fl_Multiline_Input(120, 190, 210, 75, "Description:");
        rp_description->align(FL_ALIGN_LEFT);
        
        rp_create = new Fl_Return_Button(145, 270, 120, 25, "Create");
        rp_create->callback((Fl_Callback *)create_locomotor_CB, 0);
        
        rp_cancel = new Fl_Button(270, 270, 60, 25, "Cancel");
        rp_cancel->callback((Fl_Callback *)cancel_locomotor_CB, 0);
        
        dialog->end();
        dialog->set_non_modal();
    }
    void show() {dialog->show();}
    void hide() {dialog->hide();}
    string name() {return rp_name->value();}
    string part_number() {if(strcmp(rp_part_number->value(),"") == 0) return "0";
        return rp_part_number->value();}
    string weight() {if(strcmp(rp_weight->value() , "") == 0) return "0";
        return rp_weight->value();}
    string cost() {if(strcmp(rp_cost->value() ,"") ==0) return "0";
        return rp_cost->value();}
    string description() {return rp_description->value();}
    string max_speed() {if(strcmp(rp_max_speed->value() ,"") ==0) return "0";
        return rp_max_speed->value();}
    string power() {if(strcmp(rp_power->value() ,"") ==0) return "0";
        return rp_power->value();}
    
private:
    Fl_Window *dialog;
    Fl_Input *rp_name;
    Fl_Input *rp_power;
    Fl_Input *rp_max_speed;
    Fl_Input *rp_part_number;
    Fl_Input *rp_weight;
    Fl_Input *rp_cost;
    Fl_Input *rp_description;
    Fl_Return_Button *rp_create;
    Fl_Button *rp_cancel;
};

Create_locomotor_class *create_locomotors;


//Needs work, figure outhow to push to the vector,
//and also find out how to convert sting to int and double
void create_locomotor_CB(Fl_Widget* w, void* p) {
    ComponentType type = ComponentType::locomotor;
    string name = create_locomotors->name(), description = create_locomotors->description();
    int PartNumber= stoi(create_locomotors->part_number());
    double weight=stod(create_locomotors->weight()),price= stod(create_locomotors->cost()),power=stod(create_locomotors->power()),maxSpeed=stod(create_locomotors->max_speed());
    
    Locomotor a (name,PartNumber,type,weight,price,description,power,maxSpeed);
    locomotors_.push_back(a);
    
    create_locomotors->hide();
    ///figure out how to push back to heads vector
}

void cancel_locomotor_CB(Fl_Widget* w, void* p) {
    create_locomotors->hide();
}


void Globals::create_locomotor_GUI(){
    create_locomotors = new Create_locomotor_class;
    create_locomotors->show();
    Fl::run();
    //add_locomotors();
}



//                                  //
//                                  //
//  end of creating locomotor       //
//                                  //
//                                  //
//////////////////////////////////////
//                                  //
//                                  //
//  ALL THIS FOR CREATING A TORSO   //
//                                  //
//                                  //
void cancel_torso_CB(Fl_Widget* w, void* p);
void create_torso_CB(Fl_Widget* w, void* p);


class Create_torso_class{
public:
    Create_torso_class(){
        dialog = new Fl_Window(340, 270, "Robot Part Torso");
        
        rp_name = new Fl_Input(120, 10, 210, 25, "Name:");
        rp_name->align(FL_ALIGN_LEFT);
        
        rp_part_number = new Fl_Input(120, 40, 210, 25, "Part Number:");
        rp_part_number->align(FL_ALIGN_LEFT);
        
        rp_compartments = new Fl_Input(120, 70, 210, 25, "Compartments");
        rp_compartments->align(FL_ALIGN_LEFT);
        
        rp_weight = new Fl_Input(120, 100, 210, 25, "Weight:");
        rp_weight->align(FL_ALIGN_LEFT);
        
        rp_cost = new Fl_Input(120, 130, 210, 25, "Cost:");
        rp_cost->align(FL_ALIGN_LEFT);
        
        rp_description = new Fl_Multiline_Input(120, 160, 210, 75, "Description:");
        rp_description->align(FL_ALIGN_LEFT);
        
        rp_create = new Fl_Return_Button(145, 240, 120, 25, "Create");
        rp_create->callback((Fl_Callback *)create_torso_CB, 0);
        
        rp_cancel = new Fl_Button(270, 240, 60, 25, "Cancel");
        rp_cancel->callback((Fl_Callback *)cancel_torso_CB, 0);
        
        dialog->end();
        dialog->set_non_modal();
    }
    void show() {dialog->show();}
    void hide() {dialog->hide();}
    string name() {return rp_name->value();}
    string part_number() {if(strcmp(rp_part_number->value(),"") == 0) return "0";
        return rp_part_number->value();}
    string weight() {if(strcmp(rp_weight->value() , "") == 0) return "0";
        return rp_weight->value();}
    string cost() {if(strcmp(rp_cost->value() ,"") ==0) return "0";
        return rp_cost->value();}
    string description() {return rp_description->value();}
    string compartments() {if(strcmp(rp_compartments->value(),"") == 0) return "0";
        return rp_compartments->value();}
    
private:
    Fl_Window *dialog;
    Fl_Input *rp_name;
    Fl_Input *rp_compartments;
    Fl_Input *rp_part_number;
    Fl_Input *rp_weight;
    Fl_Input *rp_cost;
    Fl_Input *rp_description;
    Fl_Return_Button *rp_create;
    Fl_Button *rp_cancel;
};

Create_torso_class *create_torsos;


//Needs work, figure outhow to push to the vector,
//and also find out how to convert sting to int and double
void create_torso_CB(Fl_Widget* w, void* p) {
    ComponentType type = ComponentType::torso;
    string name = create_torsos->name(), description = create_torsos->description();
    int PartNumber= stoi(create_torsos->part_number());
    double weight=stod(create_torsos->weight()),price= stod(create_torsos->cost()),compartments=stod(create_torsos->compartments());
    
    Torso a (name,PartNumber,type,weight,price,description, compartments);
    torsos_.push_back(a);
    create_torsos->hide();
    
    ///figure out how to push back to heads vector
}

void cancel_torso_CB(Fl_Widget* w, void* p) {
    create_torsos->hide();
}


void Globals::create_torso_GUI(){
    create_torsos = new Create_torso_class;
    create_torsos->show();
    Fl::run();
    //add_torsos();
}



//                                  //
//                                  //
//  end of creating torso           //
//                                  //
//                                  //





void Globals::create_head(){

    
    //create window from slide
    
    
    string name, description;
    int PartNumber;
    ComponentType type = ComponentType::head;
    double weight,price;
    cout << "========================================\n";
    cout << "Please provide me with the following:"<<endl<< " name of the part:  ";
    cin.ignore();
    getline(cin,name);
    cout <<" part number:  ";
    cin >> PartNumber;
    while(cin.fail()){
        cout << " Please enter a integer!\n";
        cin.clear();
        cin.ignore();
        cin >> PartNumber;
    }
    cout << " weight:  ";
    cin >> weight;
    while(cin.fail()){
        cout << " Please enter a integer!\n";
        cin.clear();
        cin.ignore();
        cin >> weight;
    }
    cout << " price:  ";
    cin >> price;
    while(cin.fail()){
        cout << " Please enter a price in 00.00 form!\n";
        cin.clear();
        cin.ignore();
        cin >> price;
    }
    cout << " description:  ";
    cin.ignore();
    getline(cin,description);
    cout << "========================================\n";
    
    Head a (name,PartNumber,type,weight,price,description);
    heads.push_back(a);
}

void Globals::create_battery(){
    
    
    //create window from slide
    
    
    string name, description;
    int PartNumber;
    ComponentType type = ComponentType::battery;
    double weight,price, energy;
    cout << "========================================\n";
    cout << "Please provide me with the following:"<<endl<< " name of the part:  ";
    cin.ignore();
    getline(cin,name);
    cout <<" part number:  ";
    cin >> PartNumber;
    while(cin.fail()){
        cout << " Please enter a integer!\n";
        cin.clear();
        cin.ignore();
        cin >> PartNumber;
    }
    cout << " weight:  ";
    cin >> weight;
    while(cin.fail()){
        cout << " Please enter a integer!\n";
        cin.clear();
        cin.ignore();
        cin >> weight;
    }
    cout << " price:  ";
    cin >> price;
    while(cin.fail()){
        cout << " Please enter a price in 00.00 form!\n";
        cin.clear();
        cin.ignore();
        cin >> price;
    }
    cout << " description:  ";
    cin.ignore();
    getline(cin,description);
    cout << " energy:  ";
    cin >> energy;
    while(cin.fail()){
        cout << " Please enter an energy in 00.00 form!\n";
        cin.clear();
        cin.ignore();
        cin >> energy;
    }
    cout << "========================================\n";

    Battery a (name,PartNumber,type,weight,price,description, energy);
    batteries.push_back(a);
}
void Globals::create_arm(){
    
    
    //create window from slide
    
    
    string name, description;
    int PartNumber;
    ComponentType type = ComponentType::arm;
    double weight,price, power, maxSpeed;
    cout << "========================================\n";
    cout << "Please provide me with the following:"<<endl<< " name of the part:  ";
    cin.ignore();
    getline(cin,name);
    cout <<" part number:  ";
    cin >> PartNumber;
    while(cin.fail()){
        cout << " Please enter a integer!\n";
        cin.clear();
        cin.ignore();
        cin >> PartNumber;
    }
    cout << " weight:  ";
    cin >> weight;
    while(cin.fail()){
        cout << " Please enter a integer!\n";
        cin.clear();
        cin.ignore();
        cin >> weight;
    }
    cout << " price:  ";
    cin >> price;
    while(cin.fail()){
        cout << " Please enter a price in 00.00 form!\n";
        cin.clear();
        cin.ignore();
        cin >> price;
    }
    cout << " description:  ";
    cin.ignore();
    getline(cin,description);
    cout << " power:  ";
    cin >> power;
    while(cin.fail()){
        cout << " Please enter a power in 00.00 form!\n";
        cin.clear();
        cin.ignore();
        cin >> power;
    }
    cout << " max spped:  ";
    cin >> maxSpeed;
    while(cin.fail()){
        cout << " Please enter a max speed in 00.00 form!\n";
        cin.clear();
        cin.ignore();
        cin >> maxSpeed;
    }
    cout << "========================================\n";
    
    Arm a (name,PartNumber,type,weight,price,description,power,maxSpeed);
    arms.push_back(a);
}
void Globals::create_locomotor(){
    
    
    //create window from slide
    
    
    string name, description;
    int PartNumber;
    ComponentType type = ComponentType::locomotor;
    double weight,price, power, maxSpeed;
    cout << "========================================\n";
    cout << "Please provide me with the following:"<<endl<< " name of the part:  ";
    cin.ignore();
    getline(cin,name);
    cout <<" part number:  ";
    cin >> PartNumber;
    while(cin.fail()){
        cout << " Please enter a integer!\n";
        cin.clear();
        cin.ignore();
        cin >> PartNumber;
    }
    cout << " weight:  ";
    cin >> weight;
    while(cin.fail()){
        cout << " Please enter a integer!\n";
        cin.clear();
        cin.ignore();
        cin >> weight;
    }
    cout << " price:  ";
    cin >> price;
    while(cin.fail()){
        cout << " Please enter a price in 00.00 form!\n";
        cin.clear();
        cin.ignore();
        cin >> price;
    }
    cout << " description:  ";
    cin.ignore();
    getline(cin,description);
    cout << " power:  ";
    cin >> power;
    while(cin.fail()){
        cout << " Please enter a power in 00.00 form!\n";
        cin.clear();
        cin.ignore();
        cin >> power;
    }
    cout << " max speed:  ";
    cin >> maxSpeed;
    while(cin.fail()){
        cout << " Please enter a max speed in 00.00 form!\n";
        cin.clear();
        cin.ignore();
        cin >> maxSpeed;
    }
    cout << "========================================\n";
    
    Locomotor a (name,PartNumber,type,weight,price,description,power,maxSpeed);
    locomotors.push_back(a);
}
void Globals::create_torso(){
    
    
    //create window from slide
    
    
    string name, description;
    int PartNumber, compartments;
    ComponentType type = ComponentType::torso;
    double weight,price;
    cout << "========================================\n";
    cout << "Please provide me with the following:"<<endl<< " name of the part:  ";
    cin.ignore();
    getline(cin,name);
    cout <<" part number:  ";
    cin >> PartNumber;
    while(cin.fail()){
        cout << " Please enter a integer!\n";
        cin.clear();
        cin.ignore();
        cin >> PartNumber;
    }
    cout << " weight:  ";
    cin >> weight;
    while(cin.fail()){
        cout << " Please enter a integer!\n";
        cin.clear();
        cin.ignore();
        cin >> weight;
    }
    cout << " price:  ";
    cin >> price;
    while(cin.fail()){
        cout << " Please enter a price in 00.00 form!\n";
        cin.clear();
        cin.ignore();
        cin >> price;
    }
    cout << " description:  ";
    cin.ignore();
    getline(cin,description);
    cout << " number of battery compartments:  ";
    cin >> compartments;
    while(cin.fail()){
        cout << " Please enter an integer!\n";
        cin.clear();
        cin.ignore();
        cin >> compartments;
    }
    cout << "========================================\n";
    
    Torso a (name,PartNumber,type,weight,price,description,compartments);
    torsos.push_back(a);
}


void show_heads_rec();
void next_head_CB(Fl_Widget* w, void* p){
    if(i < heads_.size()-2)
    {
        i++;
        show_heads_rec();
    }
    else{
        next_button->hide();
        i++;
        show_heads_rec();
    }
    
}
void cancel__head_CB(Fl_Widget* w, void* p){
    disp->hide();
    next_button->hide();
    cancel_button->hide();
    previous_button->hide();
    int j = 0;
    int size = heads_.size();
    Window_show->hide();

}
void previous_head_CB(Fl_Widget* w, void* p){
    if(i > 1)
    {
        i--;
        show_heads_rec();
        next_button->show();
        if(i == 1) previous_button -> hide();
    }
    else{
        previous_button->hide();
        i--;
        show_heads_rec();
    }
}

void show_heads_rec(){
    string name = "\n\tName: \t\t";
    string n = heads_.at(i).getName();
    
    string weight = "\tWeight: \t\t";
    string w = to_string(heads_.at(i).getWeight());

    string cost = "\tCost: \t\t";
    string c = to_string(heads_.at(i).getPrice());
    
    string partNumber = "\tPart Number: \t";
    string pn = to_string(heads_.at(i).getPartNumber());
    
    string description = "\tDescription: \t";
    string des = heads_.at(i).getDescription();
    
    string newline = "\n";
    
    string text_ = name + n + newline + weight + w + newline + cost + c + newline + partNumber + pn + newline + description + des;
    
    const char* text = text_.c_str();
    buff->replace(6,buff->length(),text);
    
    if(i > 1)
    {
        previous_button->show();
    }
}
void Globals::show_heads_GUI(int x, int y){
    i = 1;
    int j = 0;
    Window_show = new Fl_Window(x,y);
    buff = new Fl_Text_Buffer();
    disp = new Fl_Text_Display(0, 30, x, y-90);
    disp->buffer(buff);
    previous_button = new Fl_Button(10,640,140,50,"Previous");
    previous_button -> callback((Fl_Callback *)previous_head_CB, 0);
    next_button = new Fl_Button(150,640,140,50,"Next");
    next_button -> callback((Fl_Callback *)next_head_CB, 0);
    cancel_button = new Fl_Button(750,640,140,50,"Cancel");
    cancel_button -> callback((Fl_Callback *)cancel__head_CB, 0);
    
    next_button->hide();
    cancel_button->show();
    previous_button->hide();
    
    disp -> textsize(32);
    
    buff->text("There are currently no heads");
    if(heads_.size() > 1 ){
        buff->text("Heads:");
        if(heads_.size() > 2) next_button->show();
        show_heads_rec();
    }
    Window_show->end();
    Window_show->set_non_modal();
    Window_show->show();
    
    Fl::run();
}
void Globals::show_heads(){
    
    
    //create window from slide with greyed out values
    
    
    
    int i;
    if(heads.size() != 0){
        cout << "Heads:\n";
        cout << "========================================\n";
    for(i = 0; i < heads.size(); i++)
    {
        cout << "name:" << heads.at(i).getName() <<endl<< " weight: " << heads.at(i).getWeight() <<endl<< " cost:"<< heads.at(i).getPrice()<<endl<<" part Number: "<< heads.at(i).getPartNumber() <<endl<< " Description:"<<heads.at(i).getDescription()<< endl<<endl;
    }}
    else cout << "There are no heads.\n";
}

void show_batteries_rec();
void next_batterie_CB(Fl_Widget* w, void* p){
    if(i < batteries_.size()-2)
    {
        i++;
        show_batteries_rec();
    }
    else{
        next_button->hide();
        i++;
        show_batteries_rec();
    }
    
}
void cancel__batterie_CB(Fl_Widget* w, void* p){
    disp->hide();
    next_button->hide();
    cancel_button->hide();
    previous_button->hide();
    int j = 0;
    int size = batteries_.size();
    Window_show->hide();
}
void previous_batterie_CB(Fl_Widget* w, void* p){
    if(i > 1)
    {
        i--;
        show_batteries_rec();
        next_button->show();
        if(i == 1) previous_button -> hide();
    }
    else{
        previous_button->hide();
        i--;
        show_batteries_rec();
    }
}

void show_batteries_rec(){
    string name = "\n\tName: \t\t";
    string n = batteries_.at(i).getName();
    
    string weight = "\tWeight: \t\t";
    string w = to_string(batteries_.at(i).getWeight());
    
    string cost = "\tCost: \t\t";
    string c = to_string(batteries_.at(i).getPrice());
    
    string partNumber = "\tPart Number: \t";
    string pn = to_string(batteries_.at(i).getPartNumber());
    
    string description = "\tDescription: \t";
    string des = batteries_.at(i).getDescription();
    
    string newline = "\n";
    
    string text_ = name + n + newline + weight + w + newline + cost + c + newline + partNumber + pn + newline + description + des;
    
    const char* text = text_.c_str();
    buff->replace(10,buff->length(),text);
    
    if(i > 1)
    {
        previous_button->show();
    }
}
void Globals::show_batteries_GUI(int x, int y){
    i = 1;
    int j = 0;
    Window_show = new Fl_Window(x,y);
    buff = new Fl_Text_Buffer();
    disp = new Fl_Text_Display(0, 30, x, y-90);
    disp->buffer(buff);
    previous_button = new Fl_Button(10,640,140,50,"Previous");
    previous_button -> callback((Fl_Callback *)previous_batterie_CB, 0);
    next_button = new Fl_Button(150,640,140,50,"Next");
    next_button -> callback((Fl_Callback *)next_batterie_CB, 0);
    cancel_button = new Fl_Button(750,640,140,50,"Cancel");
    cancel_button -> callback((Fl_Callback *)cancel__batterie_CB, 0);
    
    next_button->hide();
    cancel_button->show();
    previous_button->hide();
    
    disp -> textsize(32);
    
    buff->text("There are currently no batteries");
    if(batteries_.size() > 1 ){
        buff->text("Batteries:");
        if(batteries_.size() > 2) next_button->show();
        show_batteries_rec();
    }
    Window_show->end();
    Window_show->set_non_modal();
    Window_show->show();
    
    Fl::run();
}
void Globals::show_batteries(){
    
    
    //create window from slide with greyed out values
    
    
    
    int i;
    if(batteries.size() != 0){
        cout << "Batteries:\n";
        cout << "========================================\n";
    for(i = 0; i < batteries.size(); i++)
    {
        cout << "Name:" << batteries.at(i).getName() <<endl<< " weight: " << batteries.at(i).getWeight() <<endl<< " cost:"<< batteries.at(i).getPrice()<<endl<<" part Number: "<< batteries.at(i).getPartNumber() <<endl<< " Description:"<<batteries.at(i).getDescription()<< endl<<" Energy: " << batteries.at(i).get_energy()<< endl<< endl;
    }}
    else cout << "There are no batteries.\n";
}
void show_arms_rec();
void next_arm_CB(Fl_Widget* w, void* p){
    if(i < arms_.size()-2)
    {
        i++;
        show_arms_rec();
    }
    else{
        next_button->hide();
        i++;
        show_arms_rec();
    }
    
}
void cancel__arm_CB(Fl_Widget* w, void* p){
    disp->hide();
    next_button->hide();
    cancel_button->hide();
    previous_button->hide();
    int j = 0;
    int size = arms_.size();
    Window_show->hide();
}
void previous_arm_CB(Fl_Widget* w, void* p){
    if(i > 1)
    {
        i--;
        show_arms_rec();
        next_button->show();
        if(i == 1) previous_button -> hide();
    }
    else{
        previous_button->hide();
        i--;
        show_arms_rec();
    }
}

void show_arms_rec(){
    string name = "\n\tName: \t\t";
    string n = arms_.at(i).getName();
    
    string weight = "\tWeight: \t\t";
    string w = to_string(arms_.at(i).getWeight());
    
    string cost = "\tCost: \t\t";
    string c = to_string(arms_.at(i).getPrice());
    
    string partNumber = "\tPart Number: \t";
    string pn = to_string(arms_.at(i).getPartNumber());
    
    string description = "\tDescription: \t";
    string des = arms_.at(i).getDescription();
    
    string newline = "\n";
    
    string text_ = name + n + newline + weight + w + newline + cost + c + newline + partNumber + pn + newline + description + des;
    
    const char* text = text_.c_str();
    buff->replace(5,buff->length(),text);
    
    if(i > 1)
    {
        previous_button->show();
    }
}
void Globals::show_arms_GUI(int x, int y){
    i = 1;
    int j = 0;
    Window_show = new Fl_Window(x,y);
    buff = new Fl_Text_Buffer();
    disp = new Fl_Text_Display(0, 30, x, y-90);
    disp->buffer(buff);
    previous_button = new Fl_Button(10,640,140,50,"Previous");
    previous_button -> callback((Fl_Callback *)previous_arm_CB, 0);
    next_button = new Fl_Button(150,640,140,50,"Next");
    next_button -> callback((Fl_Callback *)next_arm_CB, 0);
    cancel_button = new Fl_Button(750,640,140,50,"Cancel");
    cancel_button -> callback((Fl_Callback *)cancel__arm_CB, 0);
    
    next_button->hide();
    cancel_button->show();
    previous_button->hide();
    
    disp -> textsize(32);
    
    buff->text("There are currently no arms");
    if(arms_.size() > 1 ){
        buff->text("Arms:");
        if(arms_.size() > 2) next_button->show();
        show_arms_rec();
    }
    Window_show->end();
    Window_show->set_non_modal();
    Window_show->show();
    
    Fl::run();}

void Globals::show_arms(){
    
    
    //create window from slide with greyed out values
    
    
    
    int i;
    if(arms.size() != 0){
    cout << "Arms:\n";
        cout << "========================================\n";
    for(i = 0; i < arms.size(); i++)
    {
        cout << "name:" << arms.at(i).getName() <<endl<< " weight: " << arms.at(i).getWeight() <<endl<< " cost:"<< arms.at(i).getPrice()<<endl<<" part Number: "<< arms.at(i).getPartNumber() <<endl<< " Description:"<<arms.at(i).getDescription()<< endl<<" PowerRate: " << arms.at(i).get_power_rate()<< endl<<endl;
    }}
    else cout << "There are no arms.\n";
}

void show_locomotors_rec();
void next_locomotor_CB(Fl_Widget* w, void* p){
    if(i < locomotors_.size()-2)
    {
        i++;
        show_locomotors_rec();
    }
    else{
        next_button->hide();
        i++;
        show_locomotors_rec();
    }
    
}
void cancel__locomotor_CB(Fl_Widget* w, void* p){
    disp->hide();
    next_button->hide();
    cancel_button->hide();
    previous_button->hide();
    int j = 0;
    int size=locomotors_.size();
    Window_show->hide();
}
void previous_locomotor_CB(Fl_Widget* w, void* p){
    if(i > 1)
    {
        i--;
        show_locomotors_rec();
        next_button->show();
        if(i == 1) previous_button -> hide();
    }
    else{
        previous_button->hide();
        i--;
        show_locomotors_rec();
    }
}

void show_locomotors_rec(){
    string name = "\n\tName: \t\t";
    string n = locomotors_.at(i).getName();
    
    string weight = "\tWeight: \t\t";
    string w = to_string(locomotors_.at(i).getWeight());
    
    string cost = "\tCost: \t\t";
    string c = to_string(locomotors_.at(i).getPrice());
    
    string partNumber = "\tPart Number: \t";
    string pn = to_string(locomotors_.at(i).getPartNumber());
    
    string description = "\tDescription: \t";
    string des = locomotors_.at(i).getDescription();
    
    string newline = "\n";
    
    string text_ = name + n + newline + weight + w + newline + cost + c + newline + partNumber + pn + newline + description + des;
    
    const char* text = text_.c_str();
    buff->replace(11,buff->length(),text);
    
    if(i > 1)
    {
        previous_button->show();
    }
}
void Globals::show_locomotors_GUI(int x, int y){
    i = 1;
    int j = 0;
    Window_show = new Fl_Window(x,y);
    buff = new Fl_Text_Buffer();
    disp = new Fl_Text_Display(0, 30, x, y-90);
    disp->buffer(buff);
    previous_button = new Fl_Button(10,640,140,50,"Previous");
    previous_button -> callback((Fl_Callback *)previous_locomotor_CB, 0);
    next_button = new Fl_Button(150,640,140,50,"Next");
    next_button -> callback((Fl_Callback *)next_locomotor_CB, 0);
    cancel_button = new Fl_Button(750,640,140,50,"Cancel");
    cancel_button -> callback((Fl_Callback *)cancel__locomotor_CB, 0);
    
    next_button->hide();
    cancel_button->show();
    previous_button->hide();
    
    disp -> textsize(32);
    
    buff->text("There are currently no locomotors");
    if(locomotors_.size() > 1 ){
        buff->text("Locomotors:");
        if(locomotors_.size() > 2) next_button->show();
        show_locomotors_rec();
    }
    Window_show->end();
    Window_show->set_non_modal();
    Window_show->show();
    
    Fl::run();
}


void Globals::show_locomotors(){
    
    
    //create window from slide with greyed out values
    
    
    
    int i;
    if(locomotors.size() != 0){
        cout << "Locomotors:\n";
        cout << "========================================\n";
    for(i = 0; i < locomotors.size(); i++)
    {
        cout << "name:" << locomotors.at(i).getName() <<endl<< " weight: " << locomotors.at(i).getWeight() <<endl<< " cost:"<< locomotors.at(i).getPrice()<<endl<<" part Number: "<< locomotors.at(i).getPartNumber() <<endl<< " Description:"<<locomotors.at(i).getDescription()<< endl<<" PowerRate: " << locomotors.at(i).get_power_rate()<< endl<<endl;
    }}
    else cout << "There are no locomotors.\n";
}
void show_torsos_rec();
void next_torso_CB(Fl_Widget* w, void* p){
    if(i < torsos_.size()-2)
    {
        i++;
        show_torsos_rec();
    }
    else{
        next_button->hide();
        i++;
        show_torsos_rec();
    }
    
}
void cancel__torso_CB(Fl_Widget* w, void* p){
    disp->hide();
    next_button->hide();
    cancel_button->hide();
    previous_button->hide();
    int j = 0;
    int size=torsos_.size();
    Window_show->hide();
}
void previous_torso_CB(Fl_Widget* w, void* p){
    if(i > 1)
    {
        i--;
        show_torsos_rec();
        next_button->show();
        if(i == 1) previous_button -> hide();
    }
    else{
        previous_button->hide();
        i--;
        show_torsos_rec();
    }
}

void show_torsos_rec(){
    string name = "\n\tName: \t\t";
    string n = torsos_.at(i).getName();
    
    string weight = "\tWeight: \t\t";
    string w = to_string(torsos_.at(i).getWeight());
    
    string cost = "\tCost: \t\t";
    string c = to_string(torsos_.at(i).getPrice());
    
    string partNumber = "\tPart Number: \t";
    string pn = to_string(torsos_.at(i).getPartNumber());
    
    string description = "\tDescription: \t";
    string des = torsos_.at(i).getDescription();
    
    string newline = "\n";
    
    string text_ = name + n + newline + weight + w + newline + cost + c + newline + partNumber + pn + newline + description + des;
    
    const char* text = text_.c_str();
    buff->replace(6,buff->length(),text);
    
    if(i > 1)
    {
        previous_button->show();
    }
}
void Globals::show_torsos_GUI(int x, int y){
    i = 1;
    int j = 0;
    Window_show = new Fl_Window(x,y);
    buff = new Fl_Text_Buffer();
    disp = new Fl_Text_Display(0, 30, x, y-90);
    disp->buffer(buff);
    previous_button = new Fl_Button(10,640,140,50,"Previous");
    previous_button -> callback((Fl_Callback *)previous_torso_CB, 0);
    next_button = new Fl_Button(150,640,140,50,"Next");
    next_button -> callback((Fl_Callback *)next_torso_CB, 0);
    cancel_button = new Fl_Button(750,640,140,50,"Cancel");
    cancel_button -> callback((Fl_Callback *)cancel__torso_CB, 0);
    
    next_button->hide();
    cancel_button->show();
    previous_button->hide();
    
    disp -> textsize(32);
    
    buff->text("There are currently no torsos");
    if(torsos_.size() > 1 ){
        buff->text("Torsos:");
        if(torsos_.size() > 2) next_button->show();
        show_torsos_rec();
    }
    Window_show->end();
    Window_show->set_non_modal();
    Window_show->show();
    
    Fl::run();
}

void Globals::show_torsos(){
    
    
    //create window from slide with greyed out values
    
    
    
    int i;
    if(torsos.size() != 0){
        cout << "torsos:\n";
        cout << "========================================\n";
    for(i = 0; i < torsos.size(); i++)
    {
        cout << "name:" << torsos.at(i).getName() <<endl<< " weight: " << torsos.at(i).getWeight() <<endl<< " cost:"<< torsos.at(i).getPrice()<<endl<<" part Number: "<< torsos.at(i).getPartNumber() <<endl<< " Description:"<<torsos.at(i).getDescription()<< endl<<" Battery compartments available: " << torsos.at(i).get_battery_compartments()<< endl<< endl;
    }}
    else cout << "There are no torsos.\n";
}
Head Globals::get_head_by_name(string name){
    int number;
    for(number = 0; number < heads.size(); number++)
    {
        if(strcmp(heads.at(number).getName().c_str(),name.c_str())==0)
            return heads.at(number);
    }
    return heads.at(0);
}
Head Globals::get_head(int partnumber){
    int i,found =0;
    while(found == 0){
    for(i = 0; i < heads.size(); i++)
    {
        if(heads.at(i).RobotPart::getPartNumber() == partnumber)
            return heads.at(i);
    }
        if(found == 0){
            cout << "Part " << partnumber << " was not found, please enter a valid part number.\n";
            cin >> partnumber;
            while(cin.fail()){
                cout << " Please enter a integer!\n";
                cin.clear();
                cin.ignore();
                cin >> partnumber;
            }
        }
    }
    return heads.at(-1);
}
Arm Globals::get_arm_by_name(string name){
    int number;
    for(number = 0; number < arms.size(); number++)
    {
        if(strcmp(arms.at(number).getName().c_str(),name.c_str())==0)
            return arms.at(number);
    }
    return arms.at(0);
}
Arm Globals::get_arm(int partnumber){
    int i,found =0;
    while(found == 0){
    for(i = 0; i < arms.size(); i++)
    {
        if(arms.at(i).RobotPart::getPartNumber() == partnumber)
            return arms.at(i);
    }
    if(found == 0){
        cout << "Part " << partnumber << " was not found, please enter a valid part number.\n";
        cin >> partnumber;
        while(cin.fail()){
            cout << " Please enter a integer!\n";
            cin.clear();
            cin.ignore();
            cin >> partnumber;
        }
    }
    }
    return arms.at(-1);
}
Torso Globals::get_torso_by_name(string name){
    int number;
    for(number = 0; number < torsos.size(); number++)
    {
        if(strcmp(torsos.at(number).getName().c_str(),name.c_str())==0)
            return torsos.at(number);
    }
    return torsos.at(0);
}
Torso Globals::get_torso(int partnumber){
    int i,found =0;
    while(found == 0){
    for(i = 0; i < torsos.size(); i++)
    {
        if(torsos.at(i).RobotPart::getPartNumber() == partnumber)
            return torsos.at(i);
    }
    if(found == 0){
        cout << "Part " << partnumber << " was not found, please enter a valid part number.\n";
        cin >> partnumber;
        while(cin.fail()){
            cout << " Please enter a integer!\n";
            cin.clear();
            cin.ignore();
            cin >> partnumber;
        }
    }
    }
    return torsos.at(-1);
}
Battery Globals::get_battery_by_name(string name){
    int number;
    for(number = 0; number < batteries.size(); number++)
    {
        if(strcmp(batteries.at(number).getName().c_str(),name.c_str())==0)
            return batteries.at(number);
    }
    return batteries.at(0);
}
Battery Globals::get_battery(int partnumber){
    int i,found =0;
    while(found == 0){
    for(i = 0; i < batteries.size(); i++)
    {
        if(batteries.at(i).RobotPart::getPartNumber() == partnumber)
            return batteries.at(i);
    }
    if(found == 0){
        cout << "Part " << partnumber << " was not found, please enter a valid part number.\n";
        cin >> partnumber;
        while(cin.fail()){
            cout << " Please enter a integer!\n";
            cin.clear();
            cin.ignore();
            cin >> partnumber;
        }
    }
    }
    return batteries.at(-1);
}
Locomotor Globals::get_locomotor_by_name(string name){
    int number;
    for(number = 0; number < locomotors.size(); number++)
    {
        if(strcmp(locomotors.at(number).getName().c_str(),name.c_str())==0)
            return locomotors.at(number);
    }
    return locomotors.at(0);
}

Locomotor Globals::get_locomotor(int partnumber){
    int i,found =0;
    while(found == 0){
    for(i = 0; i < locomotors.size(); i++)
    {
        if(locomotors.at(i).RobotPart::getPartNumber() == partnumber)
            return locomotors.at(i);
    }
    if(found == 0){
        cout << "Part " << partnumber << " was not found, please enter a valid part number.\n";
        cin >> partnumber;
        while(cin.fail()){
            cout << " Please enter a integer!\n";
            cin.clear();
            cin.ignore();
            cin >> partnumber;
        }

    }
    }
    return locomotors.at(-1);
}
int Globals::get_size(string part){
    if(part == "head") return (int)heads.size();
    else if (part == "arm") return (int)arms.size();
    else if (part == " battery") return (int)batteries.size();
    else if (part == "locomotor") return (int)locomotors.size();
    else if (part == "torso") return (int)torsos.size();
    return 0;
}



void Globals::easter_egg(){
    //adding arms
    Arm jesus1 ("JesusL",1,ComponentType::arm,170,100,"Jesus' left arm",10,10);
        arms.push_back(jesus1);
        Arm jesus2 ("JesusR",2,ComponentType::arm,170,100,"Jesus' right arm",10,10);
        arms.push_back(jesus2);
    
        Arm Rice1 ("RiceL",3,ComponentType::arm,10,100,"Professor Rice's left arm",10,10);
        arms.push_back(Rice1);
        Arm Rice2 ("RiceR",4,ComponentType::arm,10,100,"Professor Rice's right arm",10,10);
        arms.push_back(Rice2);
    
    //adding heads
    
        Head jesus_head ("Jesus_head",1,ComponentType::head,170,100,"Jesus' head");
        heads.push_back(jesus_head);
    Head jesus_head2 ("Jesus_head2",1,ComponentType::head,170,100,"Jesus' head");
    heads.push_back(jesus_head2);

    Head jesus_head3 ("Jesus_head3",1,ComponentType::head,170,100,"Jesus' head");
    heads.push_back(jesus_head3);

    Head jesus_head4 ("Jesus_head4",1,ComponentType::head,170,100,"Jesus' head");
    heads.push_back(jesus_head4);

    Head jesus_head5 ("Jesus_head5",1,ComponentType::head,170,100,"Jesus' head");
    heads.push_back(jesus_head5);

    Head jesus_head6 ("Jesus_head6",1,ComponentType::head,170,100,"Jesus' head");
    heads.push_back(jesus_head6);

    
        Head Rice_head ("Rice_head",2,ComponentType::head,10,100,"Professor Rice's head");
        heads.push_back(Rice_head);
    
    //adding Torso*/
    
        Torso jesus_torso("Jesus_torso",1,ComponentType::torso,170,100,"Jesus' torso",3);
        torsos.push_back(jesus_torso);
    
        Torso Rice_torso("Rice_torso",2,ComponentType::torso,10,100,"Professor Rice's torso",1);
        torsos.push_back(Rice_torso);
    //adding batteries
    
        Battery jesus_heart("Jesus_battery",1,ComponentType::battery,170,100,"Jesus' heart",100);
        batteries.push_back(jesus_heart);
    
        Battery Rice_heart("Rice_battery",2,ComponentType::battery,10,100,"Professor Rice's heart",100);
        batteries.push_back(Rice_heart);
    //adding locomotors
        Locomotor  jesus_legs("Jesus_locomotor",1,ComponentType::locomotor,170,100,"Jesus' legs",10,10);
        locomotors.push_back(jesus_legs);
    
        Locomotor Rice_legs("Rice_locomotor",2,ComponentType::locomotor,10,100,"Professor Rice's legs",10,10);
        locomotors.push_back(Rice_legs);
    
}
