class Solution {
public:
    string reverseWords(string s) {
        stringstream in(s);
        string word;
        string ans="";
        while(in >> word){
            reverse(word.begin(),word.end());
            ans+=word+" ";
        }
        
        if(!ans.empty()){
            ans.pop_back();
            reverse(ans.begin(),ans.end());
        }
        
        return ans;
    }
};