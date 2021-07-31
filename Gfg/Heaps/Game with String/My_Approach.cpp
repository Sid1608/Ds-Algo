class Solution{
public:
    int minValue(string s, int k){
        // code here
        unordered_map<char,int>p;
        for(int i=0;i<s.size();i++){
            p[s[i]]++;
        }
        multiset<int,greater<int>>st;
        for(auto x:p){
            st.insert(x.second);
        }
        while(k--){
            int x=*(st.begin());
            st.insert(x-1);
            st.erase(st.begin());
        }
        int res=0;
        for(auto x:st){
            res+=(x*x);
        }
        return res;
    }
};