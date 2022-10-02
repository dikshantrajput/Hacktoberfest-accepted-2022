#include<bits/stdc++.h>
using namespace std;
long long int exponentiation(long long int x,long long int y)
{

    if(y==0)
    {
        return 1;
    }
   long long int res= exponentiation(x,y/2);
    res*=res;
    if(y&1)
    {
        res*=x;
    }
    return res;

}
int main()
{
    long long int x,y;
    cin>>x>>y;
    long long int ans=exponentiation( x, y);
    cout<<ans;
}
