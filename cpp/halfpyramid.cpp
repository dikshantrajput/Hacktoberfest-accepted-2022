#include<bits/stdc++.h>
using namespace std;

int main(){

    int rows;
    // Getting number of rows
    cout << "Enter the Number of rows - ";
    cin >> rows;

    cout << "Triangle of " << rows << " using * -\n";

    // Main logic to print triangle. 
    for( int i = 0; i < rows; i++ ) {
        for( int j = 0; j <= i; j++ ){
            cout << "*  ";
        }
        cout<<endl;
    }
    
    return 0;
}
