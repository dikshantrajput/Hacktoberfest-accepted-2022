#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    for(int i=0;i<s.size();){
        if(s[i]=='.' && s[i-1]!='-'){
            cout<<0;
            i=i+1;
        }
        else if(s[i]=='.' && s[i-1]=='-' && s[i-2]=='-'){
            cout<<0;
            i=i+1;
        }
        else if(s[i]=='-' && s[i+1]=='.'){
            cout<<1;
            i=i+2;
        }
        else if(s[i]=='-' && s[i+1]=='-'){
            cout<<2;
            i=i+2;
        }
    }
    cout<<endl;
}
