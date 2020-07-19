class Solution {
public:
    string addBinary(string a, string b) {
        int n1=a.length();
        int n2=b.length();
        
        if(n1<n2) a=string(n2-n1,'0')+a;
        if(n1>n2) b=string(n1-n2,'0')+b;
        int n=max(n1,n2);
        
        string s(n,'?');
        int c=0;
        for(int i=n-1;i>=0;i--){
            if(a[i]=='0' && b[i]=='0'){
                if(c){
                    s[i]='1';
                    c=0;
                } else s[i]='0';
            } else if((a[i]=='1' && b[i]=='0') || (a[i]=='0' && b[i]=='1')){
                if(c) s[i]='0';
                else s[i]='1';
            } else{
                if(c) s[i]='1';
                else s[i]='0';
                c=1;
            }
        }
        
        if(c) s="1"+s;
        return s;
    }
};