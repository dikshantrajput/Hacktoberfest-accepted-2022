#include<bits/stdc++.h>
using namespace std;

int main() {
    // Pair of 2 elements
    pair<int, int> P = {3,9};
    cout << "Pair of 2 int : {" << P.first << ", " << P.second << "}" << endl;
    cin >> P.first >> P.second;
    cout << "Pair of 2 int : {" << P.first << ", " << P.second << "}" << endl;
    
    // Nested Pair
    pair<pair<int, int>, pair<int, int>> NP;
    cin >> NP.first.first >> NP.first.second >> NP.second.first >> NP.second.second;
    cout << "Pair of Nested Pairs : { {" << NP.first.first << ", " << NP.first.second << "}, {" << NP.second.first << ", " << NP.second.second << "} }" << endl;

    // Pair Array
    pair<int, int> Parr[] = {{1,2}, {2,5}, {5,1}};
    for(auto &P: Parr) {
        cout << "{" << P.first << ", " << P.second << "}" << endl;
    }
    
}
