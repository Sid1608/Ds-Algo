# [Job-A-Thon 14 Hiring Challenge](https://practice.geeksforgeeks.org/contest/job-a-thon-14-hiring-challenge/instructions/)

## Coding

### [Geek Left With No Food](https://practice.geeksforgeeks.org/contest/job-a-thon-14-hiring-challenge/problems/)

``` cpp
class Solution {
  public:
    int solve(int n) {
        // code here
        int cnt=0;
        while(n){
            if(n%2==0){
                n=n-(n/2);
            }else{
                n=n-(n+1)/2;
            }
            cnt++;
        }
        return cnt;
        
    }
};
```


### [Make Array Equal](https://practice.geeksforgeeks.org/contest/job-a-thon-14-hiring-challenge/problems/)
- time complexity of gcd is o(logn)
``` cpp
class Solution {
  public:
    vector<vector<int> > solve(int N, vector<int> A) {
        // code here
        vector<vector<int>>ans;
        set<int>s;
        for(int num:A){
            if(num){
                s.insert(num);
            }
        }
        if(s.size()==0)return ans;
        int x=*(s.begin());
        
        while(x!=1){
            set<int>temp;
            ans.push_back({1,N});
            for(auto i:s){
                if(i%x){
                    temp.insert(i%x);
                }
            }
            s.clear();
            s=temp;
            if(s.size()==0){
                return ans;
            }
            x=*(s.begin());
            if(x==1){
                ans.push_back({1,N});
                return ans;
            }
            
        }
        if(x==1){
            ans.push_back({1,N});
        }
        return ans;
        
    }
```

### [Target Path Sum](https://practice.geeksforgeeks.org/contest/job-a-thon-14-hiring-challenge/problems/)
- star tree
``` cpp
class Solution {
  public:
    long long solve(int n, vector<int> &p, vector<int> &arr, int k, int a, int b) {
        // code here
        
        long long ans=0;
        if(a>=b){
            for(int i=1;i<n;i++){
                long long d=arr[0]+arr[i];
                if(d>k){
                    if(arr[0]){
                        if(arr[i]>k){
                            if(arr[0]>k){
                                ans+=b+b;
                                arr[0]=0;
                            }else{
                                ans+=b;
                            }
                            
                        }else{
                            arr[0]=0;
                            ans+=b;
                        }
                    }else{
                        ans+=b;
                    }
                }
            }
        }else{
            
            long long mini=*min_element(arr.begin(),arr.end());
            long long maxi=*max_element(arr.begin(),arr.end());
            long long ans1=0,x=arr[0];
            for(int i=1;i<n;i++){
                long long d=arr[0]+arr[i];
                if(d>k){
                   if(mini+arr[i]>k){
                       if(arr[0]+mini>k){
                           if(mini+mini>k){
                               ans1=1e18;
                               break;
                           }else{
                               ans1+=a+a;
                               arr[0]=mini;
                           }
                       }else{
                           ans1+=a;
                       }
                   }else{
                       arr[0]=mini;
                       ans1+=a;
                   }
                }
            }
            long long ans2=b;
            arr[0]=0,mini=0;
            for(int i=1;i<n;i++){
                long long d=arr[0]+arr[i];
                if(d>k){
                   if(mini+arr[i]>k){
                       if(arr[0]+mini>k){
                           if(mini+mini>k){
                               ans2=1e18;
                               break;
                           }else{
                               ans2+=a+a;
                               arr[0]=mini;
                           }
                       }else{
                           ans2+=a;
                       }
                   }else{
                       arr[0]=mini;
                       ans2+=a;
                   }
                }
            }
            
            long long ans3=b;
            arr[0]=x;
            for(int i=1;i<n;i++){
                if(arr[i]==maxi){
                    arr[i]=0;
                    break;
                }
            }
            for(int i=1;i<n;i++){
                long long d=arr[0]+arr[i];
                if(d>k){
                   if(mini+arr[i]>k){
                       if(arr[0]+mini>k){
                           if(mini+mini>k){
                               ans3=1e18;
                               break;
                           }else{
                               ans3+=a+a;
                               arr[0]=mini;
                           }
                       }else{
                           ans3+=a;
                       }
                   }else{
                       arr[0]=mini;
                       ans3+=a;
                   }
                }
            }
            ans=min({ans1,ans2,ans3});
            
        }
        return ans;
    }
};

```

## Quiz
### Programming Logic
- log(n!) = \theta(n log n).
- O(n^2)=n^3 / (sqrt(n))  https://www.geeksforgeeks.org/algorithms-analysis-of-algorithms-question-8/
- The bubble sort is at its best if the input data is sorted. i.e. If the input data is sorted in the same order as expected output.
- https://www.geeksforgeeks.org/gate-gate-it-2004-question-13/
- No of arithmetic operations will be θ (logn) in the worst case as every comparison needs 2 operations + and / by 2.

### Logical
- https://byjus.com/question-answer/statements-all-belts-are-rollers-some-rollers-are-wheels-all-wheels-are-mats-some-mats/
### Aptitude
- If a pack of cards has 14 black cards , 6 red cards and 3 white cards. What is the probability of selecting 1 black card, 2 red card and 1 white cards.
- What is the value of 2 ^ 40?
- What is the LCM (Least Common Multiple) of 1000000007 and 14 ?
- If the selling price of an object is 300 USD and the seller gain a profit of 20 percent by selling it on that price. What must be its cost price.
