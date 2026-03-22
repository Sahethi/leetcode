class Solution {
public:
    void sortColors(vector<int>& nums) {
        const int OFFSET = 50000;
        const int SIZE = 100001;

        vector<int> count(SIZE, 0);

        for(int n : nums){
            count[n + OFFSET]++;
        }

        int idx;
        for(int i=0; i<SIZE; i++){
            while(count[i] > 0){
                nums[idx++] = i - OFFSET;
                count[i]--;
            }
        }

    }
};