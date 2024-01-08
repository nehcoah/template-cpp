class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        for (char c : s) if (c - '0' > limit) return 0;
        
        int m = s.size();
        auto check = [&](const string &t) -> long long {
            if (t.size() < s.size()) return 0;
            else if (t.size() == s.size()) return s <= t;
            
            int n = t.size();
            vector<long long> f(n, -1);
            auto dfs = [&](auto self, int i, bool isLimit, bool isNum) -> long long {
                if (i == n - m) {
                    if (isLimit) return t.substr(n - m) >= s;
                    return s[0] != '0' || s[0] == '0' && isNum;
                }
                if (!isLimit && isNum && f[i] != -1) return f[i];
                
                long long ans = 0;
                if (!isNum) ans = self(self, i + 1, false, false);
                int up = isLimit ? t[i] - '0' : 9;
                for (int d = 1 - isNum; d <= min(limit, up); d++){
                    ans += self(self, i + 1, isLimit && d == up, true);
                }
                if (!isLimit && isNum) f[i] = ans;
                return ans;
            };
            return dfs(dfs, 0, true, false);
        };
        
        return check(to_string(finish)) - check(to_string(start - 1));
    }
};
