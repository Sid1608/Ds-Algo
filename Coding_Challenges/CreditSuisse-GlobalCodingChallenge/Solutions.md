

## [Banker and Stocks](https://www.credit-suisse.com/pwp/hr/en/codingchallenge/?token=eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzUxMiJ9.eyJleHAiOjE2Njc0NDQxNzcsImlhdCI6MTY2NjIzNDU3NywianRpIjoiNTQ5OTY5ZDItMzcyYS00YmFiLTgzMDctMTk2M2E0YjA3YTM0IiwiaXNzIjoiZ2NjLWFwaSIsImF1ZCI6ImdjYy1hcHAiLCJzdWIiOiJTaWQxNjA4Iiwicm9sIjpbIlVTRVIiXSwibmFtZSI6IlNpZGRoYXJ0aCBBa2FyIiwicHJlZmVycmVkX3VzZXJuYW1lIjoiU2lkMTYwOCJ9.I_C5aB_KDzfzwo9t7DfNXOT_FP4fTDqrTpFXEesZUMORZbEJsuCMr1tryNSF8dKLxx_EotPdlwbVKEVdi27mQg#/questions/1)
``` cpp
#include<bits/stdc++.h>
using namespace std;
 
string solution(long n) {
    // Write solution here
    if(n==0)return "BUY";
    if(n%2){
        return "SELL";
    }else{
        long cnt=0;
        while(n){
            if(n%2==0){
                n/=2;
                cnt++;
            }else{
                break;
            }
        }
        if(cnt>1){
            return "BUY";
        }else{
            return "PASS";
        }
    }
    return "";
}
 
int main() {
	long n;
	cin >> n;	
  	string answer=solution(n);
	cout << answer << endl;
    
}

```

## File Reorganization
``` cpp
#include <bits/stdc++.h>

using namespace std;

int solution(string files) {
    // Write solution here
    int n=files.size();
    unordered_map<char,int>ump;
    for(auto w:files){
        ump[w]++;
    }
    int ans=0,isOdd=0;
    for(auto [_,x]:ump){
        if(x%2==0){
            ans+=x;
        }else{
            isOdd=1;
            ans+=(x-1);
        }
    }
    return ans+isOdd;
}


int main() {
     string files="";
     cin>>files;
     cout<<solution(files);
     return 0;
}

```
## Sorting Share Prices

```cpp
#include <bits/stdc++.h>
using namespace std;
int solution(int N, int M, int P[])
{
    // Write solution here
	int maxi=0;
	for(int i=0;i<N;i++){
	    if(P[i]<maxi){
	        if(maxi+P[i]>M)return 0;
	    }
	    maxi=max(maxi,P[i]);
	}
	return 1;
}

int main() {
    int n,m;
    cin>>n>>m;
    int P[n];
    for(int i=0;i<n;i++){
        scanf("%d", &P[i]);
    }
	cout<<solution(n,m,P)<<endl;
	return 0;
}

```
