class Solution {
public:
    int maximumLength(vector<int>& nums) {
        
        unordered_map<int, int> freq;
        for(int num :nums){
            freq[num]++;
        }

        int maxCount = INT_MIN;

        if(freq[1] > 0){
            int onesCount = freq[1];

            if(onesCount % 2 == 0){
                onesCount--;
            }

            maxCount = max(maxCount, onesCount);
        }

        for(auto& pair : freq){
            long long curr = pair.first;
            int count = 0;

            if(curr == 1) continue;

            while(curr < 100000 && freq.count(curr) && freq[curr] >= 2){
                count += 2;
                curr = curr * curr;
            }

            if(freq.count(curr) && freq[curr] >=1){
                count +=1;
            }else{
                count -=1;
            }

            maxCount = max(maxCount, count);
        }   

        return maxCount;
    }
};