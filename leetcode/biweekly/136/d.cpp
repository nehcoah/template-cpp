class Solution {
public:
    vector<int> timeTaken(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        vector<int> mx(n);
        auto dfs = [&](auto self, int x, int pa) -> int {
            for (int y : adj[x]) {
                if (y == pa) continue;
                int cur = self(self, y, x) + (y % 2 == 0 ? 2 : 1);
                mx[x] = max(mx[x], cur);
            }
            return mx[x];
        };
        dfs(dfs, 0, -1);
        
        vector<int> ans(n);
        auto reroot = [&](auto self, int x, int pa, int pre) -> void {
            ans[x] = max(pre, mx[x]);
            int mx1 = 0, mx2 = 0;
            for (int y : adj[x]) {
                if (y == pa) continue;
                int cur = mx[y] + (y % 2 == 0 ? 2 : 1);
                if (cur >= mx1) mx2 = mx1, mx1 = cur;
                else if (cur >= mx2) mx2 = cur;
            }
            for (int y : adj[x]) {
                if (y == pa) continue;
                int cur = ((mx[y] + (y % 2 == 0 ? 2 : 1)) == mx1 ? mx2 : mx1);
                self(self, y, x, max(pre, cur) + (x % 2 == 0 ? 2 : 1));
            }
        };
        reroot(reroot, 0, -1, 0);

        return ans;
    }
};
