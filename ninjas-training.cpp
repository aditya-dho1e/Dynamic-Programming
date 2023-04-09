class Solution {
  public:
  
    int f(int i, int j, vector<vector<int>>&arr, vector<vector<int>>&dp){
        if(i<0) return 0;
        
        if(dp[i][j+1]!=-1) return dp[i][j+1];
        
        int maxi=0;
        for(int k=0;k<3;k++){
            if(k==j)continue;
            maxi=max(maxi,arr[i][k]+f(i-1,k,arr,dp));
        }
        
        return dp[i][j+1]=maxi;
    }
  
    int maximumPoints(vector<vector<int>>&arr, int n) {
        // Code here
        vector<vector<int>>dp(n+1,vector<int>(4));
        
        //base case when reached index = 0, we need to check all maximum values
        dp[0][0]=max(arr[0][1],arr[0][2]);
        dp[0][1]=max(arr[0][0],arr[0][2]);
        dp[0][2]=max(arr[0][0],arr[0][1]);
        dp[0][3]=max(arr[0][1],max(arr[0][2],arr[0][0]));
        
        //tabulation
        for(int i=1;i<n;i++){
            for(int j=0;j<4;j++){
                
                int maxi=0;
                for(int k=0;k<3;k++){
                    if(k==j)continue;
                    maxi=max(maxi, arr[i][k]+dp[i-1][k]);
                }
                
                dp[i][j]=maxi;
            }
        }
        
        return dp[n-1][3];
        
        //memoization
        // vector<vector<int>>dp(n+1,vector<int>(4,-1));
        // return f(n-1,-1,arr,dp);
    }
};
