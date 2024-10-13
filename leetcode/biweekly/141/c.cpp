class Solution {
public:
    int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
        unordered_set<int> st{targetIndices.begin(), targetIndices.end()};
        int n = source.size(), m = pattern.size();
        vector f(n + 1, vector<int>(m + 1, -1));
        auto dfs = [&](auto self, int i, int j) -> int {
            if (i == n) return j == m ? 0 : -1e9;
            if (f[i][j] != -1) return f[i][j];
            int ans = -1e9;
            if (st.count(i)) ans = max(ans, self(self, i + 1, j) + 1);
            if (j < m && source[i] == pattern[j]) ans = max(ans, self(self, i + 1, j + 1));
            ans = max(ans, self(self, i + 1, j));
            return f[i][j] = ans;
        };
        return dfs(dfs, 0, 0);
    }
};
