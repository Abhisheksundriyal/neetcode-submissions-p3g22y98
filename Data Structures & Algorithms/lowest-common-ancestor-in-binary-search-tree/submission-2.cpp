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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int a=min(p->val,q->val),b=max(p->val,q->val);
        if(a<root->val && b<root->val)
            return lowestCommonAncestor(root->left,p,q);
        else if(a>root->val && b>root->val)
            return lowestCommonAncestor(root->right,p,q);
        return root;
    }
};