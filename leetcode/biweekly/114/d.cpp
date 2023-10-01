class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int ans = 0;
        auto dfs = [&](auto self, int x, int pa) -> int {
            int mod = values[x] % k;
            for (int y : adj[x]) {
                if (y == pa) continue;
                mod = (mod + self(self, y, x)) % k;
            }
            if (mod == 0) {
                ans++;
            }
            return mod;
        };
        
        dfs(dfs, 0, -1);
        return ans;
    }
};
