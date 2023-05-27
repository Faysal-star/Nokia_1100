#ifndef HEAD
#define HEAD
#include<bits/stdc++.h>
using namespace std ;
#endif
// Main Menu 

void menu(){
    cout << "\n------------------MENU------------------\n" ;
    cout << "1. Contacts\n" ;
    cout << "2. ToDo\n" ;
    cout << "3. Game\n" ;
    cout << "4. Unit Converter\n" ;
    cout << "5. Exit\n" ;
    cout << "----------------------------------------\n" ;
    cout << "Enter your choice : " ;
}

// Contacts Menu 

void contacts_operation(){
    int sub_choice ;
    do{
        system("cls") ;
        contacts_menu() ;
        cin >> sub_choice ;
        if(sub_choice == 1){
            string name , phone ;
            getline(cin , name) ;

            cout << "\nEnter name : " ;
            getline(cin , name) ;
            cout << "Enter phone : " ;
            cin >> phone ;
            Contacts *d = new Contacts(name , phone) ;
            d->append() ;
            cout << "\nContact added successfully\n" ;
            cout << "Enter any key to continue...\n" ;
            cin.ignore() ;
        }
        else if(sub_choice == 2){
            // delete
            delete_contact() ;
            cout << "\nEnter any key to continue...\n" ;
            cin.ignore() ;
        }
        else if(sub_choice == 3){
            // print
            cout << "\n**** Contacts List ****\n" ; 
            Contacts *d = new Contacts() ;
            d->viewAll() ;
            cout << "\nEnter any key to continue...\n" ;
            cin.ignore() ;
        }
        else if(sub_choice == 4){
            break ;
        }
        else{
            cout << "Invalid choice\n" ;
        }
        // cout << "Enter any key to continue : \n" ;
        cin.ignore() ;
    }while(sub_choice != 4) ;
}

// ToDo Operations 

void toDoOperation(){
    int sub_choice ;
    do{
        system("cls") ;
        ToDo_menu() ;
        cin >> sub_choice ;
        if(sub_choice == 1){
            string task , status ;
            getline(cin , task) ;
            cout << "Enter task : " ;
            getline(cin , task) ;
            cout << "Enter status : " ;
            getline(cin , status) ;
            Date *d = new Date() ;
            cin >> *d ;
            ToDo *t = new ToDo(task , status , *d) ;
            t->append() ;
            cout << "Task added successfully\n" ;
            cout << "Enter any key to continue...\n" ;
            cin.ignore() ;
        }
        else if(sub_choice == 2){
            // delete
            delete_todo();
            cout << "Enter any key to continue...\n" ;
            cin.ignore() ;
        }
        else if(sub_choice == 3){
            // update status
            update_todo() ;
            cout << "Enter any key to continue...\n" ;
            cin.ignore() ;
        }
        else if(sub_choice == 4){
            // print
            ToDo *d = new ToDo() ;
            d->viewAll() ;
            cout << "Enter any key to continue...\n" ;
            cin.ignore() ;
        }
        else if(sub_choice == 5){
            break ;
        }
        else{
            cout << "Invalid choice\n" ;
        }
        cin.ignore() ;
    }while(sub_choice != 5) ;
}


void gameOperation(){
    int sub_choice ;
    do{
        system("cls") ;
        cout << "----- Welcome to the gameZone -----\n" ;
        cout << "1. Guess the number\n" ;
        cout << "2. Rock Paper Scissors\n" ;
        cout << "3. Exit\n" ;
        cout << "Enter your choice : " ;
        cin >> sub_choice ;
        if(sub_choice == 1) guessGame() ;
        else if(sub_choice == 2) RPCgame() ;
        else if(sub_choice == 3) break ;
        else cout << "Invalid choice\n" ;
        
        cout << "Enter any key to continue... " ;
        cin.ignore() ;

    }while(sub_choice != 3) ;
}
