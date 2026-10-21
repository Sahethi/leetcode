class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //one important insight is
        //think a, b and c appear more than n/3 times
        //count(A) + count(B) + count(C) > n/3 + n/3 + n/3 = n
        //hence the elements will be atmost 2 always

        //now we apply the algorithms boyer-moore

        int count1 = 0, count2 = 0;
        int cand1 = 0, cand2 = 1;

        for(int n: nums){
            if(cand1 == n) count1++;
            else if(cand2 == n) count2++;
            else if(count1 == 0){
                cand1 = n;
                count1 = 1;
            } else if (count2 == 0){
                cand2 = n;
                count2 = 1;
            } else{
                count1--;
                count2--;
            }
        }

        count1 = count2 = 0;
        for(int n: nums){
            if(n == cand1) count1++;
            else if(n == cand2) count2++;
        }

        vector<int> res;
        int n = nums.size();
        if(count1 > n/3) res.push_back(cand1);
        if(count2 > n/3) res.push_back(cand2);

        return res;

        /**
        int n = nums.size();
        int times = floor(n/3);
        unordered_set<int> res;

        unordered_map<int, int> count;
        for(int n : nums)
            count[n]++;

        for(int n : nums)
            if(count[n] > times) res.insert(n);

        return vector<int>(res.begin(), res.end());
        **/
    }
};