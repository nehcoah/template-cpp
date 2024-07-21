class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 1) return 0;

        // 前缀和预处理分数之和
        long long sm[n + 2][n + 2];
        memset(sm, 0, sizeof(sm));
        for (int j = 1; j <= n; j++) for (int i = 1; i <= n; i++) sm[j][i] = sm[j][i - 1] + grid[i - 1][j - 1];

        const long long INF = 1e18; 
        long long f[n + 1][n + 1][2];
        for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) f[i][j][0] = f[i][j][1] = -INF;
        for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
            // 情况 4
            f[i][j][1] = sm[i - 1][j] + sm[i + 1][j];
            // 情况 1.1
            if (i > 1) for (int jj = 1; jj <= j; jj++) {
                long long det = (sm[i - 1][j] - sm[i - 1][jj]) + sm[i + 1][j] - sm[i][jj];
                f[i][j][1] = max(f[i][j][1], f[i - 1][jj][1] + det);
            }
            // 情况 1.2
            if (i > 1) for (int jj = j + 1; jj <= n; jj++) {
                long long det = sm[i + 1][j] - sm[i][j];
                f[i][j][0] = max({f[i][j][0], f[i - 1][jj][0] + det, f[i - 1][jj][1] + det});
            }
            // 情况 2.1
            if (i > 2) for (int jj = 1; jj <= j; jj++) {
                long long det = (sm[i - 1][j] - sm[i - 1][jj]) + sm[i + 1][j];
                f[i][j][1] = max({f[i][j][1], f[i - 2][jj][0] + det, f[i - 2][jj][1] + det});
            }
            // 情况 2.2
            if (i > 2) for (int jj = j + 1; jj <= n; jj++) {
                long long det = sm[i + 1][j];
                f[i][j][1] = max({f[i][j][1], f[i - 2][jj][0] + det, f[i - 2][jj][1] + det});
            }
            // 情况 3
            if (i > 3) for (int jj = 1; jj <= n; jj++) {
                long long det = sm[i - 1][j] + sm[i + 1][j];
                f[i][j][1] = max({f[i][j][1], f[i - 3][jj][0] + det, f[i - 3][jj][1] + det});
            }
        }

        long long ans = 0;
        for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) ans = max({ans, f[i][j][0], f[i][j][1]});
        return ans;
    }
};

// 作者：TsReaper
// 链接：https://leetcode.cn/problems/maximum-score-from-grid-operations/solutions/2851294/dp-fen-lei-tao-lun-by-tsreaper-6nkf/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
