class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int i = 0;
        for(i=0; i<heights.size()-1; i++){
            if(heights[i] < heights[i+1]){
                int diff = heights[i+1] - heights[i];
                if(diff <= bricks){
                    if(bricks != 0){
                        bricks -= diff;
                        continue;
                    }else{
                        if(ladders != 0) ladders--;
                        else break;
                    }
                }else{
                    if(ladders != 0) {
                        ladders--;
                        continue;
                     } else return i;
                }
            }
        }
        return i;
    }
};