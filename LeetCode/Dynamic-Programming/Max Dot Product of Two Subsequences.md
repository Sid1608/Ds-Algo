/*
   Author:Siddharth Akar
   problem-link:https://leetcode.com/problems/max-dot-product-of-two-subsequences/
   problem-statement:Given two arrays nums1 and nums2.Return the maximum dot product between non-empty subsequences of nums1 and nums2 with the same length.
*/



class Solution {
public:

   //Recurcive-Solution
    void solve2(int ind,vector<int>& temp,vector<int>& nums2,int& n,int cnt,int ans,int& res){
        if(cnt==temp.size()){
            res=max(res,ans);
            return;
        }
        if(ind>=n)return;
       
        ans+=temp[cnt]*nums2[ind];
        solve2(ind+1,temp,nums2,n,cnt+1,ans,res);
        ans-=temp[cnt]*nums2[ind];
        solve2(ind+1,temp,nums2,n,cnt,ans,res);
        
    }
    void solve1(int ind,vector<int>temp,vector<int>& nums1,int& n,vector<int>& nums2,int m,int& res){
        if(temp.size()!=0){
            solve2(0,temp,nums2,m,0,0,res);
        }
        if(ind>=n)return ;

        temp.push_back(nums1[ind]);;
        solve1(ind+1,temp,nums1,n,nums2,m,res);
        temp.pop_back();
        solve1(ind+1,temp,nums1,n,nums2,m,res);
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int dp[n+1][m+1];
	//Iterative Solution
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 ||j==0)
                    dp[i][j]=INT_MIN;
                else{
                    int op1=nums1[i-1]*nums2[j-1]+max((dp[i-1][j-1]==INT_MIN?0:dp[i-1][j-1]),0);
                    int op2=max(dp[i-1][j],dp[i][j-1]);
                    dp[i][j]=max(op1,op2);
                }
            }
        }
        return dp[n][m];
    }
};