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

    ifstream fin2("colors.txt");
    if (!fin2) {
        cerr << "Error: colors.txt not found";
        return 1;
    }
//same changes as above
    i = 0;
    while (i < SZ_COLORS && fin2 >> colors[i]) i++;
    int num_colors = i;
    fin2.close();

list <Goat> trip;

bool running = true;
while (running) {
    int choice = main_menu();

    switch (choice) {
        case 1:
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
    cout << "something";
    cout << "something";

    while (!(cin >> choice) || choice < 1 || choice > 4) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid choice. Try again (1-4): ";
    }
    return choice;
}
//adds a goat
void add_goat(list<Goat> &trip, string names[], string colors[]) {
    string randName = names[rand() % SZ_NAMES];
    string randColor = colors[rand() % SZ_COLORS];
    int randAge = rand() % (MAX_AGE + 1);

    Goat g(randName, randAge, randColor);
    trip.push_back(g);

    cout << "goat added: " << randName << "Age: " << randAge << "Color: " << randColor << endl;
}
//deletes a goat
void delete_goat(list<Goat> &trip) {
    if (trip.empty()) {
        cout << "No goats deleted.";
        return;
    }
    
    int index = select_goat(trip);
    if (index == -1) return;

    auto it = trip.begin();
    advance(it, index - 1);
    cout << "delets sometihng" << it->get_name()
        << " " << it->get_age() << " " << it->get_color() << endl;
    trip.erase(it);
}

//select a goat
int select_goat(const list<Goat> &trip) {
    display_trip(trip);
    cout << "select a goat" << trip.size() << "0 to cancel";
    int choice;
    cin >> choice;
    if (choice == 0) return -1;
    if (choice < 1 || choice > trip.size()) {
        cout << "invalid choice";
        return -1;
    }
    return choice;
}

//displays goats
void display_trip(const list<Goat> &trip) {
    if (trip.empty()) {
        cout << "No goats this trip";
        return;
    }

    cout << "current goat";
    cout << left << setw(5) << "#" << setw(15) << "name"
         << setw(8) << "age" << setw(10) << "Color" << endl;
    cout << " ";

    int i = 1;
    for (const auto &g : trip) {
        cout << left << setw(5) << i++
             << setw(15) << g.get_name()
             << setw(8) << g.get_age()
             << setw(10) << g.get_color() << endl;
    }
}