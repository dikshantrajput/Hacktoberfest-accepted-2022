/* creation & updation of elements of a Binary Indexed tree. 

Time complexities of various operations:
creation: O(n logn)
updating an element: O(log n)
getting sum upto a position: O(n)

Youtube link: https://www.youtube.com/watch?v=CWDQJGaN1gY&t=1206s
*/

#include <iostream>
#include <vector>

using namespace std;

int getNext(int index)
{
    int temp = ~index;
    temp++;
    temp = temp & index;    // AND with original index
    temp = temp + index;    // ADD the original index
    return temp;
}

int getParent(int index)
{
    int temp = ~index;  // 1's complement of temp
    temp ++;    // 2's complement of temp
    temp = temp & index;    // AND with original index
    temp = index - temp;
    return temp;
}

void fillSubsequent(vector<int> &binaryIndexArr, int value, int index, int maxIndex)
{    
    while(index <= maxIndex)
    {
        binaryIndexArr[index] += value;
        index = getNext(index);
    }
}

void updatePos(vector<int> &binaryIndexArr, int value, int index, int maxIndex)
{
    fillSubsequent(binaryIndexArr, value, index, maxIndex);
}

int getSum(vector<int> &binaryIndexArr, int index)
{
    int sum = 0;
    while(index > 0)
    {
        sum += binaryIndexArr[index];
        index = getParent(index);
    }
    return sum;
}

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> input(n);
        
    vector<int>binaryIndexArr(n+1, 0);
    
    for(int i=0; i<n; i++)
    {
        cin >> input[i];
        fillSubsequent(binaryIndexArr, input[i], i+1, n+1);
    }

    int type, pos, val;

    for(int i=0; i<q; i++)
    {
        cin >> type;
        if(type == 1)
        {
            cin >> pos >> val;
            val = val - input[pos];
            updatePos(binaryIndexArr, val, pos+1, n+1); 
        }
        else if(type == 2)
        {
            cin >> pos;
            cout << getSum(binaryIndexArr, pos+1) << endl;
        }
    }
    return 0;
}

// Input:
11 5
3 2 -1 6 5 4 -3 3 7 2 3
1 4 9
1 8 2
1 1 7
2 4
2 9