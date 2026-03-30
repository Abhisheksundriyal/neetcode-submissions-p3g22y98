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

    char intToChar(int num)
    {
        char ch=num+'0';
        return ch;
    }

    int charToInt(char ch)
    {
        int ans=ch-'0';
        return ans;
    }

    void recur(TreeNode* node,string& ans) {
        if(node==nullptr)
            ans.push_back('N');
        else {
            ans.push_back(intToChar(node->val));
            recur(node->left,ans);
            recur(node->right,ans);
        }  
    }

    TreeNode* recur2(string& data,int& idx) {
        if(data[idx]=='N')
            return nullptr;
        TreeNode* node=new TreeNode(charToInt(data[idx]));
        idx++;
        node->left=recur2(data,idx);
        idx++;
        node->right=recur2(data,idx);
        return node;
    }


    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        recur(root,ans);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int idx=0;
        return recur2(data,idx);
    }
};
