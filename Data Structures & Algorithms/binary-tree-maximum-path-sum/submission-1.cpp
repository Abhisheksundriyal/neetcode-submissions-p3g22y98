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
        if(node==nullptr)
            return 0;
        int temp1=recur(node->left,ans),temp2=recur(node->right,ans),temp=node->val;
        if(temp1>0)
            temp+=temp1;
        if(temp2>0)
            temp+=temp2;
        ans=max(ans,temp);
        if(max(temp1,temp2)<0)
            return node->val;
        return node->val+max(temp1,temp2);
    }

    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        recur(root,ans);
        return ans;
    }
};
