# t(i+2) = t(i) + t(i+1)**2
#calculate the value upto n terms 

def fibonacciModified(t1, t2, n):
    # Write your code here
    dp=[t1,t2]
    for i in range(2,n):
        dp.append(dp[i-2] + dp[i-1]**2)
    return dp[n-1]
