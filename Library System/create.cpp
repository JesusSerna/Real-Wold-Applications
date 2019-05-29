
#include "create.h"
#include "string"

void create( Library *rvector) {
    String title, author, CRyear, genre, media, age, isbn;
    char input_result;
    int input, exit=0;
    cin.ignore();
    cout << "We will now create a new publication...\n\t";
    cout << "What is the title of the publication?\n\t\t";
    getline(cin,title);
    cout << "\tWho is the author?\n\t\t";
    getline(cin,author);
    cout << "\tWhat is the CopyRight year?\n\t\t";
    getline(cin,CRyear);;
    cout << "\tWhat genre is the publication?";
    while (exit == 0)
    {
        cout << "\n\t (0)fiction\n\t (1)non- fiction\n\t (2)self-help\n\t (3)performance\n\t\t";
        cin >> input;
        switch (input){
            case 0:
                genre = "fiction";
                exit = 1;
                break;
            case 1:
                genre = "non-fiction";
                exit = 1;
                break;
            case 2:
                genre = "self-help";
                exit = 1;
                break;
            case 3:
                genre = "performance";
                exit = 1;
                break;
            default:
                cout << "please enter only the options specified";
                break;
        }
    }
    exit = 0;
    cout << "\tWhat type of publication is it?";
    while (exit == 0)
    {
        cout << "\n\t (0)Book\n\t (1)Periodical\n\t (2)Newspapers\n\t (3)Audio\n\t (4)Video\n\t\t";
        cin >> input;
        switch (input){
            case 0:
                media = "book";
                exit = 1;
                break;
            case 1:
                media = "periodical";
                exit = 1;
                break;
            case 2:
                media = "newspaper";
                exit = 1;
                break;
            case 3:
                media = "audio";
                exit = 1;
                break;
            case 4:
                media = "video";
                exit = 1;
                break;;
            default:
                cout << "please enter only the options specified";
                break;
        }
    }
    cout << "\tWhat is the target age?";
    exit = 0;
    while (exit == 0)
    {
        cout << "\n\t (0)Child\n\t (1)Teen\n\t (2)Adult\n\t (3)Restricted\n\t\t";
        cin >> input;
        switch (input){
            case 0:
                age = "child";
                exit = 1;
                break;
            case 1:
                age = "teen";
                exit = 1;
                break;
            case 2:
                age = "adult";
                exit = 1;
                break;
            case 3:
                age = "restricted";
                exit = 1;
                break;
            default:
                cout << "please enter only the options specified";
                break;
        }
    }
    cout << "\tDoes the publication have an ISBN number? (Y/N)";
    cin >> input_result;
    if(input_result == 'y' || input_result == 'Y')
    {
        cout << "\t\tEnter the ISBN number.";
        cin >> isbn;
    }
    else isbn = "";
    rvector->records.push_back(Publication(title, author, CRyear, genre, media, age, isbn));
    cout << "Record created\n\n";
    
}