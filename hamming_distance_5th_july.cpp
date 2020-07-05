class Solution {
public:
    int hammingDistance(int x, int y) {
        int cnt=0;
        for(int i=31;i>=0;i--){
            cnt+=((1<<i) & x) != ((1<<i)&y);
        }
        
        return cnt;
        
    }
};