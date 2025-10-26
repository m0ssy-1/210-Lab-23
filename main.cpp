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
    bool again;

    string names[SZ_NAMES], colors[SZ_COLORS];

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    if (!fin) {
        cerr << "Error: names.txt not found!";
        return 1;
    }

    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();




    return 0;
}
