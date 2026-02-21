class DSU {
    public:
        vector<int> parent;
        vector<int> rank;
        int components;

        DSU(int n){
            components = n;
            parent.resize(n);
            rank.resize(n,0);
            for(int i=0; i<n; i++){
                parent[i] = i;
            }
        }

        int find(int i){
            if(parent[i] == i){
                return i;
            }
            return parent[i] = find(parent[i]);
        }

        void unite(int i, int j){
            int root_i = find(i);
            int root_j = find(j);
            if(root_i != root_j){
                if(rank[root_i] < rank[root_j]){
                    parent[root_i] = root_j;
                }else if(rank[root_i] > rank[root_j]){
                    parent[root_j] = root_i;
                }else{
                    parent[root_i] = root_j;
                    rank[root_j]++;
                }
                 components--;
            }
        }

};
class Solution {
public:

    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        for(const auto& edge : edges){
            dsu.unite(edge[0], edge[1]);
        }
        return dsu.components;
    }
    int countComponents1(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(const auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);

        int count = 0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                count++;
                dfs(i, adj, visited);
            }
        }

        return count;
    }

    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited){
        visited[node] = true;
        for(int neighbor : adj[node]){
            if(!visited[neighbor]){
                dfs(neighbor, adj, visited);
            }
        }
    }
};