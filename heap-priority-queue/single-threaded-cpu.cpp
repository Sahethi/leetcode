class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        //we have to sort by enqueue time and then process accordingly
        
        //creating arr to have the indices of the original array, as thats what we have to return
        vector<vector<long long>> arr;
        vector<int> result;
        int n = tasks.size();
        for(int i=0; i<n; i++){
            arr.push_back({tasks[i][0], tasks[i][1], i});
        }

        sort(arr.begin(), arr.end(), [](auto &a, auto &b){
            return a[0] < b[0];
        });

        int i=0, time=0;
        //we need min-heap as pq is by deault max
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long,int>> > pq;

        while(i<n || !pq.empty()){
            while(i<n && arr[i][0] <= time){
                pq.push({arr[i][1], arr[i][2]});
                i++;
            }

            if(pq.empty()){
                time = arr[i][0];
                continue;
            }


            auto [processTime, i] = pq.top();
            pq.pop();

            result.push_back(i);
            time += processTime;
        }

        return result;

    }
};