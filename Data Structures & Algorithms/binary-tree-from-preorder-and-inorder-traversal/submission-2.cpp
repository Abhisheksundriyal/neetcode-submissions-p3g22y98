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
    unordered_map<int,int> mp;
    TreeNode* recur(vector<int>& preorder,int L1,int R1,vector<int>& inorder,
                    int L2,int R2) {
        if(L1>R1 || L2>R2)
            return nullptr;
        TreeNode* newNode = new TreeNode(preorder[L1]);
        int s1=mp[preorder[L1]]-L2,s2=R2-mp[preorder[L1]];
        if(s1>0)
            newNode->left=recur(preorder,L1+1,L1+s1,inorder,L2,mp[preorder[L1]]-1);
        if(s2>0)
            newNode->right=recur(preorder,R1-s2+1,R1,inorder,mp[preorder[L1]]+1,R2);
        return newNode;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        for(int i=0;i<n;i++)
            mp[inorder[i]]=i;
        return recur(preorder,0,n-1,inorder,0,n-1);
    }
};
