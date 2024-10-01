class Solution {
    const long long inf = 2e18;
    int n;
    vector<vector<long long>> f;
    long long dfs(int i, int j, vector<int> &a, vector<int> &b) {
        if (i == n) {
            return j == 4 ? 0 : -inf / 2;
        }
        if (j == 4) return 0;
        if (f[i][j] != -inf) return f[i][j];
        long long ans = -inf / 2;
        ans = max(ans, dfs(i + 1, j, a, b));
        ans = max(ans, dfs(i + 1, j + 1, a, b) + 1ll * b[i] * a[j]);
        return f[i][j] = ans;
    }
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        n = b.size();
        f.assign(n, vector<long long>(4, -inf));
        return dfs(0, 0, a, b);
    }
};
