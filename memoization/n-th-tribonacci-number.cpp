class Solution {
public:
    int tribonacci(int n) {
        
        if(n == 1) return 0;
        if(n == 2) return 1;
        if(n == 3) return 2;

        int first = 0, second = 1, third = 1;
        int sum = first + second + third;

        for(int i=third; i<n; i++){
            sum += i;
        }

        return sum;
        
    }
};