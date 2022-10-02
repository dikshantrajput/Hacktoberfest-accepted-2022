#include <iostream>

using namespace std;


int coin_change( int n , int arr[] , int weight){


    int max[n][weight+1];

    max[n][0] = 0;


    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < weight+1; j++)
        {
            if (arr[i]=1)
            {
                max[i][j] = 1+(max[i][j-arr[1]]);
                
            }
            if(j<=arr[i]){

                max[i][j] = max[i-1][j];
            }
            else
            {
                max[i][j] = min(max[i-1][j] , 1 + max[i][j - arr[i]]);
            }
            
            







        }
        
        
    
    

 
    
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= weight+1; j++)
        {
            cout<<max[i][j] << " ";
        }

        cout<< endl;
        
    }
    




}





int main(){




int n;
    cin>>n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int weight;
    cin>>weight;

 coin_change( n , arr,  weight);





    



    return 0;
}
