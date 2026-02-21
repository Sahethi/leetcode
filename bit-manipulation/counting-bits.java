class Solution {
    public int[] countBits(int n) {
        int offset = 1;
        int[] arr = new int[n+1];
        for(int i=1; i<=n; i++){
            // any number will have same digits as have that number
            // extra one if its odd
            arr[i] = arr[i >> 1] + (i % 2);
        }
        return arr;
    }
}