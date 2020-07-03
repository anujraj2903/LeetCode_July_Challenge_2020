class Solution {
public:
    
    vector<int> transformFunc(vector<int>& cells){
        vector<int> v(cells.size(),0);
        
        for(int i=1;i<cells.size()-1;i++){
            if(cells[i-1]==cells[i+1]) v[i]=1;
        }
        
        return v;
    }
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        set<vector<int> > s;
        bool flag=false;
        int ctr=0;
        for(int i=0;i<N;i++){
            vector<int> target=transformFunc(cells);
            if(s.find(target)==s.end()){
                s.insert(target);
                ctr++;
            } else{
                flag=true;
                break;
            }
            
            cells=target;
        }
        
        if(flag){
            N=N%ctr;
            for(int i=1;i<=N;i++){
                cells=transformFunc(cells);
            }
        }
        
        return cells;
    }
};