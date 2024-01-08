class Solution {
public:
    int maxPartitionsAfterOperations(string s, int k) {
        int n = s.size();
        
        unordered_map<long long, int> mp;
        auto dfs = [&](auto self, int i, int mask, int t) {
            if (i == n) {
                return 1;
            }
            long long f = (long long) i << 32 | mask << 1 | t;
            if (mp.count(f)) return mp[f];
            
            int ans = 0;
            int n_mask = mask | (1 << (s[i] - 'a'));
            if (__builtin_popcount(n_mask) > k) {
                ans = self(self, i + 1, 1 << (s[i] - 'a'), t) + 1;
            } else {
                ans = self(self, i + 1, n_mask, t);
            }
            if (!t) {
                for (int c = 0; c < 26; c++) {
                    n_mask = mask | (1 << c);
                    if (__builtin_popcount(n_mask) > k) {
                        ans = max(ans, self(self, i + 1, 1 << c, true) + 1);
                    } else {
                        ans = max(ans, self(self, i + 1, n_mask, true));
                    }
                }
            }
            return mp[f] = ans;
        };
        return dfs(dfs, 0, 0, false);
    }
};
