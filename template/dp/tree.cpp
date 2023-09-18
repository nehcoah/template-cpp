// 换根dp
// 两次遍历

// Leetcode. 834. https://leetcode.cn/problems/sum-of-distances-in-tree/description/
class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> size(n, 1), ans(n);
        auto dfs = [&](auto self, int x, int pre, int cnt) -> void {
            ans[0] += cnt;
            for (int y : adj[x]) {
                if (y == pre) continue;
                self(self, y, x, cnt + 1);
                size[x] += size[y];
            }
        };
        dfs(dfs, 0, -1, 0);

        auto reroot = [&](auto self, int x, int pre) -> void {
            for (int y : adj[x]) {
                if (y == pre) continue;
                ans[y] = ans[x] - (size[y] - 1) + (n - size[y] - 1);
                self(self, y, x);
            }
        };
        reroot(reroot, 0, -1);

        return ans;
    }
};


// https://leetcode.cn/problems/minimum-edge-reversals-so-every-node-is-reachable/description/
class Solution {
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].emplace_back(e[1], 1);
            adj[e[1]].emplace_back(e[0], -1);
        }

        vector<int> ans(n);
        auto dfs = [&](auto self, int x, int pre) -> void {
            for (auto [y, d] : adj[x]) {
                if (y == pre) continue;
                if (d == -1) ans[0] += 1;
                self(self, y, x);
            }
        };
        dfs(dfs, 0, -1);

        auto reroot = [&](auto self, int x, int pre) -> void {
            for (auto [y, d] : adj[x]) {
                if (y == pre) continue;
                ans[y] = ans[x] + d;
                self(self, y, x);
            }
        };
        reroot(reroot, 0, -1);

        return ans;
    }
};


// 树形dp
// 打家劫舍III https://leetcode.cn/problems/house-robber-iii/description/

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
    int rob(TreeNode* root) {
        auto dfs = [&](auto self, auto *cur) -> pair<int, int> {
            if (cur == nullptr) return {0, 0};
            auto l = self(self, cur->left);
            auto r = self(self, cur->right);
            return {l.second + r.second + cur->val, max(l.first, l.second) + max(r.first, r.second)};
        };
        auto ans = dfs(dfs, root);
        return max(ans.first, ans.second);
    }
};
