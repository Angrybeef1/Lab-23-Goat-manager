// Goat.h

#ifndef GOAT_H
#define GOAT_H
#include <iostream>
using namespace std;

class Goat {
private:
    string name;
    int age;
    string color;
public: 
    //hope you dont mind i set the code in the way i am used to seeign as the original just looks odd to me.
    //default constructor
    Goat()  { 
        name = ""; 
        age = 0; 
        color = ""; 
    }

    
    //constructor for just name
    Goat (string n) { 
        name = n; 
        age = 0; 
        color = "";
    }

    //constuctor with name and age
    Goat(string n, int a) {
        name = n; 
        age = a; 
        color = "";
    }

    //contrsutor will all parameters
    Goat(string n, int a, string c) {
        name = n; 
        age = a; 
        color = c;
    }

    // setters and getters
    void set_name(string n)         { name = n; };
    string get_name() const         { return name; };
    void set_age(int a)             { age = a; };
    int get_age() const             { return age; }
    void set_color(string c)        { color = c; }
    string get_color() const        { return color; }

    // write overloaded < operator for the std::list
    bool operator<(const Goat& other) const{
        return name < other.name;
    }
};

#endif
