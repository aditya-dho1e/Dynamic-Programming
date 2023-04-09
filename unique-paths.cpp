class Solution {
public:
    int f(int i, int j, int m, int n){
        if(i<0 || j<0) return 0;
        if(i==0 && j==0) return 1;
        return f(i-1,j,m,n)+f(i,j-1,m,n);
    }
    int uniquePaths(int m, int n) {

        vector<vector<int>>dp(m+1,vector<int>(n+1));

        dp[1][1]=1;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(i==1&&j==1)continue;
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }

        return dp[m][n];
        // return f(m-1,n-1,m,n);
    }
};
