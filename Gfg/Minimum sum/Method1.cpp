
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
 string addStrings(string x, string y) {
         int a,b,c=0;
        reverse(x.begin(),x.end());
        reverse(y.begin(),y.end());
        string ans="";
        if(x.size()>=y.size())
            swap(x,y);
        int i;
        for( i=0;i<x.size();i++){
            a=x[i]-'0';
            b=y[i]-'0';
            if(a+b+c<10){
                ans+=to_string(a+b+c);
                c=0;
            }
            else{
                ans+=to_string((a+b+c)%10);
                c=1;
            }
        }
        if(y.size()>x.size()){
            for(int j=i;j<y.size();j++){
                b=y[j]-'0';
                if(b+c<10){
                    ans+=to_string(b+c);
                    c=0;
                }
                else{
                    ans+=to_string((b+c)%10);
                    c=1;
                }
            }
        }
        if(c!=0){
            ans+=to_string(c);
        }
        reverse(ans.begin(),ans.end());
        if(ans.size()==1)return ans;
        int j;
        for(j=0;j<ans.size();j++){
            if(ans[j]!='0')
                break;
        }
        string res="";
        for(int i=j;i<ans.size();i++)res+=ans[i];
       
        return res;
    }
class Solution{   
public:
        string solve(int arr[], int n) {
        // code here
        sort(arr,arr+n);
        string x="",y="";
        int i=0;
        while(i<n){
            x+=to_string(arr[i]);
            i++;
            if(i<n)
            {
                y+=to_string(arr[i]);
                i++;
            }
        }
        return addStrings(x,y);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends