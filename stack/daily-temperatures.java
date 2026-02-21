class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int answers[] = new int[temperatures.length];   

        Stack<Integer> stack = new Stack<>();

        for(int i=0; i<temperatures.length; i++){

            while(!stack.isEmpty() && temperatures[stack.peek()] < temperatures[i]){
                answers[stack.peek()] = i - stack.pop();
            }
            stack.add(i);
        }

        return answers;
    }
}