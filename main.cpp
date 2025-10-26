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
    // test containrs for read timings 
    vector<string> vec;
    list<string> lst;
    set<string> st;

    cout << "*** DATA STRUCTURES RACES ***" << endl;

     cout << left << setw(12) << "Operation"
         << setw(12) << "Vector"
         << setw(12) << "List"
         << setw(12) << "Set" << endl;

    // Read Race
    string code;
    ifstream fin;
    auto start = high_resolution_clock::now();
    auto end = high_resolution_clock::now();

    // Vector Read
    fin.open("codes.txt");
    start = high_resolution_clock::now();
    while (fin >> code) {
        vec.push_back(code);
    }
    end = high_resolution_clock::now();
    auto vec_read = duration_cast<microseconds>(end - start).count();
    fin.close();

    // List Read
    fin.open("codes.txt");
    start = high_resolution_clock::now();
    while (fin >> code) {
        lst.push_back(code);
    }
    end = high_resolution_clock::now();
    auto vec_read = duration_cast<microseconds>(end - start).count();
    fin.close();

    // Set read
    fin.open("codes.txt");
    start = high_resolution_clock::now();
    while (fin >> code) {
        st.insert(code);
    }
    end = high_resolution_clock::now();
    auto vec_read = duration_cast<microseconds>(end - start).count();
    fin.close();

    // Display timing results
    cout << left << setw(12) << "Read"
         << setw(12) << vec_read
         << setw(12) << lst_read
         << setw(12) << set_read << endl;


    cout << endl << "Success" << endl;

    return 0;

}