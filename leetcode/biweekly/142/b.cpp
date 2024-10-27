class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<int> ans(n);
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<int> p(26, -1);
        auto dfs = [&](auto self, int x) -> int {
            int pre = p[s[x] - 'a'];
            p[s[x] - 'a'] = x;
            for (int y : adj[x]) {
                auto sz = self(self, y);
                if (p[s[y] - 'a'] == -1) ans[x] += sz;
                else ans[p[s[y] - 'a']] += sz;
            }
            ans[x] += 1;
            p[s[x] - 'a'] = pre;
            return ans[x];
        };
        dfs(dfs, 0);
        return ans;
    }
};
