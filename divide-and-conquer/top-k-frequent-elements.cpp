class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for(int n : nums){
            freq[n]++;
        }

        priority_queue<
        pair<int, int>, 
        vector<pair<int,int>>, 
        greater<pair<int,int>>> pq;

        for(auto& [el, count] : freq){
            pq.push({count, el});

            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<int> topKEls;

        while(!pq.empty()){
            topKEls.push_back(pq.top().second);
            pq.pop();
        }

        return topKEls;
    }
};