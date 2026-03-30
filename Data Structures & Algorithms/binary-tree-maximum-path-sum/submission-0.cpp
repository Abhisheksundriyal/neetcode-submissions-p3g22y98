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

    int recur(TreeNode* root,int& ans) {
        int sum=root->val,sumL=sum,sumR=sum,X=sum;
        if(root->left!=nullptr)
        {
            int temp=recur(root->left,ans);
            if(temp>0)
            {
                sumL=sum+temp;
                X=X+temp;
            }
        }
        if(root->right!=nullptr)
        {
            int temp=recur(root->right,ans);
            if(temp>0)
            {
                sumR=sum+temp;
                X=X+temp;
            }
        }
        ans=max(ans,X);
        sum=max(sumL,sumR);
        return sum;
    }

    int maxPathSum(TreeNode* root) {
        int ans=root->val;
        recur(root,ans);
        return ans;
    }
};
