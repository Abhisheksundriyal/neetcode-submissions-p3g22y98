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

    void dfs(TreeNode* node,int large,int& ans) {
        if(node==nullptr)
            return;
        if(large<=node->val)
            ans++;
        dfs(node->left,max(large,node->val),ans);
        dfs(node->right,max(large,node->val),ans);
    }

    int goodNodes(TreeNode* root) {
        int ans=0;
        dfs(root,INT_MIN,ans);
        return ans;
    }
};
