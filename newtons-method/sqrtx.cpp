class Solution {
public:
    int mySqrt(int x) {
        //we have to do binary search
        int left = 0;
        int right = x;
        
        while(left <= right){
            long mid = (left + right) >> 1; // int division by 2

            if(mid * mid == x) return mid;
            if(mid * mid < x){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }

        return right; //rigth will have the lasst number which is. <= x
        

    }
};