#ifndef publications_h
#define publications_h

#include "std_lib_facilities.h"

class Publication   {
public:
    
    Publication(String t, String a, String cy, String g, String m, String _age, String _isbn):
    title(t),
    author(a),
    CRyear(cy),
    genre(g),
    media(m),
    age(_age),
    isbn(_isbn){}
    
    String get_title();
    String get_author();
    String get_CRyear();
    String get_genre();
    String get_media();
    String get_age();
    String get_isbn();
    bool is_checked_out();
    String get_customer();
    String get_phone();
    void checkout(string cust,string phone_number);
    void checkin();
    
private:
    String title;
    String author;
    String CRyear;
    String genre;
    String media;
    String age;
    String isbn;
    String customer;
    String phone;
    bool checked_out = false;
};

#endif /* Header_h */
