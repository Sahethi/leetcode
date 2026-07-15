class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        
        vector<double> res;

        double median;
        int n = nums.size();

        for(int i=0; i<=n-k; i++){

            vector<int> window(nums.begin()+i, nums.begin() + i + k);

            sort(window.begin(), window.end());

            double m = window[k/2];
            res.push_back(m);
        }      

        return res;
    }
};