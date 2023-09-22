// https://leetcode.cn/problems/cousins-in-binary-tree-ii/

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
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<TreeNode*> cur;
        root->val = 0;
        if (root->left) root->left->val = 0, cur.emplace_back(root->left);
        if (root->right) root->right->val = 0, cur.emplace_back(root->right);
        while (!cur.empty()) {
            int sum = 0;
            for (auto& c : cur) {
                if (c->left) sum += c->left->val;
                if (c->right) sum += c->right->val;
            }
            vector<TreeNode*> tmp;
            for (auto& c : cur) {
                int sub = (c->left ? c->left->val : 0) + (c->right ? c->right->val : 0);
                if (c->left) c->left->val = sum - sub, tmp.emplace_back(c->left);
                if (c->right) c->right->val = sum - sub, tmp.emplace_back(c->right);
            }
            cur = move(tmp);
        }
        return root;
    }
};
