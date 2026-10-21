class DSU{
    private:
        vector<int> parent;
        vector<int> rank;

    public:
        DSU(int n){
            parent.resize(n);
            rank.resize(n, 1);
            for(int i=0; i<n; i++){
                parent[i] = i;
            }
        }

        int find(int x){
            if(parent[x] != x){
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }

        bool unite(int x, int y){
            int rootX = find(x);
            int rootY = find(y);

            if(rootX == rootY) return false;

            if(rank[rootX] > rank[rootY]){
                parent[rootY] = rootX;
            }else if(rank[rootX] < rank[rootY]){
                parent[rootX] = rootY;
            }else{
                //when eqal doesnt matter who u choose
                parent[rootY] = rootX;
                rank[rootX]++;
            }
            return true;
        }

};

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        //lets try to solve this in a linear way

        int island = 0;
        vector<int> group(n, 0);

        for(int i=1; i<nums.size(); i++){
            if(nums[i] - nums[i-1] > maxDiff){
                island++;
            }
            group[i] = island;
        }

        vector<bool> result;
        result.reserve(queries.size());
        for(const auto& q : queries){
            int u = q[0];
            int v = q[1];

            if(group[u] == group[v]) result.push_back(true);
            else result.push_back(false);
        }

        return result;


        // DSU dsu(n);

        // //this is used to create connected components
        // for(int i=1; i<n; i++){
        //     if(nums[i] - nums[i-1] <= maxDiff){
        //         dsu.unite(i, i-1);
        //     }
        // }

        // vector<bool> result;

        // //accessing and finding if the 2 nodes in the query have the same parent
        // for(const auto& q : queries){
        //     int u = q[0];
        //     int v = q[1];

        //     result.push_back(dsu.find(u) == dsu.find(v));
        // }

        // return result;
    }
};