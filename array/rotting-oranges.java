class Pair{
    int row;
    int col;
    int time;

    Pair(int row, int col, int time){
        this.row = row;
        this.col = col;
        this.time = time;
    }
}
class Solution {
    public int orangesRotting(int[][] grid) {
        if(grid.length == 0) return 0;
        Queue<Pair> q = new LinkedList<>();
        int n = grid.length;
        int m = grid[0].length;
        int[][] vis = new int[n][m];
        int countFresh = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.offer(new Pair(i, j, 0));
                    vis[i][j] = 2;
                } else {
                    vis[i][j] = 0;
                }
                if(grid[i][j] == 1){
                    countFresh++;
                }
            }
        }

        return bfs(n, m, grid, vis, q, countFresh);

    }
    private int bfs(int n, int m, int[][] grid, int vis[][], Queue<Pair> q, int countFresh){
        int time = 0;
        int[] dRow = {-1, 0, 1, 0};
        int[] dCol = {0, 1, 0, -1};
        int count = 0;

        while(!q.isEmpty()){
            int row = q.peek().row;
            int col = q.peek().col;
            int t = q.peek().time;
            time = Math.max(time, t);
            q.remove();

            for(int i=0; i<4; i++){
                int nRow = row + dRow[i];
                int nCol = col + dCol[i];

                if(nRow >=0 && nRow < n &&
                    nCol >=0 && nCol < m &&
                    vis[nRow][nCol] == 0 &&
                    grid[nRow][nCol] == 1){
                        q.add(new Pair(nRow, nCol, t + 1));
                        vis[nRow][nCol] = 2;
                        count++;
                }
            }
        }

        if(count != countFresh) return -1;
        
        return time;
    }
}