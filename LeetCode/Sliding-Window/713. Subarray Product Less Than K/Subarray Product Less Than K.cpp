/*
    Author-Siddharth Akar
    time-complexity:o(n)
    space-o(1)


*/


class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& a, int k) {
        int n=a.size();
        if(k==1||k==0)
            return 0;
        int res=0,l=0,x=1;
        for(int r=0;r<n;r++){
            x*=a[r];
            while(x>=k){
                x/=a[l];
                l++;
            }
            res+=(r-l+1);
        }
        return res;
    }
};