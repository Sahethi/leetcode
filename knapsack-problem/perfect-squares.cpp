class Solution {
public:
    int numSquares(int n) {
        //so like find all the perfect square before the numbers 
        queue<pair<int, int>> q;
        q.push({n,0});

        vector<bool> visited(n+1, false);

        while(!q.empty()){
            auto [current, steps] = q.front();
            q.pop();

            for(int i=1; i*i <= current; i++){
                int remainder = current - (i*i);
                if(remainder == 0){
                    return steps + 1;
                }

                if(visited[remainder] == false){
                    visited[remainder] = true;
                    q.push({remainder, steps+1});
                }   
            }
        }

        return 0;
    }
};