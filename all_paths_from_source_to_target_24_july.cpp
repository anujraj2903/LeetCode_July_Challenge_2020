class Solution {
public:
    vector<int> g[16];
    int vis[16];
    int dest;
    vector<int> curr;
    vector<vector<int> > res;
    
    void dfs(int u){
        curr.push_back(u);
        vis[u]=1;
        if(u==dest){
            res.push_back(curr);
            return;
        }
        
        for(int v:g[u]){
            if(!vis[v]){
                dfs(v);
                vis[v]=0;
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        dest=n-1;
        memset(vis,0,sizeof(vis));
        
        for(int i=0;i<n;i++){
            for(int v:graph[i])
                g[i].push_back(v);
        }
        
        dfs(0);
        return res;
        
    }
};