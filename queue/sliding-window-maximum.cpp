class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //dequeue solution
        vector<int> result;
        deque<int> dq;
        int n = nums.size();

        for(int right = 0; right < n; right++){
            
            if(!dq.empty() && dq.front() == right - k){
                dq.pop_front();
            }

            while(!dq.empty() && nums[dq.back()] < nums[right]){
                dq.pop_back();
            }
            
            dq.push_back(right);

            if(right >= k-1){
                result.push_back(nums[dq.front()]);
            }
        }
        return result;
        //brute force
        /**
        int left = 0;
        vector<int> result;
        for(int right = 0; right<nums.size(); right++){
            if(right - left + 1 > k){
                left++;
            }
            if(right - left + 1 == k){
                auto it = max_element(nums.begin() + left,
                                      nums.begin() + right + 1);
                result.push_back(*it);
            }
        }
        return result;
        **/
    }
};