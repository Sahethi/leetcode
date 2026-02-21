class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses);

        for(auto& p : prerequisites){
            int parent = p[1];
            int child = p[0];

            graph[parent].push_back(child);
            indegree[child]++;
        }

        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0)
                q.push(i);
        }

        vector<int> order;
        while(!q.empty()){
            int curr = q.front();
            order.push_back(curr);
            q.pop();
            for(int next : graph[curr]){
                indegree[next]--;
                if(indegree[next] == 0)
                    q.push(next);
            }
        }

        if (order.size() == numCourses)
            return order;
        else
            return {};
    }
};