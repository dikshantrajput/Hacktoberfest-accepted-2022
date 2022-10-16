// https://practice.geeksforgeeks.org/problems/twice-counter4236/1

class Solution
{
    public:
        int countWords(string list[], int n)
        {
           map<string,int>m;
           for(int i=0;i<n;i++){
               m[list[i]]++;
           }
           int cnt=0;
           for(auto it=m.begin();it!=m.end();it++){
               if((*it).second==2){
                   cnt++;
               }
           }
           return cnt;
        }

};