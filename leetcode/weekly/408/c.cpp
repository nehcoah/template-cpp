class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size(), cnt = 0, ans = 0;
        vector<int> sum(n + 1), idx;
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + (s[i] == '1');
            if (s[i] == '0') {
                idx.push_back(i);
                ans += (1 + cnt) * cnt / 2;
                cnt = 0;
            } else {
                cnt += 1;
            }
        }
        ans += (1 + cnt) * cnt / 2;

        for (int p = 1; p <= min((int)idx.size(), 201); p++) {
            // cout << p << endl;
            for (int i = p - 1; i < idx.size(); i++) {
                int m = sum[idx[i] + 1] - sum[idx[i - p + 1] + 1];
                int l = (i - p + 1 == 0) ? sum[idx[i - p + 1] + 1] : sum[idx[i - p + 1] + 1] - sum[idx[i - p] + 1];
                int r = (i == idx.size() - 1) ? sum.back() - sum[idx[i] + 1] : sum[idx[i + 1] + 1] - sum[idx[i] + 1];
                if (m + l + r < p * p) continue;
                int x = p * p - m;
                // for (int j = 0; j <= l; j++) {
                //     if (x - j <= r) {
                //         ans += r - x + j + 1;
                //     }
                // }
                if (x < 0) {
                    ans += (l + 1) * (r + 1);
                } else {
                    int y = r - (x - max(0, x - r)) + 1;
                    int z = r - (x - min(x, l)) + 1;
                    ans += (y + z) * (z - y + 1) / 2;
                    if (x < l) ans += (l - x) * (r + 1);
                    // cout << idx[i] << " " << idx[i - p + 1] << " " << x << " " << y << " " << z << " " << l << " " << r << endl;
                }
            }
        }
        return ans;
    }
};
