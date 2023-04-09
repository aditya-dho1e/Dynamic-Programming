class Solution {
public:
    int f(int i,vector<int>&dp){
        if(i<=1)return i;
        if(i==2)return 1;
        if(dp[i]!=-1)return dp[i];
        return dp[i]=f(i-1,dp)+f(i-2,dp)+f(i-3,dp);
    }
    int tribonacci(int n) {
        if(n<=1)return n;
        if(n==2)return 1;
        
        // memoization
        // vector<int>dp(n+1,-1);
        // return f(n,dp);
        
        //tabulation
        vector<int>dp(n+1);
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;

        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
        }

        return dp[n];
    }
};
