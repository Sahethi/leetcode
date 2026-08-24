class Leaderboard {
private:
    vector<pair<int, int>> leaderboard;
public:
    Leaderboard() {
        
    }
    
    void addScore(int playerId, int score) {
        leaderboard.push_back({score, playerId});
    }
    
    int top(int K) {
        sort(leaderboard.begin(), leaderboard.end(), greater<pair<int,int>>());
        int sum = 0;
        for(int i=0; i<K; i++){
            sum += leaderboard[i].first;
        }
        return sum;
    }
    
    void reset(int playerId) {
        for(auto &p : leaderboard){
            if(p.second == playerId){
                p.first = 0;
                return;
            }
        }
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */