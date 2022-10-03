#include<bits/stdc++.h>
#include<iostream>
using namespace std;
vector<string> valid;
void generate(string s,int open,int close){
	if(open==0 && close==0){
		valid.push_back(s);
		return ;
	}
	if(close>0){
		if(open<close){
            s.push_back(')');
			generate(s,open,close-1);
			s.pop_back();
		}
	}
	if(open>0){
		s.push_back('(');
		generate(s,open-1,close);
		s.pop_back();
	}
}
int main(){
	int n;
	cin>>n;
	generate("",n,n);
	for(auto l:valid){
		cout<<l<<endl;
	}
}