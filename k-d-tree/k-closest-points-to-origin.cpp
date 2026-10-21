class Solution {
private: 
    int dist(vector<int>& point){
        int x = point[0];
        int y = point[1];
        return (x*x) + (y*y);
    }

    int partition(vector<vector<int>>& points, int left, int right){
        int pivotDist = dist(points[right]);
        int i = left;

        for(int j=left; j<right; j++){
            if(dist(points[j]) <= pivotDist){
                swap(points[j], points[i]);
                i++;
            }
        }
        swap(points[i], points[right]);
        return i;
    }

    void quickSelect(vector<vector<int>>& points, int left, int right, int k){
        if(left >= right) return;
        int pivot = partition(points, left, right);
        if(pivot == k){
            return;
        }else if(pivot > k){
            //search left
            quickSelect(points, left, pivot-1, k);
        }else{
            //search right
            quickSelect(points, pivot+1, right, k);
        }
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //u can use quick select cause u need the kth elements only
        quickSelect(points, 0, points.size()-1, k);
        return vector<vector<int>>(points.begin(), points.begin()+k);

        /*
        //max-heap solution
        priority_queue<pair<int, vector<int>>> pq;
        for(auto& point : points){
            int x = point[0];
            int y = point[1];
            int dist = x*x + y*y;
            pq.push({dist, point});
            if(pq.size() > k){
                pq.pop(); // keep only the k elements
            }
        }

        vector<vector<int>> result;
        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
        */
    }
};