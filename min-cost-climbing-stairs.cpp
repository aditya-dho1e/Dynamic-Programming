// You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

// You can either start from the step with index 0, or the step with index 1.

// Return the minimum cost to reach the top of the floor.

// Input: cost = [10,15,20]
// Output: 15

class Solution {
public:
    int f(int i, vector<int>&arr,vector<int>&dp){
        if(i<0)return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i]=min(arr[i]+f(i-1,arr,dp),arr[i]+f(i-2,arr,dp));
    }
    int minCostClimbingStairs(vector<int>&arr) {
        int n=arr.size();
        vector<int>dp(n+1,-1);

        int mini=f(n-1,arr,dp);

        dp.assign(n+1,-1);
        
        return min(mini,f(n-2,arr,dp));
    }
};
