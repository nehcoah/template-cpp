vector<long long> pw;
auto init = [](){
    pw.push_back(1);
    for (int i = 1; i <= 62; i++) {
        pw.push_back(pw.back() * 2);
    }
    return 0;
}();

class Solution {
public:
    int waysToReachStair(int k) {
        vector f(65, vector<unordered_map<long long, int>>(2));
        auto dfs = [&](auto self, long long x, int j, int p) {
            if (x - 1 > k) return 0;
            if (f[j][p].count(x)) return f[j][p][x];
            int ans = x == k;
            if (p && x != 0) ans += self(self, x - 1, j, false);
            ans += self(self, x + pw[j], j + 1, true);
            return f[j][p][x] = ans;
        };
        return dfs(dfs, 1, 0, true);
    }
};
