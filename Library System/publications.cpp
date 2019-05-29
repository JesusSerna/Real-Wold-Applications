#include "publications.h"



String Publication::get_title(){
    return title;
};
String Publication::get_author(){
    return author;
};
String Publication::get_CRyear(){
    return CRyear;
};
String Publication::get_genre(){
    return genre;
};
String Publication::get_media(){
    return media;
};
String Publication::get_age(){
    return age;
};
String Publication::get_isbn(){
    return isbn;
};
bool Publication::is_checked_out(){
    return checked_out;
};
String Publication::get_customer(){
    if(checked_out)
        return customer;
    return "";
};
String Publication::get_phone(){
    if(checked_out)
        return phone;
    return "";
};
void Publication::checkout(String cust, String phone_number){
    checked_out = true;
    customer = cust;
    phone = phone_number;
    
};
void Publication::checkin(){
    checked_out = false;
    phone = "";
    customer = "";
};