//
//  view.cpp
//  RobbieRobot
//
//  Created by Jesus Serna on 10/11/16.
//  Copyright © 2016 Jesus Serna. All rights reserved.
//

#include "view.h"
void View::show_menu_manager(){
    cout << endl << endl;
    cout << "  =====================================" << endl;
    cout << "  |     Robot Shop Product Manager    |" << endl;
    cout << "  =====================================" << endl;
    cout << "  |                                   |" << endl;
    cout << "  | (1) Create part                   |" << endl;
    cout << "  | (2) Create Model                  |" << endl;
    cout << "  | (3) View created parts            |" << endl;
    cout << "  | (4) View created models           |" << endl;
    cout << "  | (5) Add parts to created models   |" << endl;
    cout << "  | (6) Show parts in created models  |" << endl;
    cout << "  | (0) Exit to shop                  |" << endl;
    cout << "  |___________________________________|" << endl;
    cout << endl << endl;
}

void View::list_models(vector<RobotModel> models){
    int i;
    if(models.size() != 0){
        cout << "Models: "<<endl;
        cout << "========================================\n";
    for (i = 0; i < models.size(); i++){
        cout << " Name: " << models.at(i).getName() <<endl<< " Model number: " << models.at(i).getModelNumber() << endl<< " Price: " << models.at(i).getPrice() << endl << " Description: " << models.at(i).get_description()<<endl;
        
    }}
    else cout << "There are no current models.\n";
}
void View::list_parts(Globals parts){
    parts.show_heads();
    parts.show_arms();
    parts.show_torsos();
    parts.show_batteries();
    parts.show_locomotors();
}

void View::show_main_menu(){
    cout << endl << endl;
    cout << "  =====================================" << endl;
    cout << "  |             Robot Shop            |" << endl;
    cout << "  =====================================" << endl;
    cout << "  |      Who are you?                 |" << endl;
    cout << "  | (1) Product Manager               |" << endl;
    cout << "  | (2) Customer                      |" << endl;
    cout << "  | (3) Sales Associate               |" << endl;
    cout << "  | (4) Boss                          |" << endl;
    cout << "  | (0) Quit                          |" << endl;
    cout << "  |___________________________________|" << endl;
    cout << endl << endl;
}

void View::show_menu_customer(){
    cout << endl << endl;
    cout << "  =====================================" << endl;
    cout << "  |         Robot Shop Customer       |" << endl;
    cout << "  =====================================" << endl;
    cout << "  |                                   |" << endl;
    cout << "  | (1) Browse catalogs               |" << endl;
    cout << "  | (2) View your order               |" << endl;
    cout << "  | (3) Register                      |" << endl;
    cout << "  | (4) Show balance                  |" << endl;
    cout << "  | (0) Exit                          |" << endl;
    cout << "  |___________________________________|" << endl;
    cout << endl << endl;
}


void View::show_menu_sales(){
    cout << endl << endl;
    cout << "  =====================================" << endl;
    cout << "  |     Robot Shop Sales Associate    |" << endl;
    cout << "  =====================================" << endl;
    cout << "  |                                   |" << endl;
    cout << "  | (1) Order models for customer     |" << endl;  
    cout << "  | (2) View ordered models           |" << endl;  
    cout << "  | (3) Sales report                  |" << endl;
    cout << "  | (0) Exit                          |" << endl;
    cout << "  |___________________________________|" << endl;
    cout << endl << endl;
}

void View::show_menu_boss(){
    cout << endl << endl;
    cout << "  =====================================" << endl;
    cout << "  |   Robot Shop Pointed-haired-Boss  |" << endl;
    cout << "  =====================================" << endl;
    cout << "  |                                   |" << endl;
    cout << "  | (1) List of all order details     |" << endl; 
    cout << "  | (2) Sales for each Associate      |" << endl; 
    cout << "  | (0) Exit                          |" << endl;
    cout << "  |___________________________________|" << endl;
    cout << endl << endl;

}
