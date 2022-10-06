#include<bits/stdc++.h>
using namespace std;

class knapsack{
    public:
    int value;
    int weight;

    knapsack(){}
    knapsack(int v, int w){
        value=v;
        weight=w;
    }
};

bool comparator(knapsack i1, knapsack i2){
    float r1= (float) i1.value/ i1.weight;
    float r2= (float) i2.value/ i2.weight;
    return r1 > r2;
}

//greedy approach
double fractionalKnapsack(knapsack* items, int n, int w){

    sort(items,items+n, comparator);

    int i=0;
    double weight=0;
    double value=0;
    while(i<n && weight < w){
        if(items[i].weight <= w- weight){
            value+= items[i].value;
            weight+= items[i].weight;
            i++;
        }else{
            int diff= w- weight;
            value+= (double)(diff*items[i].value)/items[i].weight;
            break;
        }   
    }
    return value;
}


int main(){
    int numOfItems;
    cin >> numOfItems;

    knapsack items[numOfItems];

    for(int i=0; i<numOfItems; i++){
         cin >>items[i].value;
         cin >> items[i].weight;
    }

    int maxWeight;
    cout<<"Enter max weight in knapsack\n";
    cin >> maxWeight;

    cout<<"\nMaximum possible value in knapsack is\n";
    cout << fractionalKnapsack(items, numOfItems, maxWeight)<<endl;

    return 0;
}