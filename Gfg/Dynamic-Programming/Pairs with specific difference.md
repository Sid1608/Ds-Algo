### [Pairs with specific difference](https://practice.geeksforgeeks.org/problems/pairs-with-specific-difference1533/1)
Author:@Siddharth Akar<br>
Problem Statement:

## Approach1(Two Pointer)

``` cpp

int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
    {  
        sort(arr,arr+N);
        int i=N-2,res=0;
        while(i>=0){
            if(arr[i+1]-arr[i]<K){
                res+=arr[i+1]+arr[i];
                i-=2;
            }
            else{
                i--;
            }
        }
        return res;
    }
```

## Approach2(dp)

``` cpp
int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
    {
        // Your code goes here   
        sort(arr,arr+N);
        int dp[N];
        dp[0]=0;
        for(int i=1;i<N;i++){
            dp[i]=dp[i-1];
            if(arr[i]-arr[i-1]<K){
                if(i>=2){
                    dp[i]=max(dp[i],arr[i]+arr[i-1]+dp[i-2]);
                }
                else{
                    dp[i]=max(dp[i],arr[i]+arr[i-1]);
                }
            }
        }
        return dp[N-1];
    }
```
