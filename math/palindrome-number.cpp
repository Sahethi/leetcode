class Solution {
public:
    bool isPalindrome(int x) {
        //without converting to string
        if(x < 0 || (x % 10 == 0 && x !=0)) return false;
        
        int reverse=0;
        while(x > reverse){
            reverse = reverse * 10 + x % 10;
            x = x /10;
        }

        return(x == reverse || x == reverse / 10);
        // //by converting to string
        // string s = to_string(x);
        // int left = 0;
        // int right = s.length()-1;
        // while(left < right){
        //     if(s[left++] != s[right--]){
        //         return false;
        //     }
        // }
        // return true;
    }
};