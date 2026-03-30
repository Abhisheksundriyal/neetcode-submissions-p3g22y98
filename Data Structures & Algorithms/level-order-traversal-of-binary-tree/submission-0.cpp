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

    void dfs(TreeNode* root,vector<vector<int>>& ans,int level) {
        if(root==nullptr)
            return;
        if(ans.size()<level)
        {
            vector<int> temp;
            ans.push_back(temp);
        }
        ans[level-1].push_back(root->val);
        dfs(root->left,ans,level+1);
        dfs(root->right,ans,level+1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        dfs(root,ans,1);
        return ans;
    }
};
