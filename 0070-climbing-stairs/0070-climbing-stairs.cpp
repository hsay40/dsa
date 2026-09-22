class Solution {
public:
    int f(int index,vector<int> &dp){
        if(dp[index]!=-1){return dp[index];}
        int left = f(index-1,dp);
        int right = f(index-2,dp);
        return dp[index] =  left+right;
    }

    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        dp[0]=1;
        dp[1]=1;
        return f(n,dp);
    }
};