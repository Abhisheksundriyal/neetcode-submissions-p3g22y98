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
    void recur(TreeNode* node,int large,int& ans) {
        if(!node)
            return;
        if((node->val)>=large)
            ans++;
        large=max(large,node->val);
        recur(node->left,large,ans);
        recur(node->right,large,ans);
    }
    int goodNodes(TreeNode* root) {
        int ans=0;
        recur(root,INT_MIN,ans);
        return ans;
    }
};
