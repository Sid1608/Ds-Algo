

### []()
Author:@Siddharth Akar<br>
Problem Statement:


## Approach1

``` cpp
class Solution{
  public:
    int longestKSubstr(string s, int k) {
        unordered_map<char,int>p;
        int l=0,cnt=0,res=-1;
        for(int r=0;r<s.size();r++){
            p[s[r]]++;
            if(p[s[r]]==1)
                cnt++;
            while(cnt>k){
                if(p[s[l]]-1==0)
                    cnt--;
                p[s[l]]--;
                l++;
            }
            if(cnt==k){
                res=max(res,r-l+1);
            }
        }
        return res;
    }
};

```

## Approach2

``` cpp

```
## Approach2

``` cpp

```
## Approach2

``` cpp

```
## Approach2

``` cpp

```
