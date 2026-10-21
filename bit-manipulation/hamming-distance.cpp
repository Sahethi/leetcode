class Solution {
public:
    int hammingDistance(int x, int y) {
        /**
        0001
        0100
        basically 
        XOR this 
        0101
        then check number of set bits?

        011
        001
        010 -> only 1 bit differs

        010 & 1 if ans = 0 then count dont ++
        and then shift right 
        **/

        int hammingDist = x ^ y;
        if(hammingDist == 0) return 0;

        int count = 0;
        while(hammingDist != 0){
            if(hammingDist & 1 == 1){
                count++;
            }
            hammingDist = hammingDist >> 1;
        }

        return count;
    }
};