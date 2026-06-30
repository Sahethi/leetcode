class Solution {
public:
    int numberOfSubstrings(string s) {
        std::vector<int> last_seen(3, -1);
        int total_substrings = 0;
        int n = s.length();
        
        for (int i = 0; i < n; ++i) {
            // Update the map for the current character
            last_seen[s[i] - 'a'] = i;
            
            // If we have seen all three characters at least once
            if (last_seen[0] != -1 && last_seen[1] != -1 && last_seen[2] != -1) {
                // The window must at least start at the minimum of the three last seen indices
                int min_idx = std::min({last_seen[0], last_seen[1], last_seen[2]});
                
                // All substrings starting from index 0 up to min_idx and ending at i are valid
                total_substrings += (min_idx + 1);
            }
        }
        
        return total_substrings;
    }
};