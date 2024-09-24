class Solution {
public:
    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        int ans = 0;
        auto dfs = [&](auto self, int x, int pa) -> int {
            vector<int> cnt;
            for (int y : adj[x]) {
                if (y == pa) continue;
                cnt.push_back(self(self, y, x));
            }
            if (cnt.empty() || count(cnt.begin(), cnt.end(), cnt[0]) == cnt.size()) {
                ans += 1;
            }
            return accumulate(cnt.begin(), cnt.end(), 0) + 1;
        };
        dfs(dfs, 0, -1);
        return ans;
    }
};
