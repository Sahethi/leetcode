class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        
        vector<double> res;
        int n = nums.size();

        for(int i=0; i<=n-k; i++){

            vector<int> window(nums.begin()+i, nums.begin() + i + k);

            sort(window.begin(), window.end());

            double m;
            if(k % 2 == 1){
                m = window[k/2];
            }else{
                m = (double)(window[k/2 - 1] + window[k/2]) / 2.0;
            }

            res.push_back(m);
        }      

        return res;
    }
};