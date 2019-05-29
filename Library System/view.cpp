
#include "view.h"

void view( Library rvector) {
    int i = 0;
    while (rvector.records[i].get_title() != "") {
        cout << "\"" << rvector.records[i].get_title() << "\" ";
        cout << "by " << rvector.records[i].get_author() << ", " << rvector.records[i].get_CRyear() << " ";
        cout << "(" << rvector.records[i].get_age() << " "<< rvector.records[i].get_genre() << " " << rvector.records[i].get_media()<< ") ";
        if(rvector.records[i].get_isbn() != "")
            cout << "ISBN: " << rvector.records[i].get_isbn() << "\n";
        else cout << "\n";
        if(rvector.records[i].is_checked_out())
        {
            cout << "Checked out to " << rvector.records[i].get_customer() << " ("<< rvector.records[i].get_phone()<<")\n";
        }
        cout << "\n";
        i++;
    }
    
}