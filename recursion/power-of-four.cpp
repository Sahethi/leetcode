class Solution {
public:
    bool isPowerOfFour(int n) {

        if(n<=0) return false;

        //right shift by 2 is dividing by 4
        if(n == 1) return true;

        if((n & (n-1)) != 0) return false; //cause think of 8 & 7 = its 1000 & 0111 = 0000

        if((n & 0x55555555) == 0) return false;

        return true;
    }
};