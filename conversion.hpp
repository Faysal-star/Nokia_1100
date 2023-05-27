#ifndef HEAD
#define HEAD
#include<bits/stdc++.h>
using namespace std ;
#endif

// Unit Conversions
// Length and Weight are to base class
// Length => Inch , Meter , Feet
// Weight => Kg , Lbs
// convert() function takes a template T type argument
// Then it dynamic_cast into base classes to determine the data type
// Then it converts & show output according to it's data type

class Length{
    public:
    double l;
    Length(double l){
        this->l=l;
    }
    virtual double getl() = 0;
};
class Inch:public Length{
    public:
    Inch(double l):Length(l){}
    virtual double getl(){
        return l;
    }
};
class Meter:public Length{
    public:
    Meter(double l):Length(l){}
    virtual double getl(){
        return l;
    }
};
class Feet:public Length{
    public:
    Feet(double l):Length(l){}
    virtual double getl(){
        return l;
    }
};

class Weight{
    public:
    double w;
    Weight(double w){
        this->w=w;
    }
    virtual double getw() = 0;
};

class Kg:public Weight{
    public:
    Kg(double w):Weight(w){}
    virtual double getw(){
        return w;
    }
};

class Lbs:public Weight{
    public:
    Lbs(double w):Weight(w){}
    virtual double getw(){
        return w;
    }
};

template <class T>
void convert(T *a){
    Length *l = dynamic_cast<Length*>(a);
    if(l){
        Inch *in = dynamic_cast<Inch*>(a);
        if(in){
            double inc = in->getl();
            cout << "\nLength in Inch and Feet \n" ;
            cout << "--------------------------------\n" ;
            cout << inc << " in = " << inc*0.0254 << " Meter = " << inc*0.0833333 << " ft\n\n"; ;
        }
        Meter *m = dynamic_cast<Meter*>(a);
        if(m){
            double met = m->getl();
            cout << "\n Length in Meter and Feet \n" ;
            cout << "--------------------------------\n" ;
            cout << met << " Meter = " << met*39.3701 << " Inch = " << met*3.28084 << " ft\n\n";
        }
        Feet *f = dynamic_cast<Feet*>(a);
        if(f){
            double fe = f->getl();
            cout << "\nLength in Inch and Meter \n" ;
            cout << "--------------------------------\n" ;
            cout << fe << " ft = " << fe*12.00 << " Inch = " << fe*0.3048 << " Meter\n\n";
        }
    }
    else{
        Kg *k = dynamic_cast<Kg*>(a);
        if(k){
            double Kg = k->getw();
            cout << "\n Weight in Lbs \n" ;
            cout << "--------------------------------\n" ;
            cout << Kg << " Kg = " << Kg*2.20462 << " Lbs\n\n";
        }
        Lbs *p = dynamic_cast<Lbs*>(a);
        if(p){
            double pou = p->getw();
            cout << "\n Weight in Kg \n" ;
            cout << "--------------------------------\n" ;
            cout << pou << " Lbs = " << pou*0.453592 << " Kg\n\n";
        }
    }
}

void conversion(){
    system("cls");
    cout << "------Available units------" ;
    cout << "\n1. Inch\n2. Meter\n3. Feet\n4. Kg \n5. Lbs\n";
    cout << "From which unit you want to convert : ";
    int ch;
    cin >> ch;
    cout << "Enter your measured data : ";
    double l;
    cin >> l;
    if(ch == 1) convert(new Inch(l));
    else if(ch == 2) convert(new Meter(l));
    else if(ch == 3) convert(new Feet(l));
    else if(ch == 4) convert(new Kg(l));
    else if(ch == 5) convert(new Lbs(l));
    else cout << "Invalid choice\n";

    cout << "Do you want to do another conversion (Y/N) : ";
    char c;
    cin >> c;
    if(c == 'y' || c == 'Y') conversion();
}
