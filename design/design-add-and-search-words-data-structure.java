class Node{
    Node links[] = new Node[27];
    boolean flag = false;

    boolean containsKey(char c){
        return (links[c - 'a'] != null);
    }

    Node get(char ch){
        return links[ch  - 'a'];
    }

    void put(char ch, Node node){
        links[ch - 'a'] = node;
    }

    void setEnd(){
        flag = true;
    }

    boolean isEnd(){
        return flag;
    }
}
class WordDictionary {
    Node root;
    public WordDictionary() {
        root = new Node();
    }
    
    public void addWord(String word) {
        Node node = root;
        for(int i = 0; i < word.length(); i++){
            if(!node.containsKey(word.charAt(i))){
                Node n =  new Node();
                node.put(word.charAt(i),n);
            }
            node = node.get(word.charAt(i));
        }
        node.setEnd();
    }
    
    public boolean search(String word) {
        Node node = root;
        return search(node, word, 0);
    }

    private boolean search(Node node, String word, int index){
        //base condition
        //we are performing dfs
        if(index == word.length()) return node.isEnd();

        char c = word.charAt(index);
        if(c != '.'){
           return  node.containsKey(c) && search(node.get(c), word, index+1);
        }
        for(int i = 0; i < 26; i++) 
            if(node.links[i] != null && search(node.links[i], word, index+1))
                return true;
        return false;
    }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */