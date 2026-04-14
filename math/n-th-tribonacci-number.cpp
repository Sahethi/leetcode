class Solution {
public:
    int tribonacci(int n) {

        if(n == 0) return 0;
        else if(n == 1) return 1;
        else if(n == 2) return 1;
        else if(n == 3) return 2;

        int first = 0, second = 1, third = 1;
        int sum = 0;

        for(int i=0; i<n; i++){
            sum = first + second + third;
            first = second;
            second = third;
            third = sum;
        }

        return first;
        
    }
};