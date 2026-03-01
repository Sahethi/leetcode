class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freqMap;
        int totalTasks = 0;
        for(char task : tasks){
            freqMap[task]++;
            totalTasks++;
        }

        int maxFreq = 0;
        for(auto& p : freqMap){
            maxFreq = max(maxFreq, p.second);
        }

        int countMax = 0;
        for(auto& p : freqMap){
            if(p.second == maxFreq) 
                countMax++;
        }

        return max(totalTasks, (((maxFreq - 1) * n) + (maxFreq - 1) + countMax));
    }
};