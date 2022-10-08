#include <iostream>

using namespace std;

/*
 * The function accepts STRING s as parameter in the format like "07:05:45PM".
 * The function is expected to return a STRING in the format like "19:05:45".
 */

string timeConversion(string s) {
    int hr = 0;
    string ans = "";
    hr = ((s[0]-'0')*10) + (s[1]-'0');
    if(s[8] == 'P' && s[9] == 'M' && hr == 12){
        ans = to_string(hr);
    }
    else if(s[8] == 'P' && s[9] == 'M'){
        int p = hr+12;
        ans = to_string(p);
    }
    else if(s[8] == 'A' && s[9]=='M' && hr==12){
        ans = "00";
    } 
    else{
        ans += s[0];
        ans += s[1];
    }
    
    for(int i=2; i<8; i++){
            ans+=s[i];
    }
    return ans;
}

int main(){
    string s;
    getline(cin, s);

    string result = timeConversion(s);

    cout << result << "\n";

    return 0;
}
