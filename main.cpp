//COMSC-210 | Lab 23 Goat manager | Robert Stonemetz

#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(list<Goat> trip);


int main_menu() {
    int choice;
    bool valid = true;

    do{
        //menu
        cout << "***GOAT MANAGER 3001 ***" << endl;
        cout << "[1] Add a goat" << endl;
        cout << "[2] Delete a goat" << endl;
        cout << "[3] List goats" << endl;
        cout << "[4] Quit" << endl;
        cout << "Choice --> ";

        //to get user option
        if(cin >> choice) {
            if (choice >= 1 && choice <= 4) {
                valid = true;
            }else {
                //sends error message if invalid selection is made
                cout << "Error invalid option" << endl;
            }

        }else {
            cin.clear(); //for error flags
            cin.ignore(100, '\n'); //clears wrong input
            cout << "Please enter valid option" << endl;
        }


    }while (!valid);

    return choice;

};

int main() {
    srand(time(0));
    bool running = true;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();

    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();


    //list to store goats
    list <Goat> trip;

    //Loop for program

    while (running) {
        int choice = main_menu();


        switch(choice) {
            case 1: //adds goat
                add_goat(trip, names, colors);
                break;

            case 2: //deletes goat
                if (trip.empty()){
                    cout << "Error no goats to delete";
                } else {
                    delete_goat(trip);
                }
                break;

            case 3: //list the goats
                if (trip.empty()) {
                    cout << "No goats to list";
                }else {
                    display_trip(trip);
                }
                break;

            case 4: //quit
                cout << "all done";
                running = false;
                break;

        }
    }

    



    return 0;
}
