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
    bool dfs(TreeNode* node, int target) {
        if(!node) return true;

        if(dfs(node->left,target)) node->left=nullptr;
        if(dfs(node->right,target)) node->right=nullptr;

        if(dfs(node->left,target) && dfs(node->right,target)) {
            return node->val==target;
        }

        return false;
        
    }
    void traverse(TreeNode* node) {
        if(!node) return;
        cout<<node->val<<" , ";
        traverse(node->left);
        traverse(node->right);
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        // traverse(root);
        dfs(root,target);
        // cout<<"\n";
        // traverse(root);
        if(root->left==nullptr && root->right==nullptr && root->val==target) return nullptr;
        return root;
    }
};