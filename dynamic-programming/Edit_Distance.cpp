class Solution {
public:
    int min(int one,int two,int three){
        if(one<=two && one<=three){
            return one;
        }
        else if(two<=one && two<=three){
            return two;
        }
        else{
            return three;
        }
    }
    int minDistance(string word1, string word2) {
        int dp[word1.length()+1][word2.length()+1];
        for(int i=0;i<=word2.length();i++){
            dp[0][i]=i;
        }
        for(int i=0;i<=word1.length();i++){
            dp[i][0]=i;
        }
        for(int i=1;i<=word1.length();i++){
            for(int j=1;j<=word2.length();j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]=1+min(dp[i][j-1],dp[i-1][j],dp[i-1][j-1]);
                }
            }
        }
        return dp[word1.length()][word2.length()];
        
    }
};
