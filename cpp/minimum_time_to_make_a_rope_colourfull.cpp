#include<iostream>
#include<string.h>

using namespace std;

// using array
// int balloon_color_check(char[], int[], int);

// int main(){
//     int n;
//     cin>>n;

    
//     char colourfull_balloons[n];
//     for(int i = 0; i<n ; i++){
//         cin>>colourfull_balloons[i];
//     }
//     int time_taken[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin>>time_taken[i];
//     }

//     int min_time = balloon_color_check(colourfull_balloons, time_taken, n);
//     cout<<min_time;

    
// }

// int balloon_color_check(char colourfull_balloons[], int time_taken[], int n){
//     int min_time = 0;
//     for(int i = 0; i<n; i++){
//         if(colourfull_balloons[i] == colourfull_balloons[i+1]){
//             if(time_taken[i] > time_taken[i+1]){
//                 min_time += time_taken[i+1];
//             }
//             else{
//                 min_time += time_taken[i];
//             }
//         }
//     }
//     return min_time;
// }
// using string
int balloon_color_check(string, int[], int);

int main(){
    int n;
    cin>>n;

    
    string colourfull_balloons;
    cin>>colourfull_balloons;
    
    int time_taken[n];
    for (int i = 0; i < n; i++)
    {
        cin>>time_taken[i];
    }

    int min_time = balloon_color_check(colourfull_balloons, time_taken, n);
    cout<<min_time;

    
}

int balloon_color_check(string colourfull_balloons, int time_taken[], int n){
    int min_time = 0;
    for(int i = 0; i<n; i++){
        if(colourfull_balloons[i] == colourfull_balloons[i+1]){
            if(time_taken[i] > time_taken[i+1]){
                min_time += time_taken[i+1];
            }
            else{
                min_time += time_taken[i];
            }
        }
    }
    return min_time;
}
