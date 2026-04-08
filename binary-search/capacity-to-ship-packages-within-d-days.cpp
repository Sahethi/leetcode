class Solution {
public:
    int daysNeededF(int capacity, vector<int>& weights){
        int currentLoad = 0;
        int days = 1;
        for(int w : weights){
            if(currentLoad + w > capacity){
                days++;
                currentLoad = w;
            }else{
                currentLoad += w;
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        //think of it like assume some capacity and check how many days 
        //if the capacity is small then number of days is more , then increase
        //if the capacity is large causing number of days to be small, then decrease
        //days <= D

        int left = *max_element(weights.begin(), weights.end());
        int right = 0;
        for(int w : weights){
            right += w;
        }

        while(left <= right){
            int mid = left + (right - left)/2;
            int daysNeeded = daysNeededF(mid, weights);

            if(daysNeeded > days){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }

        return left;
    }
};