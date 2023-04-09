class Solution {
  public:
  
    int f(int i, int k, vector<int>&arr,vector<int>&dp){
        if(i==0) return 0;
        
        if(dp[i]!=-1) return dp[i];
        
        int mini=1e9;
        
        for(int j=1;j<=k;j++){
            if(i-j>=0) mini = min(mini, abs(arr[i]-arr[i-j])+f(i-j,k,arr,dp) );
        }
        
        return dp[i]=mini;
    }
  
    int minimizeCost(vector<int>&arr, int n, int k) {
        // Code here
        vector<int>dp(n+1);
        
        //tabulation
        for(int i=1;i<n;i++){
            int mini=1e8;
            for(int j=1;j<=k;j++){
                if(i-j>=0){
                    mini = min(mini, abs(arr[i]-arr[i-j])+dp[i-j]);
                }
            }
            dp[i]=mini;
        }
        
        
        return dp[n-1];
        
        //memoization
        //vector<int>dp(n+1,-1);
        return f(n-1,k,arr,dp);
    }
};
