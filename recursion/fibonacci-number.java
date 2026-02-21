class Solution {
    public int fib(int n) {
        HashMap<Integer, Integer> map = new HashMap<>();
        return fibonacci(n, map);
    }
    
    private int fibonacci(int n, HashMap<Integer, Integer> map){
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        if(!map.containsKey(n)){
            map.put(n, fibonacci(n-1, map) + fibonacci(n-2, map));
        }
        return map.get(n);
    }
}