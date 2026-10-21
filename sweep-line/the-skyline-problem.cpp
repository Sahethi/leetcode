class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> events;
        int prevMax = 0;
        for(auto& b : buildings){
            int left = b[0];
            int right = b[1];
            int height = b[2];
            events.push_back({left, -height});
            events.push_back({right, height});
        }

        sort(events.begin(), events.end());

        multiset<int> heights;
        heights.insert(0);
        vector<vector<int>> result;

        for(auto& e : events){
            int x = e.first;
            int h = e.second;

            if(h < 0){
                heights.insert(-h);
            }else{
                heights.erase(heights.find(h));
            }
            int currentMax = *heights.rbegin();
            if(currentMax != prevMax){
                result.push_back({x, currentMax});
                prevMax = currentMax;
            }
        }
        return result;
    }
};