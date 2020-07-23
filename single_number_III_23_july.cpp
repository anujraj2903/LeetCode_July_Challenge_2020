class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size();
        int res=0;
        for(int num:nums) res^=num;
        
        int idx=0;
        while(res){
            if(res&1) break;
            res/=2;
            idx++;
        }
        
        int x=0,y=0;
        for(int num:nums) 
            if(num & (1<<idx)) x^=num;
            else y^=num;
        
        return {x,y};
        
    }
};