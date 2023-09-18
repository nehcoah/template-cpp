// https://leetcode.cn/problems/partition-string-into-minimum-beautiful-substrings/

class Solution {
    const int inf = 0x3f3f3f3f;
public:
    int minimumBeautifulSubstrings(string s) {
        unordered_set<string> st {"1", "101", "11001", "1111101", "1001110001", "110000110101", "11110100001001"};
        int n = s.size(), dp[n + 1];
        memset(dp, inf, sizeof(dp));
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j >= 0; j--) {
                if (st.count(s.substr(j, i - j + 1))) dp[i + 1] = min(dp[i + 1], dp[j] + 1);
            }
        }
        return dp[n] == inf ? -1 : dp[n];
    }
};
