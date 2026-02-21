class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue pq(stones.begin(),stones.end());

        while(pq.size() >= 2){
            int y = pq.top(); 
            pq.pop();
            int x = pq.top();
            pq.pop();
            if(x!=y) pq.push(y-x);
        }

        return pq.empty() ? 0 : pq.top();

    }
};