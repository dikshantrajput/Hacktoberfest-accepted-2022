/* आलस्यं हि मनुष्याणां शरीरस्थो महान् रिपुः।
नास्त्युद्यमसमो बन्धुः कृत्वा यं नावसीदति।। 
*You are only entitled to the ACTION, 
.. NEVER to its fruits*.. 
*You are what you BELIEVE in. 
and You become that which you believe YOU can BECOME..*/

/* Author- Amar Singh */
#include "bits/stdc++.h"
using namespace std;

void TOH(int n, char A, char B, char C)
{
    if(n>0)
    {
        TOH(n-1, A, C, B);
        cout << "Move disk " << n << " from " << A << " --> " << C <<"\n";
        TOH(n-1, B, A, C);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;   /* No. of disks */
    TOH(n, 'A', 'B', 'C');    
}