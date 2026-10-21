class Solution {
    public int largestRectangleArea(int[] heights) {
        
        Stack<Integer> stack = new Stack<>();
        int area = 0;
        for(int i=0; i<=heights.length; i++){
            int a = (i == heights.length) ? 0 : heights[i];

            while(!stack.isEmpty() && a < heights[stack.peek()]){
                int height = heights[stack.pop()];
                // we are trying to find smallest bar 
                // that comes from left and right side
                // isleye i comes from right and stack.peek comes from left
                int width = stack.isEmpty() ? i : (i - stack.peek() - 1);
                area = Math.max(area, height * width);
            }
            stack.push(i);
        }

        return area;
    }
}