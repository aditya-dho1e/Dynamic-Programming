// You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

// Return true if you can reach the last index, or false otherwise.

// Input: nums = [2,3,1,1,4]
// Output: true
// Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

class Solution {
public:
    bool f(int i,vector<int>&arr,vector<int>&dp){
        if(i==arr.size()-1)return 1;
        if(i>=arr.size())  return 0;

        if(dp[i]!=-1)return dp[i];
        
        int n=arr[i];
        for(int j=1;j<=n;j++){
            if(f(i+j,arr,dp)) return dp[i]=1;
        }
        return dp[i]=0;
    }
    bool canJump(vector<int>&arr) {
        vector<int>dp(arr.size()+1,-1);
        return f(0,arr,dp);
    }
};
