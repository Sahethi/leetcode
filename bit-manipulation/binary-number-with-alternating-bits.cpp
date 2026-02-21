class Solution {
public:
    bool hasAlternatingBits(int n) {
        
        long long res = n ^ (n >> 1);
        if((res & (res+1)) == 0) return true;
        else return false;
    }
};

