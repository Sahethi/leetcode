class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0) return {1};
        if(rowIndex == 1) return {1,1};
        
        /**
        1 = 0
        11 = 1
        121 = 2 = 11 * 11
        1331 = 3 = 121 * 11
        14641 = 4 = 1331 * 11
        **/
        
        int n = rowIndex;
        vector<int> res = {1};
        long long ans = 1;
        for(int i=1; i<=rowIndex; i++){
            ans = (ans * n) / i;
            n--;
            res.push_back(ans);
        }
        return res;
    }
};