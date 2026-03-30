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
    pair<int,int> recur(TreeNode* node,bool& ans) {
        if(!node)
            return {INT_MAX,INT_MIN};
        pair<int,int> l=recur(node->left,ans),
                    r=recur(node->right,ans);
        if(l.second>=(node->val) || r.first<=(node->val))
            ans=false;
        int small=min(node->val,min(l.first,r.first)),
            large=max(node->val,max(l.second,r.second));
        return {small,large};
    }
    bool isValidBST(TreeNode* root) {
        bool ans=true;
        recur(root,ans);
        return ans;
    }
};
