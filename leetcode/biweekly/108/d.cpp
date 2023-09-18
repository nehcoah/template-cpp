// https://leetcode.cn/problems/number-of-black-blocks/

class Solution {
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        unordered_set<int> s[m + 2];
        vector<long long> ans(5);
        ans[0] = (long long)(m - 1) * (n - 1);
        for (auto& c : coordinates) {
            int x = c[0], y = c[1], cur[3][3];
            // cout << x << " " << y << endl;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) cur[i][j] = s[x + 1 + i - 1].count(y + j - 1);
            }
            int info[4] = {cur[0][0] + cur[0][1] + cur[1][0], cur[0][1] + cur[0][2] + cur[1][2], cur[1][0] + cur[2][0] + cur[2][1], cur[1][2] + cur[2][1] + cur[2][2]};
            // cout << info[0] << " " << info[1] << " " << info[2] << " " << info[3] << endl;
            if (x == 0) {
                if (y == 0) ans[info[3]]--, ans[info[3] + 1]++;
                else if (y == n - 1) ans[info[2]]--, ans[info[2] + 1]++;
                else ans[info[3]]--, ans[info[2]]--, ans[info[3] + 1]++, ans[info[2] + 1]++;
            } else if (x == m - 1) {
                if (y == 0) ans[info[1]]--, ans[info[1] + 1]++;
                else if (y == n - 1) ans[info[0]]--, ans[info[0] + 1]++;
                else ans[info[1]]--, ans[info[0]]--, ans[info[1] + 1]++, ans[info[0] + 1]++;
            } else if (y == 0) ans[info[1]]--, ans[info[3]]--, ans[info[1] + 1]++, ans[info[3] + 1]++;
            else if (y == n - 1) ans[info[0]]--, ans[info[2]]--, ans[info[0] + 1]++, ans[info[2] + 1]++;
            else {
                ans[info[1]]--, ans[info[0]]--, ans[info[1] + 1]++, ans[info[0] + 1]++;
                ans[info[2]]--, ans[info[3]]--, ans[info[2] + 1]++, ans[info[3] + 1]++;
            }
            s[x + 1].insert(y);
        }
        return ans;
    }
};
