class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        vector<int> indegree(n+1);
        vector<int> outdegree(n+1);

        //basically how many people trust i and how many ppl does i trust
        for(auto& relation : trust){
            indegree[relation[1]]++;
            outdegree[relation[0]]++;
        }

        for(int i=1; i<=n; i++){
            if(indegree[i] == n-1 && outdegree[i] == 0){
                return i;
            }
        }

        return -1;

        /**
        n = 3, trust = [[1,3],[2,3],[3,1]]
        who trusts them
        1 = 1
        2 = 0
        3 = 2

        who do i trust
        1 = 1 
        2 = 1
        3 = 1

        **/
    }
};