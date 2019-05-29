//These are used to show models///////

Fl_Window* MainMenu;

Fl_Input *name;
Fl_Input *head_to_add;
Fl_Input *torso_to_add;
Fl_Input *arm1_to_add;
Fl_Input *arm2_to_add;
Fl_Input *locomotor_to_add;
Fl_Input *battery_to_add;
Fl_Input *battery2_to_add;
Fl_Input *battery3_to_add;
Fl_Text_Display *Header;

Fl_Window* win_error;
Fl_Text_Buffer *error_buffer;
Fl_Text_Display *error_display;
/////////////////////////////////////

void createModel_GUI();
void addParts();

Fl_Button* show_heads_button;
Fl_Button* show_torsos_button;
Fl_Button* show_arms_button;
Fl_Button* show_locomotors_button;
Fl_Button* show_batteries_button;

Fl_Window* Window_menu= new Fl_Window(x,y);
Fl_Menu_Bar *menubar_PM;

void quit_CB(Fl_Widget* w, void* p) { Window_menu->hide();}

void add_parts_CB(Fl_Widget* w, void* p) {
    addParts();
}

void view_heads_CB(Fl_Widget* w, void* p) {parts_temp.show_heads_GUI(x, y);}
void view_torsos_CB(Fl_Widget* w, void* p) {parts_temp.show_torsos_GUI(x, y);}
void view_arms_CB(Fl_Widget* w, void* p) {parts_temp.show_arms_GUI(x, y);}
void view_locomotors_CB(Fl_Widget* w, void* p) {parts_temp.show_locomotors_GUI(x, y);}
void view_batteries_CB(Fl_Widget* w, void* p) {parts_temp.show_batteries_GUI(x, y);}

void createTorso_CB(Fl_Widget* w, void* p) {parts_temp.create_torso_GUI();}
void createArm_CB(Fl_Widget* w, void* p) {parts_temp.create_arm_GUI();}
void createHead_CB(Fl_Widget* w, void* p) {parts_temp.create_head_GUI();}
void createBattery_CB(Fl_Widget* w, void* p) {parts_temp.create_battery_GUI();}
void createLocomotor_CB(Fl_Widget* w, void* p) {parts_temp.create_locomotor_GUI();}
void create_model_CB(Fl_Widget* w, void* p) {createModel_GUI();}

Fl_Menu_Item menuitems_PM[] = {
    { "&File", 0, 0, 0, FL_SUBMENU },
    { "&Quit", FL_ALT + 'q', (Fl_Callback *)quit_CB },
    { 0 },
    { "&View", 0, 0, 0, FL_SUBMENU },
    { "&Models", FL_ALT + 'm', (Fl_Callback *)view_models_CB },
    { "&Parts", 0, 0, 0, FL_SUBMENU },
    { "Torso", 0, (Fl_Callback *)view_torsos_CB },
    { "Arm", 0, (Fl_Callback *)view_arms_CB },
    { "Head", 0, (Fl_Callback *)view_heads_CB },
    { "Locomotor", 0, (Fl_Callback *)view_locomotors_CB },
    { "Battery", 0, (Fl_Callback *)view_batteries_CB },
    { 0 },
    
    { 0 },
    { "&Create", 0, 0, 0, FL_SUBMENU },
    { "Robot Model", 0, (Fl_Callback *)create_model_CB },
    { "Robot Part", 0, 0, 0, FL_SUBMENU },
    { "Torso", 0, (Fl_Callback *)createTorso_CB },
    { "Arm", 0, (Fl_Callback *)createArm_CB },
    { "Head", 0, (Fl_Callback *)createHead_CB },
    { "Locomotor", 0, (Fl_Callback *)createLocomotor_CB },
    { "Battery", 0, (Fl_Callback *)createBattery_CB },
    { 0 },
    { 0 },
    { "&Model tools", 0, 0, 0, FL_SUBMENU },
    { "Add parts", 0, (Fl_Callback *)add_parts_CB, 0, FL_MENU_DIVIDER  },
    { 0 },
    { 0 }
};

void product_manager_GUI(){
    //this goes in calback to show heads     parts.show_heads_GUI(Window,x,y);
    Window_menu = new Fl_Window(x,y, "Product Manager");
    Window_menu->color(FL_WHITE);
    
    menubar_PM = new Fl_Menu_Bar(0, 0, x, 30);
    menubar_PM->menu(menuitems_PM);
    
    show_heads_button = new Fl_Button(10,60,140,50,"Show Heads");
    show_heads_button -> callback((Fl_Callback *)view_heads_CB, 0);
    show_heads_button->hide();
    
    show_torsos_button = new Fl_Button(10,115,140,50,"Show torsos");
    show_torsos_button -> callback((Fl_Callback *)view_torsos_CB, 0);
    show_torsos_button->hide();
    
    show_arms_button = new Fl_Button(10,170,140,50,"Show arms");
    show_arms_button -> callback((Fl_Callback *)view_arms_CB, 0);
    show_arms_button->hide();
    
    show_locomotors_button = new Fl_Button(10,225,140,50,"Show locomotors");
    show_locomotors_button -> callback((Fl_Callback *)view_locomotors_CB, 0);
    show_locomotors_button->hide();
    
    show_batteries_button = new Fl_Button(10,280,140,50,"Show batteries");
    show_batteries_button -> callback((Fl_Callback *)view_batteries_CB, 0);
    
    show_batteries_button->hide();
    
    name = new Fl_Input(60,60,140,50,"Name: ");
    name->hide();
    
    Submit = new Fl_Button(30,600,140,50,"Submit");
    Submit->hide();
    Cancel = new Fl_Button(175,600,140,50, "Cancel");
    Cancel->hide();
    
    
    //These are input fields for the parts we would like to add
    head_to_add = new Fl_Input(300,60,140,50,"Head:");
    head_to_add->hide();
    
    torso_to_add = new Fl_Input(300,115,140,50,"Torso:");
    torso_to_add->hide();
    
    arm1_to_add = new Fl_Input(300,170,140,50,"Arm1:");
    arm2_to_add = new Fl_Input(505,170,140,50,"Arm2:");
    arm1_to_add->hide();
    arm2_to_add->hide();
    
    locomotor_to_add = new Fl_Input(300,225,140,50,"Locomotor:");
    locomotor_to_add->hide();
    
    battery_to_add = new Fl_Input(300,280,140,50,"Battery1:");
    battery2_to_add = new Fl_Input(505,280,140,50,"Battery2:");
    battery3_to_add = new Fl_Input(710,280,140,50,"Battery3:");
    battery_to_add->hide();
    battery2_to_add->hide();
    battery3_to_add->hide();
    
    Header = new Fl_Text_Display (450,60,0,0,"Enter the name of the parts you would like to add. \n\tNote: if model does not have a torso please add a torso before adding batteries");
    Header->hide();
    
    
    
    Window_menu->end();
    Window_menu->set_non_modal();
    Window_menu->show();
    
    Fl::run();
    
}

void cancelModel_CB(Fl_Widget* w, void* p);
void createModel_CB(Fl_Widget* w, void* p);


class CreateModel_class{
public:
    CreateModel_class(){
        dialog = new Fl_Window(340, 130, "New Model");
        
        rp_name = new Fl_Input(120, 10, 210, 25, "Name:");
        rp_name->align(FL_ALIGN_LEFT);
        
        rp_model_number = new Fl_Input(120, 40, 210, 25, "Model Number:");
        rp_model_number->align(FL_ALIGN_LEFT);
        
        rp_cost = new Fl_Input(120, 70, 210, 25, "Cost:");
        rp_cost->align(FL_ALIGN_LEFT);
        
        rp_create = new Fl_Button(145, 100, 120, 25, "Create");
        rp_create->callback((Fl_Callback *)createModel_CB, 0);
        
        rp_cancel = new Fl_Button(270, 100, 60, 25, "Cancel");
        rp_cancel->callback((Fl_Callback *)cancelModel_CB, 0);
        
        dialog->end();
        dialog->set_non_modal();
    }
    void show() {dialog->show();}
    void hide() {dialog->hide();}
    string name() {return rp_name->value();}
    string model_number() {if(strcmp(rp_model_number->value(),"") == 0) return "0";
        return rp_model_number->value();}
    string cost() {if(strcmp(rp_cost->value() ,"") ==0) return "0";
        return rp_cost->value();}
private:
    Fl_Window *dialog;
    Fl_Input *rp_name;
    Fl_Input *rp_model_number;
    Fl_Input *rp_cost;
    Fl_Button *rp_create;
    Fl_Button *rp_cancel;
};

CreateModel_class *createModel;


void createModel_CB(Fl_Widget* w, void* p) {
    string name = createModel->name();
    int ModelNumber= stoi (createModel->model_number());
    double price= stod(createModel->cost());
    
    RobotModel a (name,ModelNumber,price);
    models_temp.push_back(a);
    createModel->hide();
}

void cancelModel_CB(Fl_Widget* w, void* p) {
    createModel->hide();
}


void createModel_GUI(){
    createModel = new CreateModel_class;
    createModel->show();
    Fl::run();
}






int model_index;
int found_arm1=0;
int found_arm2=0;
int batteries;
int found_battery1 = 0;
int found_battery2 = 0;
int found_battery3 = 0;

void Cancel_add_CB();
void submit_part_CB(){
    if(strcmp(models_temp.at(model_index).has("torso").c_str(),torso_to_add->value())&& strcmp(models_temp.at(model_index).has("torso").c_str(),"default"))
    {
        Torso t = parts_temp.get_torso_by_name(torso_to_add->value());
        models_temp.at(model_index).add(t);
    }
    if(strcmp(models_temp.at(model_index).has("head").c_str(),head_to_add->value()) && strcmp(models_temp.at(model_index).has("head").c_str(),"default"))
    {
        Head h = parts_temp.get_head_by_name(head_to_add->value());
        models_temp.at(model_index).add(h);
    }
    if(strcmp(models_temp.at(model_index).has("l").c_str(),locomotor_to_add->value())&& strcmp(models_temp.at(model_index).has("l").c_str(),"default"))
    {
        Locomotor l = parts_temp.get_locomotor_by_name(locomotor_to_add->value());
        models_temp.at(model_index).add(l);
    }
    if(!found_arm1){
        Arm arm1 = parts_temp.get_arm_by_name(arm1_to_add->value());
        models_temp.at(model_index).add(arm1);
        found_arm1=1;
    }
    if(!found_arm2){
        Arm arm2 = parts_temp.get_arm_by_name(arm2_to_add->value());
        models_temp.at(model_index).add(arm2);
        found_arm2=1;
    }
    if(!found_battery1 && batteries > 0){
        Battery bat1 = parts_temp.get_battery_by_name(battery_to_add->value());
        models_temp.at(model_index).add(bat1);
        found_battery1=1;
    }
    if(!found_battery2 && batteries > 1){
        Battery bat2 = parts_temp.get_battery_by_name(battery2_to_add->value());
        models_temp.at(model_index).add(bat2);
        found_battery2=1;
    }
    if(!found_battery3 && batteries > 2 ){
        Battery bat3 = parts_temp.get_battery_by_name(battery3_to_add->value());
        models_temp.at(model_index).add(bat3);
        found_battery3=1;
    }
    Submit->hide();
    
    Cancel ->callback((Fl_Callback *) Cancel_add_CB, 0);
    Cancel->label("Continue");
}

void check_batteries(){
    if(strcmp(models_temp.at(model_index).has("torso").c_str(),"")){
        Torso a = parts_temp.get_torso_by_name(torso_to_add->value());
        batteries = a.get_battery_compartments();
        show_batteries_button->show();
        if(batteries == 3){
            battery_to_add->show();
            battery2_to_add->show();
            battery3_to_add->show();
            if(strcmp(models_temp.at(model_index).has("battery").c_str(),""))
            {
                char battery1[100];
                strcpy(battery1, models_temp.at(model_index).has("battery").c_str());
                char* battery2;
                char* battery3;
                int i = 0;
                while(battery1[i] != ',')
                {
                    i++;
                }
                battery2 = &battery1[i+1];
                i+=2;
                while(battery1[i] != ',')
                {
                    i++;
                }
                battery3 = &battery1[i+1];
                
                
                for(i=0;i<sizeof(battery1);i++)
                    if(battery1[i] == ',') battery1[i] = '\0';
                
                if(strcmp(battery1,""))
                {
                    found_battery1 = 1;
                    battery_to_add->value(battery1);
                    battery_to_add->readonly(1);
                    battery_to_add->textcolor(FL_RED);
                }
                
                if(strcmp(battery2,""))
                {
                    found_battery2 = 1;
                    battery2_to_add->value(battery2);
                    battery2_to_add->readonly(1);
                    battery2_to_add->textcolor(FL_RED);
                }
                if(strcmp(battery3,""))
                {
                    found_battery3 = 1;
                    battery3_to_add->value(battery3);
                    battery3_to_add->readonly(1);
                    battery3_to_add->textcolor(FL_RED);
                    show_batteries_button->hide();
                }
            }
        }
        if(batteries == 2){
            found_battery3 = 1;
            battery_to_add->show();
            battery2_to_add->show();
            if(strcmp(models_temp.at(model_index).has("battery").c_str(),""))
            {
                char battery1[100];
                strcpy(battery1, models_temp.at(model_index).has("battery").c_str());
                char* battery2;
                int i = 0;
                while(battery1[i] != ',')
                {
                    i++;
                }
                battery2 = &battery1[i+1];
                
                
                for(i=0;i<sizeof(battery1);i++)
                    if(battery1[i] == ',') battery1[i] = '\0';
                
                if(strcmp(battery1,""))
                {
                    found_battery1 = 1;
                    battery_to_add->value(battery1);
                    battery_to_add->readonly(1);
                    battery_to_add->textcolor(FL_RED);
                }
                
                if(strcmp(battery2,""))
                {
                    found_battery2 = 1;
                    battery2_to_add->value(battery2);
                    battery2_to_add->readonly(1);
                    battery2_to_add->textcolor(FL_RED);
                    show_batteries_button->hide();
                }
            }
        }
        if(batteries == 1){
            found_battery3 = 1;
            found_battery2 = 1;
            battery_to_add->show();
            if(strcmp(models_temp.at(model_index).has("battery").c_str(),""))
            {
                char battery1[100];
                strcpy(battery1, models_temp.at(model_index).has("battery").c_str());
                char* battery2;
                int i = 0;
                
                for(i=0;i<sizeof(battery1);i++)
                    if(battery1[i] == ',') battery1[i] = '\0';
                
                if(strcmp(battery1,""))
                {
                    found_battery1 = 1;
                    battery_to_add->value(battery1);
                    battery_to_add->readonly(1);
                    battery_to_add->textcolor(FL_RED);
                    show_batteries_button->hide();
                }
            }
        }
    }
}

void submit_CB(Fl_Widget* w, void* p){
    int j;
    int found= 0;
    found_arm1 = 0;
    found_arm2 = 0;
    batteries = 0;
    found_battery1 = 0;
    found_battery2 = 0;
    found_battery3 = 0;
    model_index=0;
    
    for(j = 0; j < models_temp.size();j++) {
        if(strcmp(name->value(),models_temp.at(j).getName().c_str()) == 0){model_index = j;found = 1; j = models_temp.size();}
    }
    if(found){
        Header->show();
        name ->hide();
        if(strcmp(models_temp.at(model_index).has("head").c_str(),"") && strcmp(models_temp.at(model_index).has("head").c_str(),"default"))
        {
            head_to_add->show();
            head_to_add->readonly(1);
            head_to_add->textcolor(FL_RED);
            head_to_add->value(models_temp.at(model_index).has("head").c_str());
        }
        else
        {
            show_heads_button->show();
            head_to_add->show();
        }
        
        if(strcmp(models_temp.at(model_index).has("torso").c_str(),"")&& strcmp(models_temp.at(model_index).has("torso").c_str(),"default"))
        {
            torso_to_add->show();
            torso_to_add->readonly(1);
            torso_to_add->textcolor(FL_RED);
            torso_to_add->value(models_temp.at(model_index).has("torso").c_str());
        }
        else
        {
            show_torsos_button->show();
            torso_to_add->show();
        }
        
        if(strcmp(models_temp.at(model_index).has("l").c_str(),"")&& strcmp(models_temp.at(model_index).has("l").c_str(),"default"))
        {
            locomotor_to_add->show();
            locomotor_to_add->readonly(1);
            locomotor_to_add->textcolor(FL_RED);
            locomotor_to_add->value(models_temp.at(model_index).has("l").c_str());
        }
        else
        {
            show_locomotors_button->show();
            locomotor_to_add->show();
        }
        show_arms_button->show();
        arm1_to_add->show();
        arm2_to_add->show();
        if(strcmp(models_temp.at(model_index).has("arm").c_str(),""))
        {
            
            char arm1[100];
            strcpy(arm1, models_temp.at(model_index).has("arm").c_str());
            char* arm2;
            int i = 0;
            while(arm1[i] != ',')
            {
                i++;
            }
            arm2 = &arm1[i+1];
            
            for(i=0;i<sizeof(arm1);i++)
                if(arm1[i] == ',') arm1[i] = '\0';
            
            if(strcmp(arm1,""))
            {
                found_arm1 = 1;
                arm1_to_add->value(arm1);
                arm1_to_add->readonly(1);
                arm1_to_add->textcolor(FL_RED);
            }
            
            if(strcmp(arm2,""))
            {
                found_arm2 = 1;
                arm2_to_add->value(arm2);
                arm2_to_add->readonly(1);
                arm2_to_add->textcolor(FL_RED);
                show_arms_button->hide();
            }
        }        check_batteries();
    }
    Submit->callback((Fl_Callback *)submit_part_CB, 0);
}
void Cancel_add_CB(){
    name->hide();
    Submit->hide();
    Cancel->hide();
    //hide input boxes
    head_to_add->hide();
    torso_to_add->hide();
    arm2_to_add->hide();
    arm1_to_add->hide();
    locomotor_to_add->hide();
    battery_to_add->hide();
    battery2_to_add->hide();
    battery3_to_add->hide();
    //set buttons back to unread only
    head_to_add->readonly(0);
    torso_to_add->readonly(0);
    arm2_to_add->readonly(0);
    arm1_to_add->readonly(0);
    locomotor_to_add->readonly(0);
    battery_to_add->readonly(0);
    battery2_to_add->readonly(0);
    battery3_to_add->readonly(0);
    //set color to black
    head_to_add->textcolor(FL_BLACK);
    torso_to_add->textcolor(FL_BLACK);
    arm2_to_add->textcolor(FL_BLACK);
    arm1_to_add->textcolor(FL_BLACK);
    locomotor_to_add->textcolor(FL_BLACK);
    battery_to_add->textcolor(FL_BLACK);
    battery2_to_add->textcolor(FL_BLACK);
    battery3_to_add->textcolor(FL_BLACK);
    //hide buttons
    show_arms_button->hide();
    show_heads_button->hide();
    show_torsos_button->hide();
    show_locomotors_button->hide();
    show_batteries_button->hide();
    Header->hide();
    
    Submit->callback((Fl_Callback *)submit_CB, 0);
}

void addParts(){
    
    name->align(FL_ALIGN_LEFT);
    name->show();
    Submit->show();
    Cancel->show();
    Cancel->label("Cancel");
    
    Submit->callback((Fl_Callback *)submit_CB, 0);
    Cancel ->callback((Fl_Callback *) Cancel_add_CB, 0);
    
}


