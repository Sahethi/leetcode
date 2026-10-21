class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, 1e9));

        for(int i=0; i<n; i++){
            dist[i][i] = 0; //distance for the city to itself is 0
        }

        for(auto edge : edges){
            //as arrows are bidirectional
            dist[edge[0]][edge[1]] = edge[2]; 
            dist[edge[1]][edge[0]] = edge[2];
        }

        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(dist[i][k] + dist[k][j] < dist[i][j]){
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        int minDist = 1e9;
        int ans;

        for(int i=0; i<n; i++){
            int reach = 0;

            for(int j=0; j<n; j++){
                if(i!=j && dist[i][j] <= distanceThreshold){
                    reach++;
                }
            }

            if(reach <= minDist){
                minDist = reach;
                ans = i;
            }
        }

        return ans;

    }
};