class Solution {
public:
    
    typedef struct node{
        int cnt;
        node* child[26];
    } trie;
    
    trie* root;
    
    void insert(string& s){
        trie* curr=root;
        
        for(char c:s){
            int n=c-'a';
            if(curr->child[n]==NULL) curr->child[n]=new trie();
            curr=curr->child[n];
        }
        
        curr->cnt++;
    }
    
    bool search(string& s,int st,int e){
        trie* curr=root;
        
        for(int i=st;i<=e;i++){
            int n=s[i]-'a';
            if(!curr->child[n]) return false;
            curr=curr->child[n];
        }
        
        return curr->cnt>0;
    }
    map<int,vector<string> > m;
    
    vector<string> solve(string& s,int idx){
        if(m.count(idx)) return m[idx];
        
        vector<string> res;
        
        for(int i=idx;i<s.length();i++){
            if(search(s,idx,i)){
                string curr=s.substr(idx,i-idx+1);
                if(i==s.length()-1) res.push_back(curr);
                vector<string> ret=solve(s,i+1);
                for(string &str:ret) res.push_back(curr+" "+str);
            }
        }
        
        return m[idx]=res;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        root=new trie();
        
        for(string& s:wordDict) insert(s);
       return solve(s,0);
        
    }
};