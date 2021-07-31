

### [ Permutation with Spaces ](https://practice.geeksforgeeks.org/problems/permutation-with-spaces3627/1#)
Author:@Siddharth Akar<br>
Problem Statement:


## Approach1

``` cpp
class Solution{
public:
    void solve(int ind,string s,vector<string>& res,string r,int n){
        if(ind==n)
        {
            res.push_back(r);
            return ;
        }
        for(int i=ind;i<n;i++){
            r+=s[i];
            if(i==n-1)
                solve(i+1,s,res,r,n);
            else
                solve(i+1,s,res,r+" ",n);
        }
        
    }
    vector<string> permutation(string S){
        // Code Here
        int n=S.size();
        vector<string>res;
        solve(0,S,res,"",n);
        sort(res.begin(),res.end());
        return res;
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
