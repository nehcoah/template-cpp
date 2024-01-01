array<int, 26> operator-(const array<int, 26> &x, const array<int, 26> &y) {
    array<int, 26> z{};
    for (int i = 0; i < 26; i++) {
        z[i] = x[i] - y[i];
    }
    return z;
}

class Solution {
public:
    vector<bool> canMakePalindromeQueries(string s, vector<vector<int>>& queries) {
        int n = s.size() / 2;
        string l = s.substr(0, n), r = s.substr(n);
        reverse(r.begin(), r.end());
        int mn = 0, mx = n - 1;
        while (mn < n && l[mn] == r[mn]) mn++;
        while (mx >= 0 && l[mx] == r[mx]) mx--;
        vector<array<int, 26>> lsum(n + 1), rsum(n + 1);
        for (int i = 0; i < n; i++) {
            lsum[i + 1] = lsum[i];
            lsum[i + 1][l[i] - 'a']++;
            rsum[i + 1] = rsum[i];
            rsum[i + 1][r[i] - 'a']++;
        }

        auto check = [&](int x, int y) {
            return lsum[y + 1] - lsum[x] == rsum[y + 1] - rsum[x];
        };

        auto get = [&](auto &s, int x, int y) {
            return s[y + 1] - s[x];
        };

        auto solve = [&](vector<int> &q) {
            int a = q[0], b = q[1], c = n * 2 - q[3] - 1, d = n * 2 - q[2] - 1;
            int t = min(a, c);
            if (t > mn || !check(0, t - 1)) return false;
            t = max(b, d);
            if (t < mx || !check(t + 1, n - 1)) return false;
            if (a > d) {
                if (!check(d + 1, a - 1)) return false;
                if (!check(a, b) || !check(c, d)) return false;
            } else if (c > b) {
                if (!check(b + 1, c - 1)) return false;
                if (!check(a, b) || !check(c, d)) return false;
            } else {
                vector<pair<int, int>> ab, cd, mid;
                if (a < c) ab.emplace_back(a, c - 1);
                if (c < a) cd.emplace_back(c, a - 1);
                if (b < d) cd.emplace_back(b + 1, d);
                if (b > d) ab.emplace_back(d + 1, b);
                mid.emplace_back(max(a, c), min(b, d));
                auto absum = get(lsum, a, b), cdsum = get(rsum, c, d);
                for (auto [x, y] : ab) {
                    absum = absum - get(rsum, x, y);
                }
                for (auto [x, y] : cd) {
                    cdsum = cdsum - get(lsum, x, y);
                }
                if (absum != cdsum) return false;
                for (int i = 0; i < 26; i++) if (absum[i] < 0 || cdsum[i] < 0) return false;
            }
            return true;
        };

        vector<bool> ans;
        for (auto &q : queries) ans.push_back(solve(q));
        return ans;
    }
};
