class Solution {
public:
    int f(int i, int j, vector<vector<int>>&mat){
        if(i<0||j<0)return 1e5;

        if(i==0&&j==0) return mat[0][0];

        int u = mat[i][j] + f(i-1,j,mat);
        int l = mat[i][j] + f(i,j-1,mat);
        return min(u,l);
    }
    int minPathSum(vector<vector<int>>&mat) {
        int m=mat.size(),n=mat[0].size();

        vector<vector<int>>dp(m+1,vector<int>(n+1,1e5));

        dp[1][1]=mat[0][0];
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(i==1 && j==1)continue;
                else{
                    int u=mat[i-1][j-1]+dp[i-1][j];
                    int l=mat[i-1][j-1]+dp[i][j-1];
                    dp[i][j]=min(u,l);
                }
            }
        }

        return dp[m][n];
        // return f(m-1,n-1,mat);
    }
};
