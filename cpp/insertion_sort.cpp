#include<iostream>
#include<vector>
using namespace std;

void input(vector<int>&arr)
{
    for(int i = 0; i < arr.size(); ++i)
    {
        int element;
        cin>>element;
        arr[i] = element;
    }
}

void output(vector<int>arr)
{
    for(int i = 0; i < arr.size(); ++i)
        cout<<arr[i]<<" ";
}

void insertion_sort(vector<int>&arr)
{
    for(int i = 1; i < arr.size(); ++i)
    {
        int item = arr[i];
        int j = i - 1;
        while(j >= 0)
        {
            if(arr[j] > item)
                swap(arr[j], arr[j + 1]);
            else
                break;
            --j;
        }
    }
}
int main()
{
    int n;
    cout<<"Enter number of elements : ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter "<<n<<" elements into array : ";
    input(arr);
    insertion_sort(arr);
    cout<<"Sorted array : ";
    output(arr);
    return 0;
}
