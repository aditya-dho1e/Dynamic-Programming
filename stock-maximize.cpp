// Each day, you can either buy one share of WOT,
// sell any number of shares of WOT that you own, or not make any transaction at all. What is the maximum profit you can obtain with an optimum trading strategy?

// STDIN       Function
// -----       --------
// 3           q = 3
// 3           prices[] size n = 3
// 5 3 2       prices = [5, 3, 2]
// 3           prices[] size n = 3
// 1 2 100     prices = [1, 2, 100]
// 4           prices[] size n = 4
// 1 3 1 2     prices =[1, 3, 1, 2]
// Sample Output

// 0
// 197
// 3

long f(int i, int buy, int k,vector<int>&arr){
    
    if(i>=arr.size()) return 0;
    
    if(buy){
        int a = -arr[i]+f(i+1,0,k+1,arr);
        int b = -arr[i]+f(i+1,1,k+1,arr);
        int c = f(i+1,1,k,arr);
        return max(max(a,b),c);
    }
    else{
        return max(k*arr[i]+f(i+1,1,0,arr), f(i+1,0,k,arr));
    }
}

long stockmax(vector<int>&arr) {
    int n=arr.size();
    
    long max=arr[n-1];
    long profit=0;
    
    for(int i=n-1;i>=0;i--){
        if(arr[i]>max){
            max=arr[i];
        }
        else{
            profit+=max-arr[i];
        }
    }
    
    return profit;
}
