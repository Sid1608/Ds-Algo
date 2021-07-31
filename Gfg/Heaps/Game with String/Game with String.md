

### []()
Author:@Siddharth Akar<br>
Problem Statement:


## Approach1

``` cpp
class Solution{
public:
    int minValue(string s, int k){

        unordered_map<char,int>p;
        for(int i=0;i<s.size();i++){
           p[s[i]]++;
        }
         priority_queue<int>pq;
        for(auto x:p){
            pq.push(x.second);
        }
        while(!pq.empty() and k--){
            int curr=pq.top()-1;
            pq.pop();
            if(curr)pq.push(curr);
        }
        int res=0;
        while(!pq.empty()){
            res+=(pq.top()*pq.top());
            pq.pop();
        }
        return res;
    }
};

```

## Approach2

``` cpp
class Solution{
public:
    int minValue(string s, int k){
        unordered_map<char,int>p;
        for(int i=0;i<s.size();i++){
            p[s[i]]++;
        }
        multiset<int,greater<int>>st;
        for(auto x:p){
            st.insert(x.second);
        }
        while(k--){
            int x=*(st.begin());
            st.insert(x-1);
            st.erase(st.begin());
        }
        int res=0;
        for(auto x:st){
            res+=(x*x);
        }
        return res;
    }
};
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
