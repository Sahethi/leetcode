class Solution {
public:
    vector<pair<int,int>> dirs = {
        {-1, 0}, // UP = 0
        {1, 0},  // DOWN = 1
        {0, -1}, // LEFT = 2
        {0, 1}   // RIGHT = 3
    };

    vector<int> opposite = {1, 0, 3, 2};

    unordered_map<int, vector<int>> mp = {
        {1, {2, 3}}, // left, right
        {2, {0, 1}}, // up, down
        {3, {2, 1}}, // left, down
        {4, {3, 1}}, // right, down
        {5, {2, 0}}, // left, up
        {6, {3, 0}}  // right, up
    };

    bool dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& vis) {
        int m = grid.size(), n = grid[0].size();

        if (i == m - 1 && j == n - 1) return true;

        vis[i][j] = true;

        int type = grid[i][j];

        for (int d : mp[type]) {
            int ni = i + dirs[d].first;
            int nj = j + dirs[d].second;

            // 1. bounds check
            if (ni < 0 || nj < 0 || ni >= m || nj >= n) continue;

            // 2. visited check
            if (vis[ni][nj]) continue;

            int nextType = grid[ni][nj];

            // 3. compatibility check
            bool ok = false;
            for (int nd : mp[nextType]) {
                if (nd == opposite[d]) {
                    ok = true;
                    break;
                }
            }

            if (!ok) continue;

            // 4. recurse
            if (dfs(ni, nj, grid, vis)) return true;
        }

        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        return dfs(0, 0, grid, vis);
    }
};