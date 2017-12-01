#include <iostream>
#include <string>
#include "passserver.h"



using namespace std;
using namespace cop4530;
void Menu();

int main () {
    //proj5.cpp
    size_t s;
    cout << "Enter preferred hash table capacity: ";
    cin >> s;
    PassServer h(s);
    cout << h.cap();
    char opt;

    do{
        Menu();

        cin >> opt;
        if(opt == 'l'){
            cout <<"Enter password file name to load from: ";
            char * file = new char[100];
            cin >> file;
            if(!h.load(file))
                cout << "Error: Cannot open file "<< file<<'\n';

            delete[] file;
        }else if(opt == 'a'){
            string u, p;
            cout << "Enter username: ";
            cin >> u;
            cout<< "Enter password: ";
            cin >>p;
            pair<string,string> i(u,p);
            if(h.addUser(i)){
                cout <<"User "<< u<< " added\n";
            }else{
                cout <<"*****Error: User already exists. Could not add user.\n";
            }
        }else if(opt == 'r'){
            string u;
            cout << "Enter username: ";
            cin >> u;
            if(h.removeUser(u)){
                cout << "User "<< u<< " deleted.\n";
            }else{
                cout << "*****Error: User not found.  Could not delete user\n";
            }
        }else if(opt == 'c'){
            string u, p,np;
            cout << "Enter username: ";
            cin >> u;
            cout<< "Enter password: ";
            cin >>p;
            cout<< "\nEnter new password: ";
            cin >>np;
            if(h.changePassword(pair<string,string> (u,p),np)){
                cout <<"Password changed for user "<< u<<'\n';
            }
            else{
                cout <<"*****Error: Could not change user password\n";
            }


        }else if(opt == 'f'){
            string u;
            cout << "Enter username: ";
            cin >> u;
            if(h.find(u)){
                cout <<"User '"<< u << "' found\n";
            }else{
                cout <<"User '"<< u << "' not found\n";
            }

        }else if(opt == 'd'){
            h.dump();
        }else if(opt == 's'){
            cout <<"Size of hashtable: " << h.size()<<"\n";
        }else if(opt == 'w'){
            cout <<"Enter password file name to write to:";
            char * file = new char[100];
            cin >> file;
            if(!h.write_to_file(file))
                cout << "Error: Cannot open file "<< file<<'\n';
            delete[] file;
        }else if(opt == 'x'){

        }else{
            cout <<"*****Error: Invalid entry.  Try again.\n";
        }

    }while(opt != 'x');


    //cout << "EOP" << endl;
    return 0;

}
void Menu()
{
    cout << "\n\n";
    cout << "l - Load From File" << endl;
    cout << "a - Add User" << endl;
    cout << "r - Remove User" << endl;
    cout << "c - Change User Password" << endl;
    cout << "f - Find User" << endl;
    cout << "d - Dump HashTable" << endl;
    cout << "s - HashTable Size" << endl;
    cout << "w - Write to Password File" << endl;
    cout << "x - Exit program" << endl;
    cout << "\nEnter choice : ";
}
