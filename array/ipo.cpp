class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        vector<pair<int,int>> capAndP;
        int n = capital.size();

        for(int i=0; i<n; i++){
            capAndP.push_back({capital[i], profits[i]});
        }

        sort(capAndP.begin(), capAndP.end());

        //priority queue by default max
        priority_queue<int> pq;
        int idx = 0;
        for(int i=0; i<k; i++){
            while(idx < n && capAndP[idx].first <= w){
                pq.push(capAndP[idx].second);
                idx++;
            }

            if(pq.empty()){
                break;
            }else{
                w += pq.top();
                pq.pop();
            }
        }

        return w;
    }
};