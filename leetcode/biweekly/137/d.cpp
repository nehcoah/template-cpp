class Solution {
public:
    long long maximumValueSum(vector<vector<int>>& board) {
        auto pre = board, suf = board;
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n; j++) {
                pre[i + 1][j] = max(pre[i + 1][j], pre[i][j]);
            }
        }
        for (int i = m - 1; i > 0; i--) {
            for (int j = 0; j < n; j++) {
                suf[i - 1][j] = max(suf[i - 1][j], suf[i][j]);
            }
        }
        auto check = [&](vector<int> &cur) {
            set<pair<long long, int>> ans;
            for (int i = 0; i < n; i++) {
                ans.emplace(cur[i], i);
                if (ans.size() > 3) ans.erase(ans.begin());
            }
            return ans;
        };
        
        long long ans = -1e18;
        for (int i = 1; i < m - 1; i++) {
            auto p = check(pre[i - 1]), c = check(board[i]), s = check(suf[i + 1]);
            for (auto [x1, y1] : p) {
                for (auto [x2, y2] : c) {
                    if (y1 != y2) for (auto [x3, y3] : s) {
                        if (y1 != y3 && y2 != y3) ans = max(ans, x1 + x2 + x3);
                    }
                }
            }
        }
        return ans;
    }
};
