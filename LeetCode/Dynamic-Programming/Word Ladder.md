
/*
  Author:@Siddharth Akar
  problem-link:https://leetcode.com/problems/word-ladder/
  
  problem-statement:Given two words, beginWord and endWord, and a dictionary wordList,
  return the number of words in the shortest transformation sequence from beginWord to endWord, 
  or 0 if no such sequence exists.
*/


class Solution {
public:
    
    int ladderLength(string s, string e, vector<string>& List) {
        unordered_set<string> dict(List.begin(), List.end());
        int n=List.size();
        queue<pair<string,int>>q;
        q.push({s,1});
        while(!q.empty())
        {
            string curr=q.front().first;
            int len=q.front().second;
            q.pop();
            if(curr==e){
                return len;
            }
            dict.erase(curr);
            for(int i=0;i<curr.size();i++){
                char x=curr[i];
                for(int j=0;j<26;j++){
                    curr[i]='a'+j;
                    if(dict.find(curr)!=dict.end()){
                        q.push({curr,len+1});
                    }
                }
                curr[i]=x;
            }
            
        }
        return 0;
        
    }
};
