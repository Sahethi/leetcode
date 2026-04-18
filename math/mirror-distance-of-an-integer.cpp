class Solution {
public:
    int mirrorDistance(int n) {
        string s = to_string(n);

        reverse(s.begin(), s.end());
        int reversedInt = stoi(s);
        
        int ans = abs(n - reversedInt);

        return ans;
    }
};