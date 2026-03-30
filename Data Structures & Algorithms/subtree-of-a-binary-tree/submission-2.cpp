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

    vector<int> calculateZArray(string& s) {
        int n = s.length();
        vector<int> z(n, 0);
        int L = 0, R = 0;

        for (int i = 1; i < n; i++) {
            if (i <= R) {
                z[i] = min(R - i + 1, z[i - L]);
            }
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }
            if (i + z[i] - 1 > R) {
                L = i;
                R = i + z[i] - 1;
            }
        }
        return z;
    }

    bool isSubstring(string& s, string& t) {
        if (t.empty()) {
            return true;
        }
        if (s.empty()) {
            return false;
        }

        string combined = t + "#" + s;
        vector<int> z = calculateZArray(combined);
        int t_len = t.length();

        for (int i = t_len + 1; i < combined.length(); i++) {
            if (z[i] == t_len) {
                return true;
            }
        }
        return false;
    }
    
   string serialize(TreeNode* node) {
        if(!node)
            return "N,";
        return to_string(node->val) + "," + serialize(node->left) + serialize(node->right);
    }

    // Checks if subRoot is a subtree of root
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string ROOT_SERIALIZED = serialize(root);
        string SUBROOT_SERIALIZED = serialize(subRoot);
        return isSubstring(ROOT_SERIALIZED, SUBROOT_SERIALIZED);
    }
};
