class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int leftEven = 0;
        int leftOdd = 0;
        int totalEven = 0;
        int totalOdd = 0;
        int count =0;
        for(int i=0; i<nums.size(); i++)
            if(i % 2 == 0)
                totalEven += nums[i];
            else
                totalOdd += nums[i];


        for(int i=0; i<nums.size(); i++){
            if(i % 2 == 0){
                totalEven -= nums[i];
            } else {
                totalOdd -= nums[i];
            }

            if(leftEven + totalOdd == leftOdd + totalEven)
                count++;

            if(i%2 == 0)
                leftEven += nums[i];
            else
                leftOdd += nums[i];
        }
        return count;
    }
};