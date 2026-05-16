class Solution {
    int digitSum(int x) {
        int sum = 0;
        while (x) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<pair<pair<int,int>, int>> arr;
        // {{digitSum, value}, original_index}

        for (int i = 0; i < n; i++) {
            arr.push_back({{digitSum(nums[i]), nums[i]}, i});
        }

        sort(arr.begin(), arr.end());

        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || arr[i].second == i) continue;

            int cycle_size = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = arr[j].second;
                cycle_size++;
            }

            if (cycle_size > 1) {
                swaps += (cycle_size - 1);
            }
        }

        return swaps;
    }
};