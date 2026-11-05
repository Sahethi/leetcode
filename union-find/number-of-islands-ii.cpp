class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unite(int a, int b){
        int rootA = find(a);
        int rootB = find(b);

        if(rootA == rootB) return false;

        if(rank[rootA] < rank[rootB]){
            parent[rootA] = rootB;
        }else if(rank[rootB] < rank[rootA]){
            parent[rootB] = rootA;
        }else{
            parent[rootB] = rootA;
            rank[rootA]++;
        }

        return true;
    }
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        
        parent.assign(m * n , -1);
        rank.assign(m * n, 0);

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        vector<int> result;
        int islands = 0;
        
        for(auto position : positions){
            int row = position[0];
            int col = position[1];
            int id = row * n + col;
            
            //already land
            if(parent[id] != -1){
                result.push_back(islands);
                continue;
            }

            parent[id] = id;
            islands++;

            for (int k = 0; k < 4; k++) {
                int newRow = row + dr[k];
                int newCol = col + dc[k];

                // Check boundaries
                if (newRow < 0 || newRow >= m ||
                    newCol < 0 || newCol >= n) {
                    continue;
                }

                int neighborId = newRow * n + newCol;

                // Skip water
                if (parent[neighborId] == -1) {
                    continue;
                }

                // Merge two different islands
                if (unite(id, neighborId)) {
                    islands--;
                }
            }
            result.push_back(islands);
        }
        
        return result;
    }
};