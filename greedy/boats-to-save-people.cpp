class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {

        int boats = 0;
        bool lastPersonCovered = false;
        sort(people.begin(), people.end());
        int i;
        for(i=0; i<people.size()-1; i++){
            if(people[i] + people[i+1] <= limit) {
                boats++;
                i++;
                lastPersonCovered = true;
            }else{
                if(people[i] <= limit){
                    boats++;
                }
                lastPersonCovered = false;
            }
        }

        if(!lastPersonCovered){
            if(people[people.size()-1] <= limit){
                boats++;
            }
        }
        return boats;
    }
};