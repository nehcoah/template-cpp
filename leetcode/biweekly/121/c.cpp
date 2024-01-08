class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        if (x <= y) return y - x;
        unordered_map<int, int> mp;
        auto dfs = [&](auto self, int c) {
            if (mp.count(c)) return mp[c];
            if (c <= y) return y - c;
            int ans = c - y;
            ans = min(ans, self(self, c / 11) + c % 11 + 1);
            ans = min(ans, self(self, c / 11 + 1) + (11 - c % 11) + 1);
            ans = min(ans, self(self, c / 5) + c % 5 + 1);
            ans = min(ans, self(self, c / 5 + 1) + (5 - c % 5) + 1);
            return mp[c] = ans;
        };
        return dfs(dfs, x);
    }
};
