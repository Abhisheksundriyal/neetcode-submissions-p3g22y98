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
    TreeNode* findNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        if(root->val==key) return root;
        if(key<root->val) return findNode(root->left,key);
        return findNode(root->right,key);
    }
    TreeNode* findLargeNode(TreeNode* root) {
        if(!root) return nullptr;
        if(root->right==nullptr) return root;
        return findLargeNode(root->right);
    }

    TreeNode* findSmallNode(TreeNode* root) {
        if(!root) return nullptr;
        if(root->left==nullptr) return root;
        return findSmallNode(root->left);
    }

    void deleteLargeNode(TreeNode* root,TreeNode* largeNode) {
        if(!root) return;
        if(root->left==largeNode) {
            root->left=root->left->left;
            return;
        }
        if(root->right==largeNode) {
            root->right=root->right->left;
            return;
        }
        if(largeNode->val<root->val) deleteLargeNode(root->left,largeNode);
        else deleteLargeNode(root->right,largeNode);
    }

    void deleteSmallNode(TreeNode* root,TreeNode* smallNode) {
        if(!root) return;
        if(root->left==smallNode) {
            root->left=root->left->right;
            return;
        }
        if(root->right==smallNode) {
            root->right=root->right->right;
            return;  
        }
        if(smallNode->val<root->val) deleteSmallNode(root->left,smallNode);
        else deleteSmallNode(root->right,smallNode);
    }


    
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* node=findNode(root,key);
        if(!node) return root;
        TreeNode* largeNode=findLargeNode(node->left);
        if(largeNode) {
            int temp=largeNode->val;
            deleteLargeNode(root,largeNode);
            node->val=temp;
            return root;
        }
        TreeNode* smallNode=findSmallNode(node->right);
        if(smallNode) {
            int temp=smallNode->val;
            deleteSmallNode(root,smallNode);
            node->val=temp;
            return root;
        }
        if(node==root) return nullptr;
        deleteSmallNode(root,node);
        return root;
    }
};