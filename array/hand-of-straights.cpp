class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0)
            return false;
        
        sort(hand.begin(), hand.end());
        //[1, 2, 3, 6, 2, 3, 4, 7, 8]
        //{1, 2, 2, 3, 3, 4, 6, 7, 8}

        unordered_map<int, int> freq;
        for(int i=0; i<hand.size(); i++){
            int v = hand[i];
            freq[v]++;
        }

        for(int x : hand){
            if(freq[x] == 0) continue;
            for(int i=0; i<groupSize; i++){
                int card = x + i;
                if(freq[card] == 0)
                    return false;
                freq[card]--;
            }
        }

        return true;
    }
};