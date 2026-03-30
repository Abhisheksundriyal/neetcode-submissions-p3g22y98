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
    bool ans=true;
    int recur(TreeNode* node) {
        if(!node)
            return 0;
        int a=recur(node->left),b=recur(node->right);
        if(abs(a-b)>1)
            ans=false;
        return max(a,b)+1;
    }
    bool isBalanced(TreeNode* root) {
        recur(root);
        return ans;
    }
};
