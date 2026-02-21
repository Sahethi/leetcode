class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result1;
        unordered_map<int, int> freq;
        for(int num : nums)
            freq[num]++;

        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
        for(auto& [num, count] : freq){
            pq.push({count, num});
            if(pq.size() > k)
                pq.pop();
        }

        while(!pq.empty()){
            result1.push_back(pq.top().second);
            pq.pop();
        }

        return result1;        
    }
};