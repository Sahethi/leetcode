class Solution {
public:
    int maxProduct(int n) {
        // string s = to_string(n);
        // vector<int> nums;

        // for(char c : s){
        //     nums.push_back(c - '0');
        // }
    
        // int size = nums.size();
        // sort(nums.begin(), nums.end());
        // if(size >= 2){
        //     return nums[size-1] * nums[size-2];
        // }
        // else return nums[size-1];

        // return 0;

        int first = -1, second = -1;
        while(n > 0){
            int d = n % 10;
            n = n / 10;
            if(d > first){
                second = first;
                first = d;
            }else if(d > second){
                second = d;
            }
        }

        return first * second;
    }
};