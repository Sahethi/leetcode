class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        /**
        each bus contributes T/time[i] so total would be sum of it
        we need to find the minimum time that completes the totalTrips
        so it can be between 1 to min(time) * totalTripe
        basically the fatest bus finishes all the trips
        */

        long long left = 1;
        long long right = (long long) *min_element(time.begin(), time.end()) * totalTrips;

        while(left <= right){
            int mid = left + (right - left) / 2;
            long long trips = 0;

            for(int t : time){
                trips += mid / t;
                if(trips >= totalTrips) break;
            }

            if(trips >= totalTrips) right = mid - 1;
            else left = mid + 1;
        }

        return left;

    }
};