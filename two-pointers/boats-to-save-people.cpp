class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {

        int boats = 0;
        // sort(people.begin(), people.end());
        bool last = false;
        for(int i=0; i<people.size()-1; i++){
            if(people[i] + people[i+1] <= limit) {
                boats++;
                i++;
                if(i == people.size()-1) last = true;
            }else{
                if(people[i] <= limit){
                    boats++;
                }
                last = false;
            }
        }

        if(!last){
            if(people[people.size()-1] <= limit){
                boats++;
            }
        }


        return boats;
    }
};