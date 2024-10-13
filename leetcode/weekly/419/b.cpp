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
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        vector<int> sz;
        auto dfs = [&](auto self, auto cur) -> pair<int, int> {
            if (cur == nullptr) return {0, 0};
            auto [ls, ld] = self(self, cur->left);
            auto [rs, rd] = self(self, cur->right);
            if (ld == rd && ld != -1) sz.push_back(ls + rs + 1);
            return {ls + rs + 1, ld == rd && ld != -1 ? ld + 1 : -1};
        };
        dfs(dfs, root);
        if (sz.size() < k) return -1;
        sort(sz.rbegin(), sz.rend());
        return sz[k - 1];
    }
};
