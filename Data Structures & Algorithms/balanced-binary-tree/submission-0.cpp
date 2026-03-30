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

    int recur(TreeNode* node,bool& ans) {
        if(node==nullptr)
            return 0;
        int l=1+recur(node->left,ans),r=1+recur(node->right,ans);
        if(abs(l-r)>1)
            ans=false;
        return max(l,r);
    }

    bool isBalanced(TreeNode* root) {
        bool ans=true;
        recur(root,ans);
        return ans;
    }
};
