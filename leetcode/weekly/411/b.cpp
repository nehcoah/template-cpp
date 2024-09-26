class Solution {
    vector<vector<long long>> f;
    long long dfs(int i, int op, vector<int>& a, vector<int>& b) {
        if (i >= a.size()) return 0;
        if (f[i][op] != -1) return f[i][op];
        long long ans = 0;
        if (op == 2) {
            ans = max(ans, dfs(i + 1, 0, a, b) + a[i]);
            ans = max(ans, dfs(i + 2, 1, a, b) + a[i]);
            ans = max(ans, dfs(i + 1, 1, a, b) + b[i]);
            ans = max(ans, dfs(i + 2, 0, a, b) + b[i]);
        } else if (op == 0) {
            ans = max(ans, dfs(i + 1, 0, a, b) + a[i]);
            ans = max(ans, dfs(i + 2, 1, a, b) + a[i]);
        } else {
            ans = max(ans, dfs(i + 1, 1, a, b) + b[i]);
            ans = max(ans, dfs(i + 2, 0, a, b) + b[i]);
        }
        return f[i][op] = ans;
    }
public:
    long long maxEnergyBoost(vector<int>& a, vector<int>& b) {
        int n = a.size();
        f.assign(n, vector<long long>(3, -1));
        return dfs(0, 2, a, b);
    }
};
