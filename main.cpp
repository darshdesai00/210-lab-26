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

    // Read race 
    string code;
    ifstream fin;

    // Vector Read
    fin.open("codes.txt");
    auto start = high_resolution_clock::now();
    while (fin >> code) vec.push_back(code);
    auto end = high_resolution_clock::now();
    auto vec_read = duration_cast<microseconds>(end - start).count();
    fin.close();

    // List Read
    fin.open("codes.txt");
    start = high_resolution_clock::now();
    while (fin >> code) lst.push_back(code);
    end = high_resolution_clock::now();
    auto lst_read = duration_cast<microseconds>(end - start).count();
    fin.close();

    // Set read
    fin.open("codes.txt");
    start = high_resolution_clock::now();
    while (fin >> code) st.insert(code);
    end = high_resolution_clock::now();
    auto set_read = duration_cast<microseconds>(end - start).count();
    fin.close();

    // Display timing results
    cout << left << setw(12) << "Read"
         << setw(12) << vec_read
         << setw(12) << lst_read
         << setw(12) << set_read << endl;


    // Sort Race
    start = high_resolution_clock::now();
    sort(vec.begin(), vec.end());
    end = high_resolution_clock::now();
    auto vec_sort = duration_cast<microseconds>(end - start).count();

    start = high_resolution_clock::now();
    lst.sort();
    end = high_resolution_clock::now();
    auto lst_sort = duration_cast<microseconds>(end - start).count();

    // The set is already sorted by definition
    int set_sort = -1;

    cout << left << setw(12) << "Sort"
         << setw(12) << vec_sort
         << setw(12) << lst_sort
         << setw(12) << set_sort << endl;

    

// Insert Race
string newCode = "TESTCODE";

// Vector Inset
start = high_resolution_clock::now();
vec.insert(vec.begin() + vec.size() / 2, newCode);
end = high_resolution_clock::now();
auto vec_insert = duration_cast<microseconds>(end - start).count();

// List insert 
auto it = lst.begin();
advance(it, lst.size() / 2);
start = high_resolution_clock::now();
lst.insert(it, newCode);
end = high_resolution_clock::now();
auto lst_insert = duration_cast<microseconds>(end - start).count();

// Set insert 
    start = high_resolution_clock::now();
    st.insert(newCode);
    end = high_resolution_clock::now();
    auto set_insert = duration_cast<microseconds>(end - start).count();

    cout << left << setw(12) << "Insert"
         << setw(12) << vec_insert
         << setw(12) << lst_insert
         << setw(12) << set_insert << endl;


    // Delete Race 
    start = high_resolution_clock::now();
    vec.erase(vec.begin() + vec.size() / 2);
    end = high_resolution_clock::now();
    auto vec_delete = duration_cast<microseconds>(end - start).count();

    it = lst.begin();
    advance(it, lst.size() / 2);
    start = high_resolution_clock::now();
    lst.erase(it);
    end = high_resolution_clock::now();
    auto lst_delete = duration_cast<microseconds>(end - start).count();

    auto sit = st.begin();
    advance(sit, st.size() / 2);
    start = high_resolution_clock::now();
    st.erase(sit);
    end = high_resolution_clock::now();
    auto set_delete = duration_cast<microseconds>(end - start).count();

    cout << left << setw(12) << "Delete"
         << setw(12) << vec_delete
         << setw(12) << lst_delete
         << setw(12) << set_delete << endl;

    cout << "\nAll races complete!" << endl;
    
    return 0;
}



