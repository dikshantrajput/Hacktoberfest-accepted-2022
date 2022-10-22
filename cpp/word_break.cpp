class Solution {
public:
    map<string,bool> mp;
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.length()+1,-1);
        for(int i=0;i<wordDict.size();i++){
                mp[wordDict[i]]=true;
        }
        return ans(s,0,dp);
    }
    bool ans(string &s,int i,vector<int> &dp){
        if(i>=s.length())
        return true;
        if(dp[i]!=-1)
        return dp[i]==1;

        string sp="";
        dp[i]=0;
        for(int j=i;j<s.length();j++){
            sp+=s[j];
            if(mp.find(sp)!=mp.end())
            dp[i]=dp[i]|ans(s,j+1,dp);
            if(dp[i]==true)
            return dp[i];
        }
        return dp[i]==1;
    }
};
