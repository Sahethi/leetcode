class Solution {
public:
    int titleToNumber(string columnTitle) {
        int len = columnTitle.size();
        long long ans = 0;
        if(len == 1) return (1 + columnTitle[0] - 'A');

        for(int i=0; i<len; i++){
            ans = ans * 26 + (columnTitle[i] - 'A' + 1);
        }

        return ans;
    }
};