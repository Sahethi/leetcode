class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>dist(m, vector<int>(n, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        pq.push({grid[0][0],0,0});
        dist[0][0] = grid[0][0];

        vector<int> dir ={0,1,0,-1,0};

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            int time = curr[0];
            int r = curr[1];
            int c = curr[2];

            if(r == m-1 && c == n-1) return time;

            for(int i=0; i<4; i++){
                int nr = r + dir[i];
                int nc = c + dir[i+1];

                if(nr >= m || nc >= n || nr < 0 || nc < 0) continue; 
                int newTime = max(time, grid[nr][nc]);

                if(newTime < dist[nr][nc]){
                    dist[nr][nc] = newTime;
                    pq.push({newTime, nr, nc});
                }
            }
        }
        return 0;
    }
};