

### []()
Author:@Siddharth Akar<br>
Problem Statement:


## Approach1

``` cpp
class Solution{
public:
    int dp[501][501];
    int solve(int x,int y,vector<vector<int>>& mat,int n){
        if(dp[x][y]!=-1)
            return dp[x][y];
        
        int op1=mat[x][y],op2=mat[x][y],op3=mat[x][y];
        if(x+1<n)
            op1+=solve(x+1,y,mat,n);
        if(x+1<n and y-1>=0)
            op2+=solve(x+1,y-1,mat,n);
        if(x+1<n and y+1<n)
            op3+=solve(x+1,y+1,mat,n);
        return dp[x][y]=max(op1,max(op2,op3));
        
    }
    int maximumPath(int N, vector<vector<int>>& Matrix)
    {
        memset(dp,-1,sizeof(dp));
        int res=INT_MIN;
        for(int i=0;i<N;i++)
            res=max(res,solve(0,i,Matrix,N));
        return res;
        // code here
    }
};

```

## Approach2

``` cpp

```
## Approach3

``` cpp

```
## Approach4

``` cpp

```
## Approach5

``` cpp

```
