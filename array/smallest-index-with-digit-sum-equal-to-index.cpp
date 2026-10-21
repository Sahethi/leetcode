class Solution {
public:
    int smallestIndex(vector<int>& nums) 
    {
        int l = nums.size();
        for(int i = 0;i<l; i++)
        {
            int sod = 0;
            while(nums[i]!=0)
            {
                sod+=nums[i]%10;
                nums[i]/=10;
            }
            if(sod==i)
            {
                return i;
            }
        }
        return -1;    
    }
};