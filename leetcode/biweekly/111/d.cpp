// 2827
// https://leetcode.cn/problems/number-of-beautiful-integers-in-the-range/description/
// digit dp

class Solution {
    int countSpecialNumbers(int n, int k) {
        string s = to_string(n);
        int m = s.length(), dp[m][21][25];
        memset(dp, -1, sizeof(dp));

        string str;
        function<int(int, int, int, bool, bool)> dfs = [&](int i, int mod, int cnt, bool isLimit, bool isNum) -> int {
            if (i == m) return !str.empty() && mod == 0 && cnt == 12;
            if (!isLimit && isNum && dp[i][mod][cnt] != -1) return dp[i][mod][cnt];
            int ans = 0;
            if (!isNum) ans = dfs(i + 1, mod, cnt, false, false);
            int up = isLimit ? s[i] - '0' : 9;
            for (int d = 1 - isNum; d <= up; d++){
                str.push_back(d + '0');
                ans += dfs(i + 1, (mod * 10 + d) % k, cnt + (d & 1 ? 1 : -1), isLimit && d == up, true);
                str.pop_back();
            }
            if (!isLimit && isNum) dp[i][mod][cnt] = ans;
            return ans;
        };
        return dfs(0, 0, 12, true, false);
    }
public:
    int numberOfBeautifulIntegers(int low, int high, int k) {
        return countSpecialNumbers(high, k) - countSpecialNumbers(low - 1, k);
    }
};
