




## Different Consecutive Characters(Difficulty Rating:879)
``` cpp
void solve(){
   int n;
   cin>>n;
   string s;
   cin>>s;
   int ans=0;
   for(int i=1;i<n;i++){
       if(s[i]==s[i-1]){
           ans++;
       }
   }
   cout<<ans<<endl;
   
   
}

```


## Minimise LCS(Difficulty Rating:1367)
``` cpp
void solve(){
   ll n;
   cin>>n;
   string a,b;
   cin>>a>>b;
   int fa[26]={0};
   int fb[26]={0};
   for(int i=0;i<n;i++){
       fa[a[i]-'a']++;
       fb[b[i]-'a']++;
   }
   int ans=0;
   for(int i=0;i<26;i++){
       ans=max(ans,min(fa[i],fb[i]));
   }
   cout<<ans<<endl;
   
   
}
```

## Weird Subarray(Difficulty Rating:1739)
``` cpp
void solve(){
   ll n;
   cin>>n;
   vector<ll>a(n);
   rep(i,n){
       cin>>a[i];
   }
  

  vector<vector<ll>>dp(n,vector<ll>(2,0));
  dp[0][0]=1;
  dp[0][1]=1;
  ll ans=1;
   for(int i=1;i<n;i++){
       if(a[i-1]>a[i]){
           dp[i][0]=1;
      
           if(-a[i-1]<=-a[i]){
               dp[i][0]+=dp[i-1][0];
           }
           dp[i][1]=dp[i-1][0]+1;
       }else{
           dp[i][0]=1;
           if(-a[i-1]<=-a[i]){
               dp[i][0]+=dp[i-1][0];
           }
           dp[i][1]=max(dp[i-1][0],dp[i-1][1])+1;
         
       }
       ans+=max(dp[i][0],dp[i][1]);
   }
   cout<<ans<<endl;
   
    
   
   
}
```
## [Subarray Removal](https://www.youtube.com/watch?v=Ait-waohfqc)(Difficulty Rating:1505)
``` cpp
void solve(){
   int n;
   cin>>n;
   vector<int>a(n);
   rep(i,n){
       cin>>a[i];
   }
   int cnt1=0,cnt0=0;
   rep(i,n){
       cnt1+=a[i];
   }
   cnt0=n-cnt1;
   if(cnt0==0){
      int ans=0;
      ans=cnt1/3;
      cout<<ans<<endl;
   }else{
       if(cnt0>=cnt1){
           cout<<cnt1<<endl;
       }else{
           int ans=cnt0;
           int diff=cnt1-cnt0;
           
               ans+=(diff/3);
           
           cout<<ans<<endl;
       }
   }
   
}
```
