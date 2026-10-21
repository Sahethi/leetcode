class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        
        vector<double> res;

        int n = nums.size();

        multiset<int> window(nums.begin(), nums.begin()+k);
        auto mid = next(window.begin(), k/2);


        for(int i=k; ;i++){

            if(k % 2){
                res.push_back(*mid);
            }else{
                auto prevMid = prev(mid);
                res.push_back(((double)(*prevMid) + *mid) / 2.0);
            }

            if (i == nums.size())
                break;

            // Insert incoming element
            window.insert(nums[i]);

            if (nums[i] < *mid)
                mid--;

            // Remove outgoing element
            if (nums[i - k] <= *mid)
                mid++;

            window.erase(window.lower_bound(nums[i - k]));
        }

        return res;

        /**
        vector<double> res;
        int n = nums.size();

        for(int i=0; i<=n-k; i++){

            vector<int> window(nums.begin() +i, nums.begin() + i + k);
            sort(window.begin(), window.end());

            double m;

            if(k % 2 == 1){
                m = window[k/2];
            }else{
                m = ((double)window[k/2 - 1] + window[k/2]) / 2.0;
            }

            res.push_back(m);
        }      

        return res;
        */
    }
};