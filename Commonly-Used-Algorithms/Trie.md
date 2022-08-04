

### Prefix Tree
``` CPP
class TrieNode{
    TrieNode* links[26];
    bool flag=false;
    public:
        bool containsKey(char c){
            return (links[c-'a']!=NULL);
        }
        TrieNode* get(char c){
            return links[c-'a'];
        }
        void put(char c,TrieNode* node){
            links[c-'a']=node;
        }
        void setEnd(){
            flag=true;
        }
        bool getEnd(){
            return flag;
        }
    
};
class Trie {
public:
    TrieNode* root;
    
    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word) {//time complexity: O(len)
        TrieNode* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new TrieNode());
            }
            node=node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {//time complexity: O(len)
        TrieNode* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node=node->get(word[i]);
        }
        return node->getEnd();
    }
    
    bool startsWith(string prefix) {//time complexity: O(len)
        TrieNode* node=root;
        for(int i=0;i<prefix.size();i++){
            if(!node->containsKey(prefix[i])){
                return false;
            }
            node=node->get(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */


```
