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
    TreeNode* build(queue<string>& q){
        if(q.empty()) return nullptr;

        string val = q.front();
        q.pop();
        if(val == "NULL") return nullptr;

        TreeNode* root = new TreeNode(stoi(val));
        root->left = build(q);
        root->right = build(q);
        return root;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        if(!root){
            return "NULL";
        }

        string s = to_string(root->val);
        string l = serialize(root->left);
        string r = serialize(root->right);

        s += "," + l + "," + r;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        stringstream ss(data);
        string item;

        while(getline(ss, item, ',')){
            q.push(item);
        }

        return build(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));