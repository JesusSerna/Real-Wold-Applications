
void OK_cust_CB(Fl_Widget* w, void* p)
{
    win_error->hide();
    error_display->hide();
    OK->hide();
    error_buffer->replace(7,15, "x");
}
void OK_model_CB(Fl_Widget* w, void* p)
{
    win_error->hide();
    error_display->hide();
    OK->hide();
    error_buffer->replace(7,12, "x");
}

void create_orders_CB(Fl_Widget* w, void* p);
void cancel_order_CB(Fl_Widget* w, void* p);

class New_Order_Dialog{
public:
    
    New_Order_Dialog(){
        
        dialog = new Fl_Window(340, 280, "New Order");
        
        
        sa_name = new Fl_Input(120, 5, 210, 25, "Name: ");
        sa_name->align(FL_ALIGN_LEFT);
        
        customer_name = new Fl_Input(120,35,210,25, "Customer name: ");
        customer_name->align(FL_ALIGN_LEFT);
        
        
        Model_ordered = new Fl_Input(120, 65, 210, 25, "Model ordered: ");
        Model_ordered->align(FL_ALIGN_LEFT);
        
        Order_number = new Fl_Input(120,95,210,25, "Order number: ");
        Order_number->align(FL_ALIGN_LEFT);
        
        special_requests = new Fl_Multiline_Input(120, 125, 210, 100, "Special requests: ");
        special_requests->align(FL_ALIGN_LEFT);
        
        order_create = new Fl_Return_Button(145, 250, 120, 25, "Create");
        order_create->callback((Fl_Callback *)create_orders_CB, 0);
        
        
        order_cancel = new Fl_Button(270, 250, 60, 25, "Cancel");
        order_cancel->callback((Fl_Callback *)cancel_order_CB, 0);
        
        dialog->end();
        dialog->set_non_modal();
        
    }
    void show(){dialog->show();}
    
    void hide(){dialog->hide();}
    
    string name(){
        return sa_name->value();
    }
    
    string customer(){
        return customer_name->value();
    }
    
    string model(){
        return Model_ordered->value();
    }
    
    string special(){
        return special_requests->value();
    }
    
    string order(){
        if(strcmp(Order_number->value(),"") == 0) return "0";
        return Order_number->value();
    }
    
private:
    Fl_Window *dialog;
    Fl_Input *sa_name;
    Fl_Multiline_Input *special_requests;
    Fl_Input *customer_name;
    Fl_Input *Model_ordered;
    Fl_Return_Button *order_create;
    Fl_Button *order_cancel;
    Fl_Input *Order_number;
};
New_Order_Dialog *new_order_dlg;

void cancel_order_CB(Fl_Widget* w, void* p)
{
    new_order_dlg->hide();
}
void create_orders_CB(Fl_Widget* w, void* p)
{
    int l;
    int rm;
    int customer;
    int sa;
    int found_associate = 0;
    int found_customer = 0;
    int found_model = 0;
    for(j = 0; j < sales_temp.size();j++){
        if(sales_temp[j].getName() == new_order_dlg->name()){
            found_associate = 1;
            sa = j;
            for(k = 0; k < customers_temp.size();k++){
                if(customers_temp[k].getName() == new_order_dlg->customer()){
                    found_customer = 1;
                    customer = k;
                    for(l = 0;l < models_temp.size();l++){
                        if(models_temp[l].getName() == new_order_dlg->model()){
                            found_model = 1;
                            rm = l;
                        }
                    }
                }
            }
        }
    }
    if(found_associate == 0){
        win_error->show();
        error_display->show();
        OK->callback((Fl_Callback *)OK_sa_CB, 0);
        OK->show();
        error_buffer->replace(7,8, "Sales associate");
    }
    else if(found_customer == 0){
        win_error->show();
        error_display->show();
        OK->callback((Fl_Callback *)OK_cust_CB, 0);
        OK->show();
        error_buffer->replace(7,8, "Customer");
    }
    else if(found_model == 0){
        win_error->show();
        error_display->show();
        OK->callback((Fl_Callback *)OK_model_CB, 0);
        OK->show();
        error_buffer->replace(7,8, "Model");
    }
    
    if (found_customer == 1 && found_associate == 1 && found_model == 1)
    {
        int On = stoi(new_order_dlg->order());
        int price = 0;
        
        Order a(On, price, 10, customers_temp.at(customer), sales_temp.at(sa), models_temp.at(rm));
        orders_temp.push_back(a);
        new_order_dlg->hide();
    }
    
}

void create_order_CB(Fl_Widget* w, void* p)
{
    new_order_dlg->show();
}
void quit_sales_CB(Fl_Widget* w, void* p)
{
    Window_menu->hide();
}
Fl_Menu_Item menuitems_Sales[] = {
    { "&File", 0, 0, 0, FL_SUBMENU },
    { "&Quit", FL_ALT + 'q', (Fl_Callback *)quit_sales_CB },
    { 0 },
    { "&View", 0, 0, 0, FL_SUBMENU },
    { "&Orders", 0, (Fl_Callback *)show_orders_sa_CB },
    { 0 },
    { "&Create", 0, 0, 0, FL_SUBMENU },
    { "Robot Order", 0, (Fl_Callback *)create_order_CB },
    { 0 },
    { 0 }
};

void Sales_associate_GUI(){
    Window_menu = new Fl_Window(x,y, "Sales Associate");
    Window_menu->color(FL_WHITE);
    
    menubar_PM = new Fl_Menu_Bar(0, 0, x, 30);
    menubar_PM->menu(menuitems_Sales);
    
    login_input = new Fl_Input(0,30,140,50,"Name: ");
    login_input->hide();
    Submit = new Fl_Button(0,80,140,50,"Submit");
    Submit->hide();
    
    new_order_dlg = new New_Order_Dialog();
    
    Window_menu->end();
    Window_menu->set_non_modal();
    Window_menu->show();
    
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
