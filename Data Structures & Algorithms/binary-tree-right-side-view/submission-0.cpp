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

class Solution {
public:

    void dfs(TreeNode* node,vector<int>& ans,int level) {
        if(level>ans.size())
            ans.push_back(node->val);
        if(node->right!=nullptr)
            dfs(node->right,ans,level+1);
        if(node->left!=nullptr)
            dfs(node->left,ans,level+1);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==nullptr)
            return ans;
        dfs(root,ans,1);
        return ans;
    }
};
