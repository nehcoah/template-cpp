vector<vector<int>> factor(201);
auto init = []() {
    for (int i = 1; i < 201; i++) {
        for (int j = i * 2; j < 201; j += i) {
            factor[j].push_back(i);
        }
    }
    return 0;
}();

class Solution {
public:
    int minimumChanges(string s, int K) {
        int n = s.size();
        vector cost(n, vector<int>(n));
        for (int l = 0; l < n; l++) {
            for (int r = l + 1; r < n; r++) {
                int len = r - l + 1;
                int ans = n;
                for (int x : factor[len]) {
                    int res = 0;
                    for (int c = 0; c < x; c++) {
                        for (int i = l + c, j = r - x + 1 + c; i < j; i += x, j -= x) {
                            if (s[i] != s[j]) res++;
                        }
                    }
                    ans = min(ans, res);
                }
                cost[l][r] = cost[r][l] = ans;
            }
        }
        vector f(n + 1, vector<int>(K + 1, n));
        f[0][0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                for (int k = 1; k <= K; k++) {
                    f[i + 1][k] = min(f[i + 1][k], f[j][k - 1] + cost[j][i]);
                }
            }
        }
        return f[n][K];
    }
};
