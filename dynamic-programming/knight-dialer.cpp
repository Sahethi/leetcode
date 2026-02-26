class Solution {
public:
    const int MOD = 1e9 + 7;
    int knightDialer(int n) {
        vector<vector<int>> moves = {
            {4, 6}, // 0
            {6, 8}, // 1
            {7, 9}, // 2
            {4, 8}, // 3
            {0, 3, 9}, // 4
            {}, // 5
            {0,1,7}, // 6
            {2,6}, // 7
            {1,3}, // 8
            {2,4} // 9
        };
        vector<long> dp(10, 1);
        for (int step = 1; step < n; step++) {
            vector<long> next(10, 0);
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < moves[i].size(); j++) {
                    int neighbor = moves[i][j];
                    next[neighbor] += dp[i];
                }
            }

            dp = next;
        }

    }
};