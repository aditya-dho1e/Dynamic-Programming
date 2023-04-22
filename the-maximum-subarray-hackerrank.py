# We define subsequence as any subset of an array. We define a subarray as a contiguous subsequence in an array.

# Given an array, find the maximum possible sum among:

# all nonempty subarrays.
# all nonempty subsequences.
# Print the two values as space-separated integers on one line.


def maxSubarray(arr):
    # Write your code here
    ans=[]
    maxi = -1*sys.maxsize - 1
    
    #kadane for max subarray sum
    sum=0
    for i in arr:
        sum+=i
        
        if sum>maxi:
            maxi=sum
        
        if sum<0:
            sum=0
    
    ans.append(maxi)
    
    #sum of subsets for max subseq sum
    arr.sort(reverse=True)
    
    dp=[arr[0]]
    
    for i in range(1,len(arr)):
        
        dp.append( max(arr[i]+dp[i-1],dp[i-1]) )
        
    ans.append(dp[len(arr)-1])
    
    return ans
