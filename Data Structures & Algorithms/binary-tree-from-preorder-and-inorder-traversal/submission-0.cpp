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

    TreeNode* recur(vector<int>& preorder,int l1,int r1,int l2,int r2,unordered_map<int,int>& myMap) {
        if(l1>r1 || l2>r2)
            return nullptr;
        TreeNode* node = new TreeNode(preorder[l1]);
        int N=r1-l1,idx=myMap[preorder[l1]],sz=idx-l2;
        if(sz>0)
            node->left=recur(preorder,l1+1,l1+sz,l2,idx-1,myMap);
        if(N-sz>0)
            node->right=recur(preorder,l1+sz+1,r1,idx+1,r2,myMap);
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        unordered_map<int,int> myMap;
        for(int i=0;i<n;i++)
            myMap[inorder[i]]=i;
        return recur(preorder,0,n-1,0,n-1,myMap);
    }
};
