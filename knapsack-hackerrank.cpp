// Given an array of integers and a target sum, determine the sum nearest to but not exceeding the target that can be created.
// To create the sum, use any element of your array zero or more times.




int solve(int i, int t, vector<int>&arr,vector<vector<int>>&dp){
    
    if(t<0) return 1e8;
    if(t==0) return 0;
    
    if(dp[i][t]!=-1) return dp[i][t];
    
    if(i==0){
        if(t>=arr[0]) return t%arr[0];
        else return 1e8;
    }
    
    int take = solve(i,t-arr[i],arr,dp);
    int notake = solve(i-1,t,arr,dp);
    return dp[i][t]=min(t, min(take,notake));
}

int unboundedKnapsack(int t, vector<int> arr) {
    int n=arr.size();
    
    vector<vector<int>> dp(n+1,vector<int>(t+1,-1));
    
    // for(int j=1;j<=t;j++){
    //     dp[0][j] = j%arr[0];
    // }
    
    // for(int i=1;i<n;i++){
    //     for(int j=1;j<=t;j++){
    //         int take=1e8;
    //         int notake=dp[i-1][t];
    //         if(j-arr[i]>=0)take=dp[i][j-arr[i]];
    //         dp[i][j]=min(j, min(take,notake));
    //     }
    // }
    
    
    // return t - dp[n-1][t];
    return t - solve(n-1,t,arr,dp);
}
