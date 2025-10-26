#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <set>
#include <algorithm>
#include <chrono>
#include <iomanip>
#include <string>
using namespace std;
using namespace std::chrono;

int main() {
    // temporary test containers (have to use these later)
    vector<string> vec;
    list<string> lst;
    set<string> st;

    cout << "*** DATA STRUCTURES RACES ***" << endl;


    // Read Race
    string code;
    ifstream fin;
    auto start = high_resolution_clock::now();
    auto end = high_resolution_clock::now();

    // Vector Read
    fin.open("codes.txt")
    start = high_resolution_clock::now();
    while (fin >> code) {
        vec.push_back(code);
    }





    // testing out the chrono timing test
    auto start = high_resolution_clock::now();

    // to test stopwatch
    for (int i = 0; i < 100000; ++i) {
        vec.push_back(to_string(i));
    }
    // ends the timing 
    auto end = high_resolution_clock::now();
    // sees how long the duration is
    auto duration = duration_cast<microseconds>(end - start);

    // output time in microseconds 
    cout << "Example chrono check: " << duration.count()
         << " microseconds" << endl;

    return 0;
}
