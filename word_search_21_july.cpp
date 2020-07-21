class Solution {
public:
    string s;
    vector<vector<char> > grid;
    int n,m,len;
    bool found(int x,int y,int pos){
         if(pos==len) return true;
        if(x<0 || x>=n || y<0 || y>=m) return false;
       
        if(grid[x][y]==s[pos]){
            char ch=grid[x][y];
            grid[x][y]='#';
            bool res=found(x,y+1,pos+1) || found(x,y-1,pos+1) || found(x+1,y,pos+1) || found(x-1,y,pos+1);
            grid[x][y]=ch;
            return res;
        }
        
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n=board.size();
        m=board[0].size();
        len=word.length();
        s=word;
        grid=board;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==s[0]) if(found(i,j,0)) return true;
            }
        }
        
        return false;
    }
};