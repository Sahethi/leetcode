class Solution {
public:
    int minOperations(int n) {
        // vector<int> arr(n);
        // int sum = 0;
        // for(int i=0; i<n; i++){
        //     arr[i] = (2 * i) + 1;
        //     sum += arr[i];
        // }
        // int target = sum / n;

        // //if number of elements are even 
        return (n%2 == 0) ? (n/2)*(n/2) : n/2*(n/2+1);
    }
};