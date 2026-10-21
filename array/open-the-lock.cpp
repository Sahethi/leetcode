class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visited(deadends.begin(), deadends.end());
        
        if (visited.count("0000")) return -1;
        if(target == "0000") return 0;

        queue<pair<string, int>> q;
        q.push({"0000", 0});
        visited.insert("0000");

        while (!q.empty()) {
            auto [current, steps] = q.front();
            q.pop();
            
            // 3. Loop through each of the 4 wheel positions
            for (int i = 0; i < 4; ++i) {
                char original_char = current[i];
                
                // --- TRY SPINNING WHEEL UP ---
                std::string step_up = current;
                step_up[i] = (original_char == '9') ? '0' : original_char + 1;
                
                if (step_up == target) return steps + 1;
                if (visited.find(step_up) == visited.end()) {
                    visited.insert(step_up);
                    q.push({step_up, steps + 1});
                }
                
                // --- TRY SPINNING WHEEL DOWN ---
                std::string step_down = current;
                // If it's '0', wrap to '9'. Otherwise, subtract 1.
                step_down[i] = (original_char == '0') ? '9' : original_char - 1;
                
                if (step_down == target) return steps + 1;
                if (visited.find(step_down) == visited.end()) {
                    visited.insert(step_down);
                    q.push({step_down, steps + 1});
                }
            }
        }

        return -1;   
    }
};