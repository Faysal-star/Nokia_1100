#ifndef HEAD
#define HEAD
#include<bits/stdc++.h>
using namespace std ;
#endif

// Game of Rock Paper Scissors Game
// A Player base class(Abstract) with pure virtual function
// Human and Computer are two derived class from Player
// Human play() function let's user input move
// Computer play() function randomly generate a move
// playGame() function compares both move , decide winner & increment score

class Player{
public:
    string name ;
    string hand ;
    int score ;
    Player(){
        name = "" ;
        score = 0 ;
    }
    Player(string n , int s){
        name = n ;
        score = s ;
    }
    // destructor 
    virtual ~Player() {} 
    virtual void play() = 0 ;
    virtual void print_winning() = 0 ;
};
    
class Human:public Player{
public:
    Human():Player(){}
    Human(string n , int s):Player(n , s){}
    virtual void play(){
        cout << "\nEnter your choice(R/P/S) : " ;
        cin >> hand ;
    }
    virtual void print_winning(){
        cout << "\n******* " << name << " won *******\n" ;
    }
};

class Computer:public Player{
public:
    Computer(){
        name = "AI" ;
        score = 0 ;
    }
    virtual void play(){
        int r = rand()%3 ;
        if(r == 0) hand = "R" ;
        else if(r == 1) hand = "P" ;
        else hand = "S" ;
    }
    virtual void print_winning(){
        cout << "\n******* " << name << " won *******\n" ;
    }
};

void play_game(Player &p1 , Player &p2){
    p1.play() ;
    p2.play() ;
    cout << "<----------------------------->\n" ;
    if(p1.hand[0] >= 'a' && p1.hand[0] <= 'z') p1.hand[0] -= 32 ;
    
    cout << "\t" << p1.name << " => " << p1.hand << endl ;
    cout << "\t" << p2.name << " => " << p2.hand << endl ;
    
    if(p1.hand == "R" && p2.hand == "S"){
        p1.score++ ;
        p1.print_winning() ;
    } 
    else if(p1.hand == "S" && p2.hand == "P"){
        p1.score++ ;
        p1.print_winning() ;
    }
    else if(p1.hand == "P" && p2.hand == "R"){
        p1.score++ ;
        p1.print_winning() ;
    }
    else if(p1.hand == p2.hand) cout << "**** Draw ****\n" ;
    else{
        p2.score++ ;
        p2.print_winning() ;
    }
}

void RPCgame(){
    system("cls") ;
    cout << "Welcome To Minimalistic Rock-Paper-Scissor Game\n";
    cout << "------------------------------------------------\n";
    string name ;
    getline(cin , name) ;
    cout << "Enter Your Name : " ;
    getline(cin , name) ;
    cout << "How many rounds : " ;
    int rounds ;
    cin >> rounds ;
    int tr = 0 ;
    
    Human p1(name , 0) ;
    Computer p2 ;
    
    while(tr++ < rounds){
        cout << "\n----Round " << tr << "----\n" ;
        play_game(p1 , p2) ;
    }
    
    cout << "\n\n***** Final Score ***** \n" ;
    cout << p1.name << " : " << p1.score << "\n" ;
    cout << p2.name << " : " << p2.score << "\n" ;
    cout << "\nWant to play more ? (Y/N) : " ;
    char ch ;
    cin >> ch ;
    if(ch == 'Y' || ch == 'y') RPCgame() ;
    else cout << "Thanks for playing\n" ;
}


// Number guessing game (binary search)
// This game try to find out your choosen number , using binary search method

void guessGame(){
    system("cls") ;
    cout << "Welcome To Minimalistic Number Guessing Game\n";
    cout << "--------------------------------------------\n";
    cout << "Choose a number between 1 to 1000\n";
    cout << "Are you ready :) \n" ;
    cout << "* Press Y if that is your number\n";
    cout << "* Press G if your number is greater than that\n";
    cout << "* Press L if your number is less than that\n\n";
    cin.ignore() ;
    int l = 1 , r = 1000 ;
    int tr = 1 ;
    char ch ;
    while(l <= r){
        int mid = (l+r)/2 ;
        cout << "Is your number " << mid << " ? (Y/G/L) : " ;
        cin >> ch ;
        if(ch == 'Y' || ch == 'y'){
            cout << "\n\nYess ! I guessed your number : " << mid << "\n" ;
            cout << "Though it took me " << tr << " turns\n" ;
            break ;
        }
        else if(ch == 'G' || ch == 'g') l = mid+1 ;
        else r = mid-1 ;
        tr++ ;
    }

    cout << "\nWant to play more ? (Y/N) : " ;
    cin >> ch ;
    if(ch == 'Y' || ch == 'y') guessGame() ;
    else cout << "Thanks for playing\n" ;
}