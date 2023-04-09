class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int f(int i, int*arr){
	    if(i==0) return arr[0];
	    if(i<0) return 0;
	    
	    return max(f(i-1,arr), arr[i]+f(i-2,arr));
	}
	
	int findMaxSum(int *arr, int n) {
	    // code here
	    vector<int>dp(n+1,0);
	    
	    dp[1]=arr[0];
	    for(int i=2;i<=n;i++){
	        dp[i]=max(dp[i-1], arr[i-1]+dp[i-2]);
	    }
	    
	    return dp[n];
	    
	   // return f(n-1,arr);
	}
};
