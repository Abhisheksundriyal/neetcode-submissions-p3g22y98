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
    map<pair<TreeNode*,int>,int> myMap;
    int recur(TreeNode* node,int state) {
        if(!node) return 0;
        if(myMap.find({node,state})!=myMap.end()) return myMap[{node,state}];

        int ans=0;
        if(state==0) {
            int ans1=node->val+recur(node->left,1)+recur(node->right,1);
            int ans2=recur(node->left,0)+recur(node->right,0);
            ans=max(ans1,ans2);
        } else {
            int ans1=recur(node->left,0)+recur(node->right,0);
            ans=ans1;
        }
        return myMap[{node,state}]=ans;
    }
    int rob(TreeNode* root) {
        return recur(root,0);
    }
};