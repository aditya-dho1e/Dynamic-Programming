class Solution {
  public:
  
    int f(int i, vector<int>&arr,vector<int>&dp){
        if(i==0)return 0;
        
        if(dp[i]!=-1)return dp[i];
        
        int left=abs(arr[i]-arr[i-1])+f(i-1,arr,dp);
        int right=1e8;
        if(i-2>=0){
            right=abs(arr[i]-arr[i-2])+f(i-2,arr,dp);
        }
        return dp[i]=min(left,right);
    }
  
    int minimumEnergy(vector<int>&arr, int n) {
        // Code here
        vector<int>dp(n,-1);
        return f(n-1,arr,dp);
    }
};

