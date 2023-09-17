// https://leetcode.cn/problems/count-pairs-of-points-with-distance-k/description/

class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {
        unordered_map<int, unordered_map<int, int>> mp;
        int ans = 0;
        for (auto &c : coordinates) {
            int x = c[0], y = c[1];
            for (int i = max(0, x - 2 * k); i <= x + 2 * k; i++) {
                if (mp.count(i)) {
                    int target = (k - (x ^ i)) ^ y;
                    if (mp[i].count(target)) ans += mp[i][target];
                }
            }
            mp[x][y]++;
        }
        return ans;
    }
};
