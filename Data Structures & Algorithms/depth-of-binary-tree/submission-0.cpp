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

    void recur(TreeNode* node,int level,int& ans) {
        if(node==nullptr)
            return;
        ans=max(ans,level);
        recur(node->left,level+1,ans);
        recur(node->right,level+1,ans);
    }

    int maxDepth(TreeNode* root) {
        int ans=0;
        recur(root,1,ans);
        return ans;
    }
};
