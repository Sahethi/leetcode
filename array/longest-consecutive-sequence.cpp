class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        unordered_set<int> num_set(nums.begin(), nums.end());
        int max_length = 0;
        for(auto x : num_set){
            int curr_num = x;
            int curr_len = 1; 
            int prev = curr_num - 1;
            if(num_set.find(prev) != num_set.end()){
                continue;
            } 
            while(num_set.find(curr_num + 1) != num_set.end()){
                curr_num = curr_num + 1;
                curr_len +=1;
            }
            max_length = max(max_length, curr_len);


        }
        return max_length;
        
    }
};