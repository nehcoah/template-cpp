// https://leetcode.cn/problems/find-the-longest-semi-repetitive-substring/

class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int ans = 1, n = s.size();
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = i + 1; j < n; j++) {
                if (s[j] == s[j - 1]){
                    if (cnt == 0) cnt++;
                    else {
                        ans = max(j - i, ans);
                        break;
                    }
                }
                if (j == n - 1) ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};
