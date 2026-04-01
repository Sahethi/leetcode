class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        /**
        k = 4 and x = 3
        |1 - 3| = 2
        |2 - 3| = 1
        |3 - 3| = 0
        |4 - 3| = 1
        |5 - 3| = 2

        basically return the 4 closest int to x
        x = 3

        as its sorted think of it like this 
        u can solve this in this way 
        calculate it 
        **/
        int n = arr.size();
        int left = 0, right = n-k;
        while(left < right){
            int mid = left + (right - left) / 2;

            if(x - arr[mid] > arr[mid+k] - x){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        return vector<int>(arr.begin() + left, arr.begin() + left +k);


    }
};