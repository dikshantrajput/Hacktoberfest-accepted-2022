#include <bits/stdc++.h>
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
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n=s.length();
        int o=n/2;
        int c=o;
        int co=0,cc=0;
        
        for(int i=0;i<n;i++){
            if(s[i]=='(')co++;
            else if(s[i]==')')cc++;
        }
        int ro=o-co;
        int rc=c-cc;
        if(ro==0 || rc==0){
            cout<<"YES"<<endl;
        }
        else{
            for(int i=0;i<n;i++){
                if(s[i]=='?'){
                    if(ro>1)
                    {
                        s[i]='(';
                        ro--;
                    }
                    else if(ro==1){
                        s[i]=')';
                        ro--;
                    }
                    else if(ro==0){
                        rc--;
                        ro--;
                        s[i]='(';
                    }
                    else if(rc>=1){
                        s[i]=')';
                        rc--;
                    }

                }
            }
            // cout<<s<<endl;
            int cnt=0;
            bool f=true;
            for(int i=0;i<n;i++){
                if(s[i]=='(')
                    cnt++;
                else
                    cnt--;

                if(cnt<0)
                    f=false;
            }
            if(cnt>0)
                f=false;

            if(f)
                cout<<"NO"<<endl;
            else
                cout<<"YES"<<endl;
        }

    }
    return 0;
}
