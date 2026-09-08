class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {

        vector<int> count(value, 0);

        for(int n : nums){
            //in order to deal with the negative remainders
            int remainder = ((n % value) + value) % value;
            count[remainder]++;
            //bascially count tells us 
            //with remainder 1,2,3 - how many numbers are there
        }

        for(int i=0; ; i++){
            int rem = i % value;

            if(count[rem] == 0) return i;

            count[rem]--;
        }
    }
};