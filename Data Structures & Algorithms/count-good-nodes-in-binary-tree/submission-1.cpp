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

    void dfs(TreeNode* node,int large,int& count) {
        if(node==nullptr)
            return;
        if(node->val>=large)
        {
            count++;
            large=max(large,node->val);
        }
        dfs(node->left,large,count);
        dfs(node->right,large,count);
        
    }

    int goodNodes(TreeNode* root) {
        int count=0,large=INT_MIN;
        dfs(root,large,count);
        return count;
    }
};
