class Solution {
public:
    //for a graph to be a valid tree it shouldnt have any cycles and should have n-1 edges
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        if(edges.size() != n-1){
            return false;
        }
        for(const auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        if(!dfs(0, -1, adj, visited)) return false;

        for(int i=0; i<n; i++){
            if(!visited[i]){
                return false;
            }
        }

        return true;
    }

    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited){
        visited[node] = true;
        //now we need to iterate over the neigbors of node
        for(int neighbor : adj[node]){
            if(neighbor == parent){
                continue;
            }
            if(visited[neighbor]){
                return false;
            } else {
                if(!dfs(neighbor, node, adj, visited)){
                    return false;
                }
            }
        }
        return true;
    }
};