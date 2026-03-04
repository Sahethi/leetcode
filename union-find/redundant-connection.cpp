class Solution {
    vector<int> parent;
    vector<int> rank;
    int find(int x){
        if(parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unionSets(int u, int v){
        int rootU = find(u);
        int rootV = find(v);
        if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        }
        else if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        }
        else {
            parent[rootV] = rootU;
            rank[rootU]++;   // height increases by 1
        }
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        //kruskal's disjoint set
        int n = edges.size();
        parent.resize(n+1);
        rank.resize(n+1,0);

        for(int i=1; i<=n; i++){
            parent[i] = i; //node is its own parent
        }

        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            int rootU = find(u);
            int rootV = find(v);
            if(rootU == rootV) return edge;
            unionSets(u, v);
        }
        return edges[0];
    }
};