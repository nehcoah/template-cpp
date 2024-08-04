class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        vector<vector<int>> cnt(n + 1, vector<int>(11));
        for (auto &p : pick) {
            cnt[p[0]][p[1]] += 1;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += any_of(cnt[i].begin(), cnt[i].end(), [&](int x) {
                return x > i;
            });
        }
        return ans;
    }
};
