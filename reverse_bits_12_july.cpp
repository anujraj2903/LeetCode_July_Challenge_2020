class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res=0;
        
        int i=0;
        while(n){
            if(n&1){
                res+=pow(2,31-i);
            }
            
            i++;
            n/=2;
        }
        
        return res;
    }
};