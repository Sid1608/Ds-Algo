### Problem statement
<img width="568" alt="image" src="https://user-images.githubusercontent.com/57083596/178090586-10c978c7-5fdf-45c7-a272-cb3df390ae91.png">


### Approach
``` cpp
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    long long colosseum(int N,vector<int> A) {
        //store max and min sum by selecting n elements till i th index from start and end respectively
        vector<pair<long long,long long>>left(3*N),right(3*N);
        multiset<long long>st1;
        multiset<long long,greater<long long>>st2;
        long long sum1=0,sum2=0;
        //from left to right
        for(int i=0;i<3*N;i++){
            st1.insert(A[i]);
            st2.insert(A[i]);
            sum1+=A[i];
            sum2+=A[i];
            if(st1.size()>N){
                sum1-=*st1.begin();
                sum2-=*st2.begin();
                st1.erase(st1.begin());
                st2.erase(st2.begin());
            }
            left[i].first=sum1;
            left[i].second=sum2;
        }
        st1.clear();
        st2.clear();
        sum1=0,sum2=0;
        //from right to lefft
        for(int i=(3*N-1);i>=0;i--){
            
            st1.insert(A[i]);
            st2.insert(A[i]);
            sum1+=A[i];
            sum2+=A[i];
            if(st1.size()>N){
                sum1-=*st1.begin();
                sum2-=*st2.begin();
                st1.erase(st1.begin());
                st2.erase(st2.begin());
            }
            right[i].first=sum1;
            right[i].second=sum2;
        }
        long long ans=INT_MIN;
        for(int i=N-1;i<2*N;i++){
            ans=max(ans,(long long)left[i].first-right[i+1].second);
            ans=max(ans,(long long)left[i].second-right[i+1].first);
        }
        return ans;
        
   }
};

// { Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        Solution obj;
        int n;
        cin>>n;
        vector<int> a(3*n);
         for (int i = 0; i <3*n; ++i){
            cin>>a[i];
        }
        cout << obj.colosseum(n,a) <<"\n";
    }
    return 0;
}
  // } Driver Code Ends

```
