/*------------------Shivam Sharma----------------*/
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
#define FIO ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
#define int long long
#define vi vector<int>
#define pi pair<int,int>
#define vllb vector<bool>
#define uset unordered_set<int>
#define pb push_back
#define ff first
#define ss second
#define mod 1000000007
#define md 998244353
using namespace std;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;


int inv(int i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;}

int mod_mul(int a, int b) {a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}
 
int mod_add(int a, int b) {a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod;}
 
int gcd(int a, int b) { if (b == 0) return a; return gcd(b, a % b);}
 
int ceil_div(int a, int b) {return a % b == 0 ? a / b : a / b + 1;}

int power(int x,int y)
{
    int res = 1;     
    
    x = x; 
    if (x == 0) return 0; 
 
    while (y > 0)
    {
        if (y & 1)
            res = res*x;
        y = y>>1;
        x = x*x;
    }
    return res;
}

int32_t main() {
    // your code goes here
    FIO
    
    int n;
    cin>>n;
    int a[n];
    int b[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    
    sort(b,b+n);
    int ans=(b[0]+1)/2;
    ans+=(b[1]+1)/2;

    for(int i=0;i<n-2;i++){
        int temp=(a[i]+a[i+2]+1)/2;
        ans=min(temp,ans);
    }
    for(int i=0;i<n-1;i++){
        int x=min(a[i],a[i+1]);
        int y=max(a[i],a[i+1]);
        if(y>=2*x)
        {
            int temp=(y+1)/2;
            ans=min(ans,temp);
        }
        else{
            int temp=(x+y+2)/3;
            ans=min(ans,temp);
        }
    }
    cout<<ans;
        
}
 