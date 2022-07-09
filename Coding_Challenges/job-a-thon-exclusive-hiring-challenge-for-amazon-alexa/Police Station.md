``` cpp
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int solve(int N, int a, vector<int> x) {
        // code here
        int maxi1=0,ind1=-1,maxi2=0;
        for(int i=0;i<N;i++){
            x[i]=abs(x[i]-a);
            if(maxi1<x[i]){
                maxi1=x[i];
                ind1=i;
            }
        }
        for(int i=0;i<N;i++){
            if(i==ind1)continue;
            maxi2=max(maxi2,x[i]);
        }
        return maxi1+maxi2;
    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {

        int N, a;
        cin >> N >> a;


        vector<int> x(N);
        for (int i = 0; i < N; i++)
            cin >> x[i];

        Solution ob;
        cout << ob.solve(N, a, x) << "\n";
    }
    return 0;
}
  // } Driver Code Ends

```
