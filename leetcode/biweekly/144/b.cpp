class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        int n = s.size();

        vector<vector<long long>> n_f(26, vector<long long>(26, 1e18));
        vector<vector<long long>> p_f(26, vector<long long>(26, 1e18));
        for (int i = 0; i < 26; i++) {
            n_f[i][i] = 0;
            p_f[i][i] = 0;
        }
        for (int i = 0; i < 26; i++) {
            n_f[i][(i + 1) % 26] = nextCost[i];
        }
        for (int i = 0; i < 26; i++) {
            p_f[i][(i + 25) % 26] = previousCost[i];
        }
        for (int p = 0; p < 26; p++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    n_f[i][j] = min(n_f[i][j], n_f[i][p] + n_f[p][j]);
                }
            }
        }
        for (int p = 0; p < 26; p++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    p_f[i][j] = min(p_f[i][j], p_f[i][p] + p_f[p][j]);
                }
            }
        }

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += min(n_f[s[i] - 'a'][t[i] - 'a'], p_f[s[i] - 'a'][t[i] - 'a']);
        }
        return ans;
    }
};
