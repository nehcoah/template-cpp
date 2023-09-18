// https://leetcode.cn/problems/count-of-integers/

class Solution {
    const int mod = 1e9 + 7;
public:
    int count(string num1, string num2, int min_sum, int max_sum) {
        int n1 = num1.size(), n2 = num2.size();
        int dp1[n1][401], dp2[n2][401];
        memset(dp1, -1, sizeof(dp1));
        memset(dp2, -1, sizeof(dp2));
        
        function<int(int, int, bool)> dfs1 = [&](int i, int sum, bool isLimit) -> int {
            if (sum > max_sum) return 0;
            if (i == n1) return sum >= min_sum;
            if (!isLimit && dp1[i][sum] != -1) return dp1[i][sum];
            long long ans = 0;
            int up = isLimit ? num1[i] -'0' : 9;
            for (int d = 0; d <= up; d++){
                ans = (ans + dfs1(i + 1, sum + d, isLimit && d == up)) % mod;
            }
            if (!isLimit) dp1[i][sum] = ans;
            return ans;
        };
        
        function<int(int, int, bool)> dfs2 = [&](int i, int sum, bool isLimit) -> int {
            if (sum > max_sum) return 0;
            if (i == n2) return sum >= min_sum;
            if (!isLimit && dp2[i][sum] != -1) return dp2[i][sum];
            long long ans = 0;
            int up = isLimit ? num2[i] -'0' : 9;
            for (int d = 0; d <= up; d++){
                ans = (ans + dfs2(i + 1, sum + d, isLimit && d == up)) % mod;
            }
            if (!isLimit) dp2[i][sum] = ans;
            return ans;
        };
        int ret = dfs2(0, 0, true) - dfs1(0, 0, true);
        int cur = 0;
        for (char c : num1) cur += c - '0';
        if (cur >= min_sum && cur <= max_sum) ret = (ret + mod + 1) % mod;
        return ret;
    }
};
