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
    int recur(TreeNode* node,int& ans) {
        if(!node)
            return 0;
        int a=recur(node->left,ans),b=recur(node->right,ans);
        ans=max(ans,a+b);
        return max(a,b)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        recur(root,ans);
        return ans;
    }
};
