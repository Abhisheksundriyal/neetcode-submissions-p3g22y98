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
        pair<int,int> L,R,A={node->val,node->val};
        if(node->left==nullptr || node->right==nullptr) {
            if(node->left==nullptr && node->right==nullptr)
                1;
            else if(node->right==nullptr) {
                L=recur(node->left,ans);
                A.first=min(A.first,L.first);
                A.second=max(A.second,L.second);
                if(L.second>=node->val)
                    ans=false;
            }
            else
            {
                R=recur(node->right,ans);
                A.first=min(A.first,R.first);
                A.second=max(A.second,R.second);
                if(R.first<=node->val)
                    ans=false;
            }
            return A;
        }
        L=recur(node->left,ans);
        R=recur(node->right,ans);
        A.first=min(A.first,L.first);
        A.second=max(A.second,L.second);
        A.first=min(A.first,R.first);
        A.second=max(A.second,R.second);
        if(L.second>=node->val || R.first<=node->val)
            ans=false;
        return A;
    }

    bool isValidBST(TreeNode* root) {
        if(root==nullptr)
            return true;
        bool ans=true;
        recur(root,ans);
        return ans;
    }
};