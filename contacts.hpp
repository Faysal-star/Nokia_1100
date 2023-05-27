#ifndef HEAD
#define HEAD
#include<bits/stdc++.h>
using namespace std ;
#endif

// Contacts Class and Functions 

// Contacts class has name and phone as string
// file input (>>) & output (<<) operators are overloaded using friend function

class Contacts{
public :
    string name ;
    string phone;
    Contacts() {
        name = "" ;
        phone = "" ;
    }
    Contacts(string n , string p){
        name = n ;
        phone = p ;
    }
    Contacts(const Contacts &d){
        name = d.name ;
        phone = d.phone ;
    }
    friend ofstream &operator<<(ofstream &ofs , Contacts &d){
        ofs << d.name << endl ;
        ofs << d.phone << endl ;
        return ofs ;
    }
    friend ifstream &operator>>(ifstream &ifs , Contacts &d){
        getline(ifs , d.name) ;
        ifs >> d.phone ;
        ifs.ignore() ;
        return ifs ;
    }
    void print(){
        cout << name << " : " << phone << endl ;
    }
    void append(){
        ofstream fin ;
        fin.open("Contacts.txt" , ios::app) ;
        fin << *this ;
    }
    void viewAll(){
        ifstream fin ;
        fin.open("Contacts.txt" , ios::in) ;
        if(!fin) cout << "File not found\n" ;
        else{
            Contacts *d = new Contacts() ;
            int idx = 1 ;
            while(fin >> *d){
                cout << idx++ << ". " ;
                d->print() ;
            }
        }
    }
};

void contacts_menu(){
    cout << "\n--------------Contacts Menu--------------\n" ;
    cout << "1. Add\n" ;
    cout << "2. Delete\n" ;
    cout << "3. Print\n" ;
    cout << "4. Return to main menu\n" ;
    cout << "----------------------------------------\n" ;
    cout << "Enter your choice : " ;
}

void delete_contact(){
    cout << "\n----------------Delete Contact---------------\n" ;
    cout << "***** Previous List *****\n\n" ;
    Contacts *d = new Contacts() ;
    d->viewAll() ;
    cout << "\n\nEnter index to delete : " ;
    int idx ;
    cin >> idx ;
    ifstream fin ;
    fin.open("Contacts.txt" , ios::in) ;
    ofstream fout ;
    fout.open("temp.txt" , ios::out) ;
    int i = 1 , f = 0;
    while(fin >> *d){
        if(i != idx){
            fout << *d ;
        }
        else f = 1 ;
        i++ ;
    }
    fin.close() ;
    fout.close() ;
    if(f == 0){
        cout << "Invalid index\n" ;
        remove("temp.txt") ;
        return ;
    }
    else{
        cout << " === Contact Deleted ===\n" ;
        remove("Contacts.txt") ;
        rename("temp.txt" , "Contacts.txt") ;
        cout << "**** Updated List **** \n" ;
        d->viewAll() ;
    }
}