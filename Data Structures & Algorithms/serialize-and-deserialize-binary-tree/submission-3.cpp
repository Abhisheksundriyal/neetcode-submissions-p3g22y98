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
    // string solve(TreeNode* node,string& ans) {
    //     if(!node) {
    //         ans+=",N";
    //         return ans;
    //     }
    //     return ans+=","+to_string(node->val)+solve(node->left,ans)+solve(node->right,ans);
    // }
    string serialize(TreeNode* root) {
        if(!root)
            return ",N";
        return ","+to_string(root->val)+serialize(root->left)+serialize(root->right);
    }

    TreeNode* recur(string& data,int& idx,int& n) {
        if(idx>=n)
            return nullptr;
        string temp;
        while(idx<n && data[idx]!=',')
        {
            temp.push_back(data[idx]);
            idx++;
        }
        idx++;
        if(temp=="N")
            return nullptr;
        int num=stoi(temp);
        TreeNode* newNode = new TreeNode(num);
        newNode->left=recur(data,idx,n);
        newNode->right=recur(data,idx,n);
        return newNode;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int n=data.size(),idx=1;
        return recur(data,idx,n);
    }
};
