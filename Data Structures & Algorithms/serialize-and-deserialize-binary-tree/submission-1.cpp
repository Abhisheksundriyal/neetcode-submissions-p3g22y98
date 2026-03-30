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

    void recur(TreeNode* node,string& ans) {
        if(node==nullptr)
        {
            ans.push_back('N');
            ans.push_back('X');
        }
            
        else {
            ans=ans+to_string(node->val);
            ans.push_back('X');
            recur(node->left,ans);
            recur(node->right,ans);
        }  
    }

    TreeNode* recur2(string& data,int& idx) {
        if(data[idx]=='X')
            idx++;
        if(data[idx]=='N')
        {
            idx++;
            return nullptr;
        }
        string temp;
        while(data[idx]!='X')
        {
            temp.push_back(data[idx]);
            idx++;
        }
        TreeNode* node=new TreeNode(stoi(temp));
        node->left=recur2(data,idx);
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
