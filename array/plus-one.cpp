class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        for(int i=n-1; i>=0; i--){
            if(digits[i] < 9){
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        digits.insert(digits.begin(), 1);
        return digits;
        // int n = digits.size();
        // vector<int> result(digits.begin(), digits.end());
        // if(result[n-1] < 9)
        //     result[n-1]++;
        // else {
        //     int c = 0;
        //     for(int i=n-1; i>=0; i--){
        //         if(result[i] == 9){
        //             c++;
        //         }else{
        //             break;
        //         }
        //     }
        //     if(c == n){
        //         result[0] = 1;
        //         for(int i=1; i<c; i++){
        //             result[i] = 0;
        //         }
        //         result.push_back(0);
        //     }else{
        //         result[n-c-1]++;
        //         for(int i=n-c; i<n; i++){
        //             result[i] = 0;
        //         }
        //     }
        // }

        // return result;
    }
};