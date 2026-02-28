class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tank = 0;
        int start = 0;
        int total = 0;
        vector<int>diff(gas.size());
        for(int i=0; i<gas.size(); i++){
            diff[i] = gas[i] - cost[i];
            tank += diff[i];
            total += diff[i];
            if(tank < 0){
                start = i+1;
                tank = 0;
            }
        }
        if(total < 0) return -1;
        return start;
    }
};