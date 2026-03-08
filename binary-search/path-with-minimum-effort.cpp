class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> dist(m, vector<int> (n, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        pq.push({0,0,0});
        dist[0][0] = 0;

        vector<int> dir = {0,1,0,-1,0};

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            int effort = curr[0];
            int r = curr[1];
            int c = curr[2];

            if(r == m-1 && c == n-1){
                return effort;
            }

            for(int i=0; i<4; i++){
                int nr = r + dir[i];
                int nc = c + dir[i+1];

                if(nr >= m || nc >= n || nr < 0 || nc < 0) continue;

                int diff = abs(heights[r][c] - heights[nr][nc]);
                int newEffort = max(effort, diff);

                if(newEffort < dist[nr][nc]){
                    dist[nr][nc] = newEffort;
                    pq.push({newEffort, nr, nc});
                }
            }
        }
        return 0;
    }
};