// 2801
// https://leetcode.cn/problems/count-stepping-numbers-in-range/description/
// digit dp

class Solution {
    const int mod = 1e9 + 7;
    using ll = long long;
    ll get(string& s) {
        vector<vector<ll>> dp(s.size(), vector<ll>(10, -1));
        return dfs(dp, s, 0, -1, true, false);
    }
    
    ll dfs(vector<vector<ll>>& dp, string& s, int i, int pre, bool isLimit, bool isNum) {
        if (i == s.size()) return isNum;
        if (pre != -1 && !isLimit && isNum && dp[i][pre] != -1) return dp[i][pre];
        ll ans = 0;
        if (!isNum) ans = dfs(dp, s, i + 1, pre, false, false) % mod;
        if (!isNum) {
            int up = isLimit ? s[i] - '0' : 9;
            for (int j = 1; j <= up; j++) ans = (ans + dfs(dp, s, i + 1, j, isLimit && j == up, true)) % mod;
        } else {
            if (pre != 0) {
                if (isLimit && (s[i] - '0') < (pre - 1)) {}
                else ans = (ans + dfs(dp, s, i + 1, pre - 1, isLimit && (pre - 1) == (s[i] - '0'), true)) % mod;
            }
            if (pre != 9) {
                if (isLimit && (s[i] - '0') < (pre + 1)) {}
                else ans = (ans + dfs(dp, s, i + 1, pre + 1, isLimit && (pre + 1) == (s[i] - '0'), true)) % mod;
            }
        }
        if (!isLimit && isNum) dp[i][pre] = ans;
        return ans;
    };
public:
    int countSteppingNumbers(string low, string high) {
        bool flag = true;
        for (int i = 0; i < low.size() - 1; i++) if (abs((low[i] - '0') - (low[i + 1] - '0')) != 1) {
            flag = false; break;
        }
        return (get(high) - get(low)  + flag + mod) % mod;
    }
};
