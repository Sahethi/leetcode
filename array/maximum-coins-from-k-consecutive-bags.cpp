class Solution {
private:
    long long solve(vector<vector<int>>& coins, int k){
        int n = coins.size();
        sort(coins.begin(), coins.end());
        vector<long long> prefix(n+1, 0);
        //r - l + 1 * c

        //prefix is storing sum between the intervals
        for(int i=0; i<n; i++){
            long long l = coins[i][0];
            long long r = coins[i][1];
            long long c = coins[i][2];
            prefix[i+1] = prefix[i] + (r - l + 1) * c;
        }

        long long best = 0;
        int j=0;
        for(int i=0; i<n; i++){
            long long left = coins[i][0];
            //cover this much from point left to k bags 
            long long right = left + k - 1;

            j = max(j, i);
            while(j<n && coins[j][0] <= right){
                j++;
            }

            //check the total between the valid intervals
            long long total = prefix[j] - prefix[i];

            //removing the overhangs, surpasses the right boundary
            if(j > i && coins[j-1][1] > right){
                //remove that partial
                total -= (coins[j-1][1] - right) * 1LL * coins[j-1][2];
            }
            best = max(best, total);

        }
        return best;
    }
public:
    long long maximumCoins(vector<vector<int>>& coins, int k) {
        
        long long ans = solve(coins, k);

        vector<vector<int>> reversed = coins;

        for(auto& interval : reversed){
            int l = interval[0];
            int r = interval[1];
            interval[0] = -r;
            interval[1] = -l;
        }

        ans = max(ans, solve(reversed, k));
        return ans;
        
        
        // //k is the window size
        // int n = coins.size();
        // sort(coins.begin(), coins.end());
        // vector<int> prefix(n+1, 0);
        // //r - l + 1 * c
        // //prefix is storing sum between the intervals
        // for(int i=0; i<n; i++){
        //     long long l = coins[i][0];
        //     long long r = coins[i][1];
        //     long long c = coins[i][2];
        //     prefix[i+1] = prefix[i] + (r - l + 1) * c;
        // }

        // //starting with the left end point
        // long long left = coins[i][0]
        // long long right = left + k - 1;

        // int j = i;
    }
};