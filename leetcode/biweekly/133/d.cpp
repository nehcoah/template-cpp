class Solution {
public:
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        const int mod = 1e9 + 7;
        vector<int> r(n, -1);
        for (auto &re : requirements) {
            r[re[0]] = re[1];
        }
        if (r[0] > 0) return 0;
        
        int mx = *max_element(r.begin(), r.end());
        vector f(n, vector<int>(mx + 1));
        f[0][0] = 1;
        for (int i = 1; i < n; i++) {
            int x = 0, y = mx;
            if (r[i] != -1) x = y = r[i];
            for (int j = x; j <= y; j++) {
                for (int d = 0; d <= min(i, j); d++) {
                    f[i][j] = (f[i][j] + f[i - 1][j - d]) % mod;
                }
            }
        }
        return f[n - 1][r[n - 1]];
    }
};
