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
    unordered_map<int,int> mp;
public:

    TreeNode* recur(vector<int>& preorder,vector<int>& inorder,int l1,int r1,int l2,int r2){
        if(l1>r1)
            return nullptr;
        TreeNode* node = new TreeNode(preorder[l1]);
        int idx=mp[preorder[l1]];
        node->left=recur(preorder,inorder,l1+1,l1+(idx-l2),l2,idx-1);
        node->right=recur(preorder,inorder,l1+(idx-l2)+1,r1,idx+1,r2);
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]]=i;
        return recur(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }
};
