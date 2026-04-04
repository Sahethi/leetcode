class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int countOf5 = 0;

        for(int i=0; i<bills.size(); i++){
            if(bills[i] == 5){
                countOf5++;
            }else{
                int n = (bills[i] / 5);
                if(n <= countOf5) {
                    continue;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};