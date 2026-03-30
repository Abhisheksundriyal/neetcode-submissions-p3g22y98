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
    void recur(TreeNode* node,int level,
                unordered_set<int>& mySet,vector<int>& ans)
    {
        if(!node)
            return;
        if(mySet.find(level)==mySet.end())
        {
            mySet.insert(level);
            ans.push_back(node->val);
        }
        recur(node->right,level+1,mySet,ans);
        recur(node->left,level+1,mySet,ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        unordered_set<int> mySet;
        vector<int> ans;
        recur(root,1,mySet,ans);
        return ans;
    }
};
