// We consider two strings to be anagrams of each other if the first string's letters can be rearranged to form the second string. 
// In other words, both strings must contain the same exact letters in the same exact frequency. 
// For example, bacdc and dcbac are anagrams, but bacdc and dcbad are not.

// Alice is taking a cryptography class and finding anagrams to be very useful.
// She decides on an encryption scheme involving two large strings where encryption is dependent on the minimum number of character 
// deletions required to make the two strings anagrams. Can you help her find this number?

// E.g.
// s1=abc
// s2=cde
// output: 6

int makingAnagrams(string s1, string s2) {
    
    int m=s1.size(),n=s2.size();
    
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    
    vector<vector<int>> dp(m+1, vector<int>(n+1,-1));
    
    for(int i=0;i<=m;i++){
        dp[i][0]=i;
    }
    
    for(int j=0;j<=n;j++){
        dp[0][j]=j;
    }
    
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j]=min(
                    2+dp[i-1][j-1],
                    min(
                        1+dp[i-1][j],
                        1+dp[i][j-1]
                    )
                );
            }
            
        }
    }
    
    return dp[m][n];
}
