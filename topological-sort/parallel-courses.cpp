class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);

        for(auto& r : relations){
            int preReq = r[0] - 1;
            int nextReq = r[1] - 1;

            graph[preReq].push_back(nextReq);
            indegree[nextReq]++;
        }

        //pushing elements with in degree 0
        queue<int> q;
        for(int i=0; i<n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        int semester = 0;
        int processed = 0;

        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                int curr = q.front();
                q.pop();
                processed++;
                for(int next : graph[curr]){
                    indegree[next]--;
                    if(indegree[next] == 0)
                        q.push(next);
                }
            }
            semester++;
        }

        return processed == n ? semester : -1;
    }
};