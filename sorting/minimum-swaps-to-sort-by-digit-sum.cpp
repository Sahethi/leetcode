class Solution {
    int digitSum(int num){
        int sum = 0;
        while(num){
            sum += num % 10;
            num = num/10;
        }
        return sum;
    }
public:
    int minSwaps(vector<int>& nums) {
        //basically cycle sort

        int n = nums.size();
        
        vector<pair<pair<int, int>, int>> arr;
        // {{digitSum, value}, original_index}

        for(int i=0; i<n; i++){
            arr.push_back({{digitSum(nums[i]), nums[i]}, i});
        }

        sort(arr.begin(), arr.end());

        vector<bool> visited(n, false);
        int swaps=0;

        for(int i=0; i<n; i++){
            //if its already visited and in correct position then skip
            if(visited[i] || arr[i].second == i) continue;

            int cycleSize = 0;
            int j = i;

            while(!visited[j]){
                visited[j] = true;
                j = arr[j].second;
                cycleSize++;
            }

            // if(cycleSize > 1){
            swaps  += (cycleSize - 1);
            // }
        }

        return swaps;
    }
};