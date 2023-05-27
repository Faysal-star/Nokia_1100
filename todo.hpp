#ifndef HEAD
#define HEAD
#include<bits/stdc++.h>
using namespace std ;
#endif

// ToDo Class and Functions

// Date class is inherited from ToDo 
// Every ToDo has , Task , Date , Status (Pending/Completed)
// Data is stored in ToDo.txt file
// input output operators (<< , >>) are overloaded to take input or show output

class Date{
public :
    int day ;
    int month ;
    int year ;
    Date(){
        day = 0 ;
        month = 0 ;
        year = 0 ;
    }
    Date(int d , int m , int y){
        day = d ;
        month = m ;
        year = y ;
    }
    Date(const Date &d){
        day = d.day ;
        month = d.month ;
        year = d.year ;
    }
    friend istream &operator>>(istream &is , Date &d){
        cout << "Enter day : " ;
        is >> d.day ;
        cout << "Enter month : " ;
        is >> d.month ;
        cout << "Enter year : " ;
        is >> d.year ;
        return is ;
    }
    friend ostream &operator<<(ostream &os , Date &d){
        os << d.day << "/" << d.month << "/" << d.year << endl ;
        return os ;
    }
    void print(){
        cout << day << "/" << month << "/" << year << endl ;
    }
};

class ToDo:public Date{
public:
    string task ;
    string status ;
    ToDo(){
        task = "" ;
        status = "" ;
    }
    ToDo(string t , string s , Date d):Date(d){
        task = t ;
        status = s ;
    }
    friend ofstream &operator<<(ofstream &ofs , ToDo &d){
        ofs << d.task << endl ;
        ofs << d.status << endl ;
        ofs << d.day << endl ;
        ofs << d.month << endl ;
        ofs << d.year << endl ;
        return ofs ;
    }
    friend ifstream &operator>>(ifstream &ifs , ToDo &d){
        getline(ifs , d.task) ;
        ifs >> d.status ;
        ifs >> d.day >> d.month >> d.year ;
        ifs.ignore() ;
        return ifs ;
    }
    void print(){
        Date::print() ; 
        cout << "\t => " ;
        cout << task << " : " << status << "\n" ;
    }
    void append(){
        ofstream fin ;
        fin.open("ToDo.txt" , ios::app) ;
        fin << *this ;
    }
    void viewAll(){
        ifstream fin ;
        fin.open("ToDo.txt" , ios::in) ;
        if(!fin) cout << "File not found\n" ;
        else{
            ToDo *d = new ToDo() ;
            int idx = 1 ;
            while(fin >> *d){
                cout << idx++ << ". " ;
                d->print() ;
            }
        }
    }
};

void ToDo_menu(){
    cout << "\n----------------ToDo Menu---------------\n" ;
    cout << "1. Add\n" ;
    cout << "2. Delete\n" ;
    cout << "3. Update Status\n" ;
    cout << "4. Print\n" ;
    cout << "5. Return to main menu\n" ;
    cout << "----------------------------------------\n" ;
    cout << "Enter your choice : " ;
}

void delete_todo(){
    ToDo *d = new ToDo() ;
    d->viewAll() ;
    cout << "Enter index to delete : " ;
    int idx ;
    cin >> idx ;
    ifstream fin ;
    fin.open("ToDo.txt" , ios::in) ;
    ofstream fout ;
    fout.open("temp.txt" , ios::out) ;
    int i = 1  , f = 0;
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
        cout << " === ToDo Deleted ===\n" ;
        remove("ToDo.txt") ;
        rename("temp.txt" , "ToDo.txt") ;
        cout << "**** Updated List **** \n" ;
        d->viewAll() ;
    }
}

void update_todo(){
    ToDo *d = new ToDo() ;
    d->viewAll() ;
    cout << "Enter index to update status : " ;
    int idx ;
    cin >> idx ;
    ifstream fin ;
    fin.open("ToDo.txt" , ios::in) ;
    ofstream fout ;
    fout.open("temp.txt" , ios::out) ;
    int i = 1 , f = 0;
    while(fin >> *d){
        if(i == idx){
            cout << "Enter new status : " ;
            string status ;
            getline(cin , status) ;
            getline(cin , status) ;
            d->status = status ;
            f = 1 ;
        }
        fout << *d ;
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
        cout << " === ToDo Updated ===\n" ;
        remove("ToDo.txt") ;
        rename("temp.txt" , "ToDo.txt") ;
        cout << "**** Updated List **** \n" ;
        d->viewAll() ;
    }
}