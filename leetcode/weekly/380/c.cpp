class Solution {
    using ll = __int128;
public:
    long long findMaximumNumber(long long k, int x) {
        int mod = pow(2, x - 1), pw = pow(2, x);
        auto check = [&](long long t) {
            const int m = 63;
            vector<pair<ll, ll>> dp(m, {-1, -1});

            function<pair<ll, ll>(int, bool)> dfs = [&](int i, bool isLimit) -> pair<ll, ll> {
                if (i < 0) return {0, 1};
                if (!isLimit && dp[i].first != -1) return dp[i];
                ll ans = 0, cnt = 0;
                int up = isLimit ? t >> i & 1 : 1;
                for (int d = 0; d <= up; d++){
                    auto [a, b] = dfs(i - 1, isLimit && d == up);
                    ans += a, cnt += b;
                    if ((i + 1) % x == 0 && d == 1) ans += b;
                }
                if (!isLimit) dp[i] = {ans, cnt};
                return {ans, cnt};
            };
            return dfs(m - 1, true).first <= k;
        };
        
        long long l = 0, r = 3e18;
        while (l < r) {
            auto mid = l + r + 1 >> 1;
            if (check(mid)) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};
