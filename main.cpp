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

// adding constants
const int NUM_RUNS = 15;
const int NUM_OPER = 4;
const int NUM_STRUCT = 3;
const string DATA_FILE = "codes.txt";

int main() {
//
long long results[NUM_RUNS][NUM_OPER][NUM_STRUCT] = {0};

cout << "*** DATA STRUCTURES RACES (Milestone 2) ***\n";
cout << "Running " << NUM_RUNS << " simulations...\n\n";

for (int r = 0; r < NUM_RUNS; r++) {
    // fresh containers each run
    vector<string> vec;
    list<string> lst;
    set<string>  st;

    // Read race 
    string code;
    ifstream fin;

    // Vector Read
    fin.open(DATA_FILE);
    if (!fin) {cerr << "Error: Couldnt open " << DATA_FILE << " for vector .\n"; return 1;}
    auto start = high_resolution_clock::now();
    while (fin >> code) vec.push_back(code);
    auto end = high_resolution_clock::now();
    auto vec_read = duration_cast<microseconds>(end - start).count();
    fin.close();

    // List Read
    fin.open(DATA_FILE);
    if (!fin) {cerr << "Error: Couldnt open " << DATA_FILE << " for list .\n"; return 1;}
    start = high_resolution_clock::now();
    while (fin >> code) lst.push_back(code);
    end = high_resolution_clock::now();
    auto lst_read = duration_cast<microseconds>(end - start).count();
    fin.close();

    // Set read
    fin.open(DATA_FILE);
    if (!fin) {cerr << "Error: Couldnt open " << DATA_FILE << " for set .\n"; return 1;}
    start = high_resolution_clock::now();
    while (fin >> code) st.insert(code);
    end = high_resolution_clock::now();
    auto set_read = duration_cast<microseconds>(end - start).count();
    fin.close();



    // Sort Race
    start = high_resolution_clock::now();
    sort(vec.begin(), vec.end());
    end = high_resolution_clock::now();
    results[r][1][0] = duration_cast<microseconds>(end - start).count();

    start = high_resolution_clock::now();
    lst.sort();
    end = high_resolution_clock::now();
    results[r][1][1] = duration_cast<microseconds>(end - start).count();
    
    // The set is already sorted by definition
    results[r][1][2] = -1;

    
// Insert Race
string newCode = "TESTCODE";

// Vector Inset
start = high_resolution_clock::now();
vec.insert(vec.begin() + vec.size() / 2, newCode);
end = high_resolution_clock::now();
results[r][2][0] = duration_cast<microseconds>(end - start).count();

// List insert 
auto it = lst.begin();
advance(it, lst.size() / 2);
start = high_resolution_clock::now();
lst.insert(it, newCode);
end = high_resolution_clock::now();
results[r][2][1] = duration_cast<microseconds>(end - start).count();

// Set insert 
start = high_resolution_clock::now();
st.insert(newCode);
end = high_resolution_clock::now();
results[r][2][2] = duration_cast<microseconds>(end - start).count();


    // Delete Race 
    start = high_resolution_clock::now();
    vec.erase(vec.begin() + vec.size() / 2);
    end = high_resolution_clock::now();
    results[r][3][0] = duration_cast<microseconds>(end - start).count();

    it = lst.begin();
    advance(it, lst.size() / 2);
    start = high_resolution_clock::now();
    lst.erase(it);
    end = high_resolution_clock::now();
    results[r][3][1] = duration_cast<microseconds>(end - start).count();

    auto sit = st.begin();
    advance(sit, st.size() / 2);
    start = high_resolution_clock::now();
    st.erase(sit);
    end = high_resolution_clock::now();
    results[r][3][2] = duration_cast<microseconds>(end - start).count();

}
    cout << "\nAll races complete!" << endl;
    return 0;
}




