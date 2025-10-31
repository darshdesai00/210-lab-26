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


// results[run][operation][structure]
// run: 0–14
// operation: 0=Read, 1=Sort, 2=Insert, 3=Delete
// structure: 0=Vector, 1=List, 2=Set
long long results[NUM_RUNS][NUM_OPER][NUM_STRUCT] = {0};


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

    // belows stores the read results into the 3D array
     results[r][0][0] = vec_read;
     results[r][0][1] = lst_read;
     results[r][0][2] = set_read;



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
    


// below is that average array to store the mean times
long long avg[NUM_OPER][NUM_STRUCT] = {0};

// compute averages
for (int op = 0; op < NUM_OPER; op++) {
    for (int ds = 0; ds < NUM_STRUCT; ds++) {
        long long sum = 0;
        for (int r = 0; r < NUM_RUNS; r++) {
            sum += results[r][op][ds];
        }
        avg[op][ds] = sum / NUM_RUNS;
    }
}



// below prints the final formatted results
cout << "\nNumber of simulations: " << NUM_RUNS << endl;
cout << left << setw(12) << "Operation"
     << setw(12) << "Vector"
     << setw(12) << "List"
     << setw(12) << "Set" << endl;

string operations[NUM_OPER] = {"Read", "Sort", "Insert", "Delete"};
for (int op = 0; op < NUM_OPER; op++) {
    cout << setw(12) << operations[op];
    for (int ds = 0; ds < NUM_STRUCT; ds++) {
        cout << setw(12) << avg[op][ds];
    }
    cout << endl;
}



cout << "\nAll races complete!" << endl;
    return 0;
}
