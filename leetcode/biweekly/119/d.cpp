class Solution {
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        const int inf = 0x3f3f3f3f;
        int ans = 0;
        for (int mask = 0; mask < (1 << n); mask++) {
            vector<vector<int>> w(n, vector<int>(n, inf));
            for (int i = 0; i < n; i++) w[i][i] = 0;
            for (auto &r : roads) {
                int u = r[0], v = r[1], x = r[2];
                if (mask >> u & 1 || mask >> v & 1) continue;
                w[u][v] = min(w[u][v], x);
                w[v][u] = min(w[v][u], x);
            }
            for (int p = 0; p < n; p++) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        w[i][j] = min(w[i][j], w[i][p] + w[p][j]);
                    }
                }
            }
            
            bool good = true;
            for (int i = 0; i < n; i++) {
                if (mask >> i & 1) continue;
                for (int j = 0; j < n; j++) {
                    if (mask >> j & 1) continue;
                    if (w[i][j] > maxDistance) {
                        good = false;
                        break;
                    }
                }
            }
            ans += good;
        }
        return ans;
    }
};
