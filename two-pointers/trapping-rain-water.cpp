class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int water = 0, leftMax = 0, rightMax = 0;
        while(left < right){
            
            if(height[left] < height[right]){
                if(leftMax > height[left]){
                    water += leftMax - height[left];
                }else{
                   leftMax = max(leftMax, height[left]);
                }
                left++;
            }else{
                if(rightMax > height[right]){
                    water += rightMax - height[right];
                }else{
                   rightMax = max(rightMax, height[right]);
                }
                right--;
            }
        }
        return water;
    }
};