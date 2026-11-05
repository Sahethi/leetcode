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
        } else if(rank[rootB] < rank[rootA]){
            parent[rootB] = rootA; 
        }else{
            parent[rootB] = rootA; 
            rank[rootA]++;
        }
        return true;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        parent.assign(n, 0);
        rank.assign(n, 0);
        
        int provinces = n;

        for(int i=0; i<n; i++){
            parent[i] = i;
        }

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(isConnected[i][j] == 1){
                    if(unite(i, j)){
                        provinces--;
                    }
                }
            }
        }

        return provinces;
    }
};