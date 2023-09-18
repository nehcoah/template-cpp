// https://leetcode.cn/problems/find-the-punishment-number-of-an-integer/

int ans[1001];
auto init = [](){
    memset(ans, 0, sizeof(ans));
    for (int i = 1; i < 1001; i++) {
        int t = i * i;
        string s = to_string(t);
        auto dfs = [&](auto self, int cur, int sum) {
            if (ans[i] != 0) return;
            if (sum > t) return;
            if (cur == s.size() && sum == i) {
                ans[i] = t;
                return;
            }
            for (int j = cur; j < s.size(); j++) {
                self(self, j + 1, sum + stoi(s.substr(cur, j - cur + 1)));
            }
        };
        dfs(dfs, 0, 0);
        ans[i] += ans[i - 1];
    }
    return 0;
}();

class Solution {
public:
    int punishmentNumber(int n) {
        return ans[n];
    }
};
