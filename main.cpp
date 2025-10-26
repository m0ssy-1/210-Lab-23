#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include <cstdlib>
#include <ctime>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int main_menu();
void add_goat(list<Goat> &trip, string [], string []);
void delete_goat(list<Goat> &trip);
void display_trip(const list<Goat> &trip);
int select_goat(const list<Goat> &trip);

int main() {
    srand(time(0));

    string names[SZ_NAMES], colors[SZ_COLORS];

    ifstream fin("names.txt");
    if (!fin) {
        cerr << "Error: names.txt not found\n";
        return 1;
    }

    int i = 0;
    //changes made to not have oiverflow and to have exact counting
    while (i < SZ_NAMES && fin >> names[i]) i++;
    int num_names = i;
    fin.close();

    ifstream fin2("colors.txt");
    if (!fin2) {
        cerr << "Error: colors.txt not found\n";
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
            cout << "\nGoat Manager 3001 says Goodbye~";
            break;
    }
}
    return 0;
}

int main_menu() {
    int choice;
    cout << "\n*** GOAT MANAGER 3001 ***\n";
    cout << "[1] Add a goat\n";
    cout << "[2] Delete a goat\n";
    cout << "[3] List goats\n";
    cout << "[4] Quit\n";
    cout << "Choice --> ";

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

    cout << "\nAdded goat: " << randName << " (" << randAge << ", " << randColor << ")\n";
}
//deletes a goat
void delete_goat(list<Goat> &trip) {
    if (trip.empty()) {
        cout << "\nNo goats deleted.\n";
        return;
    }
    
    int index = select_goat(trip);
    if (index == -1) return;

    auto it = trip.begin();
    advance(it, index - 1);
    cout << "Deleting " << it->get_name()
        << " (" << it->get_age() << ", " << it->get_color() << ")\n";
    trip.erase(it);
}

//select a goat
int select_goat(const list<Goat> &trip) {
    display_trip(trip);
    cout << "Select a goat to delete [1-" << trip.size() << "] (0 to cancel): ";
    int choice;
    cin >> choice;
    if (choice == 0) return -1;
    if (choice < 1 || choice > trip.size()) {
        cout << "Invalid choice.\n";
        return -1;
    }
    return choice;
}

//displays goats
void display_trip(const list<Goat> &trip) {
    if (trip.empty()) {
        cout << "\nNo goats this trip.\n";
        return;
    }

    cout << "\nCurrent Goat:\n";
    cout << left << setw(5) << "#" << setw(15) << "Name"
         << setw(8) << "Age" << setw(10) << "Color" << endl;
    cout << "-------------------------------\n";

    int i = 1;
    for (const auto &g : trip) {
        cout << left << setw(5) << i++
             << setw(15) << g.get_name()
             << setw(8) << g.get_age()
             << setw(10) << g.get_color() << endl;
    }
}