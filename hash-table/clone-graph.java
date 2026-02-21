/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/

class Solution {
    public Node cloneGraph(Node node) {
        HashMap<Node, Node> map = new HashMap<>();
        return clone(node, map);
    }
    private Node clone(Node node, HashMap<Node, Node> map){
        if(node == null) return null;

        //if already in hashMap then return the node
        if(map.containsKey(node)) return map.get(node);

        //if doesn't exist then create the node
        ArrayList<Node> cloneNeighbors = new ArrayList<>();
        Node clone = new Node(node.val, cloneNeighbors);
        map.put(node, clone);

        //basically performing dfs on every neighbor
        for(Node n : node.neighbors){
            clone.neighbors.add(clone(n, map));
        }
        return clone;
    }
}