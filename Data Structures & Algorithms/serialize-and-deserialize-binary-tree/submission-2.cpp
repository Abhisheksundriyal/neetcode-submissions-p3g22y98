/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==nullptr)
            return "N";
        return (to_string(root->val)+","
                +serialize(root->left)+","
                +serialize(root->right));
    }

    TreeNode* recur(string data,int& idx) {
        string temp;
        while(idx<data.length() && data[idx]!=',')
        {
            temp.push_back(data[idx]);
            idx++;
        }
        idx++;
        if(temp=="N")
            return nullptr;
        int num=stoi(temp);
        TreeNode* node = new TreeNode(num);
        node->left=recur(data,idx);
        node->right=recur(data,idx);
        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int idx=0;
        return recur(data,idx);
    }
};
