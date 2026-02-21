class Solution {
    private void dfs(int[][] image, int sr, int sc, int color, int target){
        if(sr >=0 && sr < image.length && sc>=0 && sc<image[0].length && image[sr][sc] ==color){
            image[sr][sc] = target;
            dfs(image, sr + 1, sc, color, target);
            dfs(image, sr - 1, sc, color, target);
            dfs(image, sr, sc + 1, color, target);
            dfs(image, sr, sc - 1, color, target);
        }
    }
    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        if(image[sr][sc] == color) return image;
        dfs(image, sr, sc, image[sr][sc], color);
        return image;
    }
}