// https://leetcode.cn/problems/extra-characters-in-a-string/

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        int dp[n + 1];
        memset(dp, 0, sizeof(dp));
        unordered_set<string> st{dictionary.begin(), dictionary.end()};
        for (int i = 0; i < n; i++) {
            dp[i + 1] = dp[i] + 1;
            for (int j = i; j >= 0; j--) {
                if (st.count(s.substr(j, i - j + 1))) dp[i + 1] = min(dp[j], dp[i + 1]);
            }
        }
        return dp[n];
    }
};
