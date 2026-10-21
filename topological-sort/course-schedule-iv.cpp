class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> grid(numCourses, vector<bool>(numCourses, false));
        vector<bool> ans;
        
        for(int i=0; i<prerequisites.size(); i++){
            auto u = prerequisites[i][0];
            auto v = prerequisites[i][1];

            grid[u][v] = true;
        }
        for(int k=0; k<numCourses; k++){
            for(int i=0; i<numCourses; i++){
                for(int j=0; j<numCourses; j++){
                    if(grid[i][k] && grid[k][j]){
                        grid[i][j] = true;
                    }
                }
            }
        }

        for(auto& q : queries){
            ans.push_back(grid[q[0]][q[1]]);
        }
        return ans;
    }
};