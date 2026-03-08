class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        //list of neighbors
        vector<vector<pair<int, int>>> adj(n+1);
        for(const auto& time : times){
            int u = time[0];
            int v = time[1];
            int w = time[2];
            adj[u].push_back({v, w});
        }
        
        //this is a vector to store the shortest time from k to every other node
        vector<int> dist(n+1, INT_MAX);
        
        //building min-heap prirority queue
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[k] = 0;
        pq.push({0,k}); //time and node

        while(!pq.empty()){
            int time_to_u = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            //if we have found a shorter path ignore this
            if(time_to_u > dist[u])
                continue;

            for(const auto& edge : adj[u]){
                int v = edge.first;
                int time_u_to_v = edge.second;

                if(dist[u] + time_u_to_v < dist[v]){
                    dist[v] = dist[u] + time_u_to_v;
                    pq.push({dist[v], v});
                }
            }
        }

        int max_time = 0;
        for(int i=1; i<=n; i++){
            if(dist[i] == INT_MAX)
                return -1;
            max_time = max(max_time, dist[i]);
        }
        return max_time;

    }
};