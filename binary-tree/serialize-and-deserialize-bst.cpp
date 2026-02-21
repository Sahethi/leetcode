/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    TreeNode* build(queue<int>& q, int minVal, int maxVal){
        if(q.empty()) return nullptr;

        int val = q.front();
        if(val < minVal || val > maxVal){
            return nullptr;
        }
        q.pop();
        TreeNode* root = new TreeNode(val);
        root->left = build(q, minVal, val);
        root->right = build(q, val, maxVal);

        return root;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string s = to_string(root->val);
        string l = serialize(root->left);
        string r = serialize(root->right);

        if(l != "") s += "," + l;
        if(r != "") s += "," + r;

        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        if(data.empty()) return nullptr;

        stringstream ss(data);
        string item;
        queue<int> q;

        while(getline(ss, item, ',')){
            q.push(stoi(item));
        }

       return build(q, INT_MIN, INT_MAX);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;