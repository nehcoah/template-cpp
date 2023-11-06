class Solution {
public:
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n = values.size();
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        auto dfs = [&](auto self, int x, int pa) -> long long {
            long long cur = values[x], sum = 0;
            for (int y : adj[x]) {
                if (y == pa) continue;
                sum += self(self, y, x);
            }
            return sum == 0 ? cur : min(sum, cur);
        };
        long long ans = dfs(dfs, 0, -1);
        return accumulate(values.begin(), values.end(), 0LL) - ans;
    }
};
