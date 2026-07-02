class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> gridHealth(n, vector<int>(m, -1));
        deque<pair<int, int>> dq;

        int startHealth = health - grid[0][0];

        if (startHealth <= 0)
            return false;

        // up, down, right, left
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        gridHealth[0][0] = startHealth;
        dq.push_front({0, 0});

        while (!dq.empty()) {
            auto [r, c] = dq.front();
            dq.pop_front();

            int currentHealth = gridHealth[r][c];

            if (r == n - 1 && c == m - 1)
                return true;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    int nextHealth = currentHealth - grid[nr][nc];

                    if (nextHealth >= 1 && nextHealth > gridHealth[nr][nc]) {
                        gridHealth[nr][nc] = nextHealth;

                        if (grid[nr][nc] == 0)
                            dq.push_front({nr, nc});
                        else
                            dq.push_back({nr, nc});
                    }
                }
            }
        }

        return false;
    }
};