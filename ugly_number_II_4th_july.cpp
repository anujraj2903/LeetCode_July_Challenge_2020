#define ll long long int
class Solution {
public:
    
    int nthUglyNumber(int n) {
        priority_queue<ll,vector<ll>,greater<ll> > pq;
        pq.push(1);
        set<ll> s;
        n--;
        
        vector<ll> p={2,3,5};
        while(n--){
            ll u=pq.top();
            pq.pop();
            
            for(ll num:p){
                if(s.find(num*u)==s.end()){
                    pq.push(num*u);
                    s.insert(num*u);
                }
            }
            
        }
        
        return pq.top();
        
    }
};