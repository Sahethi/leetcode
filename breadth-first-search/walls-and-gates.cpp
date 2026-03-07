class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {

        if(rooms.empty()) return;

        queue<pair<int, int>> q;
        for(int i=0; i<rooms.size(); i++){
            for(int j=0; j<rooms[0].size(); j++){
                if(rooms[i][j] == 0){
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()){
            auto gate = q.front();
            q.pop();
            int nr = gate.first;
            int nc = gate.second;

            if(nc + 1 < rooms[0].size()){
                if(rooms[nr][nc+1] == INT_MAX){
                    rooms[nr][nc+1] = rooms[nr][nc] + 1;
                    q.push({nr,nc+1});
                }
            }

            if(nr + 1 < rooms.size()){
                if(rooms[nr+1][nc] == INT_MAX){
                    rooms[nr+1][nc] = rooms[nr][nc] + 1;
                    q.push({nr+1,nc});
                }
            }

            if(nc - 1 >=0){
                if(rooms[nr][nc-1] == INT_MAX){
                    rooms[nr][nc-1] = rooms[nr][nc] + 1;
                    q.push({nr,nc-1});
                }
            }

            if(nr - 1 >=0){
                if(rooms[nr-1][nc] == INT_MAX){
                    rooms[nr-1][nc] = rooms[nr][nc] + 1;
                    q.push({nr-1,nc});
                }
            }
            
        }
    }
};