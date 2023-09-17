// 换根dp
// Leetcode. 834. https://leetcode.cn/problems/sum-of-distances-in-tree/description/
// 两次遍历

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
