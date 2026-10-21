class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {

        int n = graph.size();

        //if only 1 node is there then 0 steps
        if(n == 1) return 0;

        //target condition would be like visiting all the nodes so like all n and n can be max 12
        int target = (1 << n) - 1;
        //thats like if n = 3 hence its 111

        //stores node, bitmask, distance
        queue<tuple<int, int, int>> q;

        vector<vector<bool>> visited(n, vector<bool>(1 << n, false));

        for(int i=0; i<n; i++){
            int startingMask = 1 << i;
            q.push({i, startingMask, 0});
            visited[i][startingMask] = true;
        }

        while(!q.empty()){
            auto [curr, mask, dist] = q.front();
            q.pop();

            for(int n : graph[curr]){
                int newMask = mask | (1 << n);

                if(newMask == target) return dist + 1;

                if(!visited[n][newMask]){
                    visited[n][newMask] = true;
                    q.push({n, newMask, dist + 1});
                }
            }
        }

        return 0;
    }
};