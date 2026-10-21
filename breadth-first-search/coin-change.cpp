class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        
        queue<pair<int, int>> q;
        vector<bool> visited(amount+1, false);
        visited[amount] = true;

        q.push({amount, 0});
        
        while(!q.empty()){
            auto [current, steps] = q.front();
            q.pop();

            for(auto coin : coins){
    
                if(current < coin) continue;
                int diff = current - coin;
                if(diff == 0){
                    return steps + 1;
                }
                
                if(visited[diff] == false){
                    visited[diff] = true;
                    q.push({diff, steps+1});
                }
            }
        }

        return -1;
    }
};