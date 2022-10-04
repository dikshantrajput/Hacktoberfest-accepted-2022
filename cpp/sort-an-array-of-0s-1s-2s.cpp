#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    void sort012(int arr[], int n)
    {
        //using dutch flag method
        int low = 0;
        int mid = 0 ;
        int high = n-1;
        
        while(mid <= high)
        {
            if(arr[mid] == 0)
            {
                swap(arr[mid], arr[low]);
                mid++;
                low++;
            }
            else if(arr[mid] == 1)
            {
                
                mid++;
                
            }
            else
            {
                swap(arr[mid], arr[high]);
                high--;
            }
        }
        
        
        
        
        
        //using count
    //     int zero = 0;
    //     int one = 0;
    //     int two = 0;
        
    //     // Count the number of 0s, 1s and 2s in the array
    // for (int i = 0; i < n; i++) {
    //     switch (a[i]) {
    //     case 0:
    //         zero++;
    //         break;
    //     case 1:
    //         one++;
    //         break;
    //     case 2:
    //         two++;
    //         break;
    //     }
    // }
  
    // // Update the array
    // int i = 0;
  
    // // Store all the 0s in the beginning
    // while (zero > 0) {
    //     a[i++] = 0;
    //     zero--;
    // }
  
    // // Then all the 1s
    // while (one > 0) {
    //     a[i++] = 1;
    //     one--;
    // }
  
    // // Finally all the 2s
    // while (two > 0) 
    // {
    //     a[i++] = 2;
    //     two--;
    // }
    
    
    
    
    
    
        
        //using sort function
       // return sort(a, a+n+1);
    }
    
};


int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


