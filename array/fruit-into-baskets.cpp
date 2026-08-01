class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        //only 2 baskets are available and each basket can only hold 1 types of fruit
        //maximise the number of fruits u can pick
        //basically there can be diff types of fruits
        //you have to maintain a maxDist and keep updating it 
        //cause u can only have two varitries

        unordered_map<int, int> mp;
        int maxWindow = 0;
        int left = 0;
        //if my window has more than 1 type keep moving the left pointer


        for(int i=0; i<fruits.size(); i++){
            
            mp[fruits[i]]++;

            while(mp.size() > 2){
                mp[fruits[left]]--;
                if(mp[fruits[left]] == 0){
                    mp.erase(fruits[left]);
                }
                left++;
            }
            
            maxWindow = max(maxWindow,  i - left + 1);
        }

        return maxWindow;
    }
};