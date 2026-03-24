class Solution {
public:
    int minKnightMoves(int x, int y) {

        x = abs(x);
        y = abs(y);
        set<pair<int, int>> visited;
        queue<pair<int, int>> q;
        //all the valid knight moves
        vector<pair<int, int>> dirs = {
            {1,2}, {1,-2}, {-1,2}, {-1,-2},
            {2,1}, {-2,1}, {2,-1}, {-2,-1},
        };

        q.push({0,0});
        visited.insert({0,0});

        int steps = 0;
        while(!q.empty()){
            int size = q.size();

            for(int i=0; i<size; i++){
                auto xy = q.front();
                int currX = xy.first;
                int currY = xy.second;

                q.pop();

                if(currX == x && currY == y) return steps;

                for(auto& d : dirs){
                    int nx = currX + d.first;
                    int ny = currY + d.second;

                    if(nx >= -2 && ny >= -2 && !visited.count({nx, ny})){
                        visited.insert({nx, ny});
                        q.push({nx, ny});
                    }
                }
            }
            steps++;
        }
        
        return -1;
    }
};