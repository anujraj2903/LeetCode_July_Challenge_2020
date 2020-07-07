class Solution {
public:
    vector<vector<int> > g;
    int n,m;
    int ans=0;
    
    void dfs(int x,int y){
        
        if(x<0 || y<0 || x>=n || y>=m || g[x][y]==0){
            ans++;
            return;
        }
        
        if(g[x][y]==-1) return ;
        
        g[x][y]=-1;
        dfs(x+1,y);
        dfs(x-1,y);
        dfs(x,y+1);
        dfs(x,y-1);
    }
    
    void traverse(){
         for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(g[i][j]){
            dfs(i,j);
            return;
        } 
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        g=grid;
        traverse();
        return ans;
       
    }
};