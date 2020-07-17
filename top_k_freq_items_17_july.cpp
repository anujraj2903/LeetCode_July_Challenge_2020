class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;
        priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
        
        for(int num:nums) m[num]++;
        
        int ctr=0;
        
        for(auto x:m){
            if(ctr>=k){
                if(pq.top().first<x.second){
                    pq.pop();
                    pq.push({x.second,x.first});
                }
            } else{
                pq.push({x.second,x.first});
            }
            
            ctr++;
        }
        
        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        return res;
    }
};