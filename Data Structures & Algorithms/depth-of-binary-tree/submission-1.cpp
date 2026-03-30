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
    int ans=0;
    void recur(TreeNode* node,int temp) {
        if(!node)
            return;
        ans=max(ans,temp);
        recur(node->left,temp+1);
        recur(node->right,temp+1);
    }
    int maxDepth(TreeNode* root) {
        recur(root,1);
        return ans;
    }
};
