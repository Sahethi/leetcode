class Solution 
{
public:
    int findNthDigit(int n) {
        long long digits = 1;
        long long count = 9;
        long long start = 1;

        while(n > digits * count){
            n -= digits * count;

            digits++;
            count *= 10;
            start *= 10; 
        }

        //now we know that n lies in the correct bucket
        n = n-1; //as its 1-indexed
        int num = start + n / digits;
        int index = n % digits;

        string s = to_string(num);

        return s[index] - '0';
    }
};