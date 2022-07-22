<img width="502" alt="image" src="https://user-images.githubusercontent.com/57083596/180362454-7b7c0508-0840-4eb9-ab95-b6f2900be76a.png">

``` cpp
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    int minimumMoves(int a, int b) {
        // code here
        if(a>b)swap(a,b);
        int ans=0;
        while(b){
            int x=(int)b/a;
            ans+=x;
            b-=a*x;
            if(b==0)break;
            if(a>b)swap(a,b);
        }
        return ans;
    }
};


// { Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int A;
        scanf("%d",&A);
        
        
        int B;
        scanf("%d",&B);
        
        Solution obj;
        int res = obj.minimumMoves(A, B);
        
        cout<<res<<endl;
        
    }
}
  // } Driver Code Ends

```
