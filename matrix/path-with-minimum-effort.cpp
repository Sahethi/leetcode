class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> dist(m, vector<int> (n, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        pq.push({0,0,0});
        dist[0][0] = 0;

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            int effort = curr[0];
            int r = curr[1];
            int c = curr[2];

            if(r == m-1 && c == n-1){
                return effort;
            }

            int nr, nc;
            if(r + 1 < m){
                nr = r + 1;
                nc = c;
                int diff = abs(heights[r][c] - heights[nr][nc]);
                int newEffort = max(effort, diff);

                if(newEffort < dist[nr][nc]){
                    dist[nr][nc] = newEffort;
                    pq.push({newEffort, nr, nc});
                }
            }
            if(r - 1 >= 0){
                nr = r - 1;
                nc = c;
                int diff = abs(heights[r][c] - heights[nr][nc]);
                int newEffort = max(effort, diff);

                if(newEffort < dist[nr][nc]){
                    dist[nr][nc] = newEffort;
                    pq.push({newEffort, nr, nc});
                }
            }
            if(c + 1 < n){
                nr = r;
                nc = c + 1;
                int diff = abs(heights[r][c] - heights[nr][nc]);
                int newEffort = max(effort, diff);

                if(newEffort < dist[nr][nc]){
                    dist[nr][nc] = newEffort;
                    pq.push({newEffort, nr, nc});
                }
            }
            if(c - 1 >= 0){
                nr = r;
                nc = c - 1;
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