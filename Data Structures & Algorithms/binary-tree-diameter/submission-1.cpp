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

    int recur(TreeNode* node,int level,int& ans) {
        if(node==nullptr)
            return level-1;
        int l=recur(node->left,level+1,ans),r=recur(node->right,level+1,ans),temp=(l-level)+(r-level);
        ans=max(ans,temp);
        return max(l,r);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        recur(root,1,ans);
        return ans;
    }
};
