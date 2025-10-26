#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"
#include <cstdlib>
#include <ctime>
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(const list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(const list<Goat> trip);
int main_menu();

int main() {
    srand(time(0));

    string names[SZ_NAMES], colors[SZ_COLORS];

    ifstream fin("names.txt");
    if (!fin) {
        cerr << "Error: names.txt not found";
        return 1;
    }

    int i = 0;
    //changes made to not have oiverflow and to have exact counting
    while (i < SZ_NAMES && fin >> names[i]) i++;
    int num_names = i;
    fin.close();

    ifstream fin1("colors.txt");
    if (!fin2) {
        cerr << "Error: colors.txt not found";
        return 1;
    }
//same changes as above
    i = 0;
    while (i < SZ_COLORS && fin2 >> colors[i]) i++;
    int num_colors = i;
    fin1.close();

list <Goat> trip;

bool running = true;
while (running) {
    int choice = main_menu();

    switch (choice) {
        case 1;
            add_goat(trip, names, colors);
            break;
        case 2:
            delete_goat(trip);
            break;
        case 3:
            display_trip(trip);
            break;
        case 4:
            running = false;
            cout << "goodbye";
            break;
    }
}
    return 0;
}

int main_menu() {
    int choice;
    cout << "*** GOAT MANAGER 3001 ***";
    cout << "[1] something";
    cout << "[2] something";
    cout << "[3] something";
    cout << "[4] something";
    cout << "";
    cout << "";

    while (!(cin >> choice) || choice < 1 || choice > 4) {
        cin.
    }
}