class Solution {
    public int findCircleNum(int[][] isConnected) {
        ArrayList<ArrayList<Integer>> adjList = new ArrayList<ArrayList<Integer>>();
        int V = isConnected.length;
        boolean[] vis = new boolean[V + 1];
        int count = 0;

        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i, vis, isConnected);
                count++;
            }
        }
        return count;

        //without converting matrix to list

        /** 
        //initialising adjacency list
        for(int i=0; i<V; i++){
            adjList.add(new ArrayList<Integer>());
        }

        //converting matrix to adjacency list
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if(isConnected[i][j] == 1 && i!=j){
                    adjList.get(i).add(j);
                    adjList.get(j).add(i);
                }
            }
        }

        for(int i=0; i<V; i++){
            if(!vis[i]){
                count++;
                dfs(i, adjList, vis);
            }
        }
        return count;
        */
    }
    /** 
    private void dfs(int node, ArrayList<ArrayList<Integer>> adjList, boolean[] vis){
        vis[node] =  true;   
        // q.add(node);
        // while(!q.isEmpty()){
        //     node = q.poll();
            for(Integer i : adjList.get(node)){
                if(!vis[i]){
                   vis[i] = true;
                   dfs(i, adjList, vis);
                //    q.add(i);
                }
            }
        // }   
    }
    */
    private void dfs(int i, boolean[] vis, int[][] matrix){
        for(int j=0; j<matrix.length; j++){
            if(matrix[i][j] == 1 && !vis[j]){
                vis[j] = true;
                dfs(j, vis, matrix);
            }
        }
    }
}