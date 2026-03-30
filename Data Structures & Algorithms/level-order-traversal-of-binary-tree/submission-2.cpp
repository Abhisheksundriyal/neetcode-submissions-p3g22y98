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
    void recur(TreeNode* node,int level,vector<vector<int>>& ans) {
        if(!node)
            return;
        if(ans.size()<level)
            ans.push_back({});
        ans[level-1].push_back(node->val);
        recur(node->left,level+1,ans);
        recur(node->right,level+1,ans);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        recur(root,1,ans);
        return ans;
    }
};