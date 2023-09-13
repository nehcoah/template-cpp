// 2830
// https://leetcode.cn/problems/maximize-the-profit-as-the-salesman/description/
// sorting, dp

class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        int m = offers.size(), f[m + 1];
        memset(f, 0, sizeof(f));
        sort(offers.begin(), offers.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });
        for (int i = 0; i < m; i++) {
            int s = offers[i][0], e = offers[i][1], c = offers[i][2];
            f[i + 1] = f[i];
            auto it = lower_bound(offers.begin(), offers.begin() + i, s, [&](auto & o, int x) {
                return o[1] < x;
            });
            if (it == offers.begin()) f[i + 1] = max(f[i + 1], c);
            else {
                int idx = it - offers.begin() - 1;
                f[i + 1] = max(f[i + 1], f[idx + 1] + c);
            }
        }
        return f[m];
    }
};
