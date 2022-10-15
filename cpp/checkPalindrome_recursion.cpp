#include<bits/stdc++.h>
using namespace std;

bool checkPalindrome(string str, int i , int j){
    if(i>j)
    return true;

    if(str[i] != str[j]){
        return false;
    }
    else{
        return checkPalindrome(str, i+1, j-1);
    }

}
 
int main(){
    
    string str = "abcde";

    bool ispalindrome = checkPalindrome(str, 0 ,str.length()-1);
    
    if(ispalindrome){
        cout<<"paindrome";
    }
    else{
        cout<<"not a palindrome";  
    }


    return 0;
}