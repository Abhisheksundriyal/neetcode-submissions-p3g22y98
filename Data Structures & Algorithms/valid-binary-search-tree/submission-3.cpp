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

    pair<int,int> dfs(TreeNode* node,bool& ans) {
        pair<int,int> p={node->val,node->val};
        if(node->left==nullptr && node->right==nullptr)
            return p;
        if(node->left!=nullptr)
        {
            pair<int,int> temp=dfs(node->left,ans);
            if(temp.second>=node->val)
                ans=false;
            p.first=min(p.first,temp.first);
            p.second=max(p.second,temp.second);
        }
        if(node->right!=nullptr)
        {
            pair<int,int> temp=dfs(node->right,ans);
            if(temp.first<=node->val)
                ans=false;
            p.first=min(p.first,temp.first);
            p.second=max(p.second,temp.second);
        }
        return p;
    }

    bool isValidBST(TreeNode* root) {
        bool ans=true;
        dfs(root,ans);
        return ans;
    }
};
