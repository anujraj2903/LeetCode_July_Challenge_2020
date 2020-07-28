class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int charmap[26]={0};
        
        for(char ch:tasks){
            charmap[ch-'A']++;
        }
        
        sort(charmap,charmap+26);
        int max_value=charmap[25]-1;
        int idle_slots=max_value*n;
        
        for(int i=24;i>=0;i--){
            idle_slots-=min(charmap[i],max_value);
        }
        
        return idle_slots>0?idle_slots+tasks.size():tasks.size();
    }
};