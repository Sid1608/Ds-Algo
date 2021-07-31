//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


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

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}  // } Driver Code Ends