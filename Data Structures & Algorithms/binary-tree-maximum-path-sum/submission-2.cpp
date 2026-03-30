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
        int temp=node->val,l=recur(node->left,ans),r=recur(node->right,ans);
        if(l>0)
            temp+=l;
        if(r>0)
            temp+=r;
        ans=max(ans,temp);
        if(l>0 || r>0)
            return (node->val+max(l,r));
        return (node->val);
    }
    int maxPathSum(TreeNode* root) {
        int ans=root->val;
        recur(root,ans);
        return ans;
    }
};
