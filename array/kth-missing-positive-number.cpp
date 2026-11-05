class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

        /**
        2 3 4 7 11
        k = 5
        so u can find the missing count between 2 numbers 
        number of positive ints we have between 1 to 7 
        only 4 appear in our array 2 3 4 7
        7 : i = 3
        7 - (3+1) = 3 number are missing thats 1 5 6
        so the missing count is arr[i] - (i + 1)
        **/

        int left = 0;
        int right = arr.size()-1;

        while(left <= right){
            int mid = left + (right - left)/2;
            int missing = arr[mid] - (mid + 1);

            if(missing < k){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }

        return left + k;

    }
};