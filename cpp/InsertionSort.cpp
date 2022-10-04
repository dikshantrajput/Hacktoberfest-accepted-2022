/*
Insertion sort
its like a game of card where you sort the previous
stacka and just add new one and finds its position
in the previous stack

*Approach
1. we will consider index 0 array as sorted array
2. take next element and find its position in its index - 1 array
*/

//includes
#include<iostream>

//name space
using namespace std;

//To transverse the array
void Transverse(int arr[], int size);

//To sort the array using Insertion sort
void Sort(int arr[], int size);

int main()
{
    int arr[10] = {21, 323,34, 250, 98, 65, 101, 17, 12, 0};
    //Array to be sort

    Transverse(arr, 10);

    Sort(arr, 10);

    Transverse(arr, 10);

    return 0;
}

//Defination of all the functions

void Transverse(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
}


void Sort(int arr[], int size)
{
    int main_loop = 1;
    //Main loop or parent loop from 1 to size - 1

    int sub_loop = main_loop - 1;
    //sub loop from main_loop -1 to 0

    while(main_loop < size)
    {
        int value = arr[main_loop];
        //value at main_loop index

        while(sub_loop >= 0 && arr[sub_loop] > value)
        {
           arr[sub_loop + 1] = arr[sub_loop];
           sub_loop--;
        }
        arr[++sub_loop] = value;
        //Now put the value to the right place

        main_loop++;
        //Update the value of main_loop variable

        sub_loop = main_loop - 1;
        //Update the va;ue of sub_loop

    }
}


