class DetectSquares {
public:
    unordered_map<int, unordered_map<int, int>> points;
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        points[x][y]++;
    }
    
    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];

        if(!(points.count(x))) return 0;
        int total = 0;

        for(auto& [y2, freq] : points[x]){
            if(y == y2) continue;
            int side = y2 - y;
            if(points.count(x+side)){
                total += freq * points[x+side][y] * points[x+side][y2];
            }
            if(points.count(x-side)){
                total += freq * points[x-side][y] * points[x-side][y2];
            }
        }
        return total;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */