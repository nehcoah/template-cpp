// 2790
// https://leetcode.cn/problems/maximum-number-of-groups-with-increasing-length/description/
//

class Solution {
public:
    int maxIncreasingGroups(vector<int>& usageLimits) {
        sort(usageLimits.begin(), usageLimits.end());
        long long ans = 0, sum = 0;
        for (int x : usageLimits) {
            sum += x;
            if ((ans + 2) * (ans + 1) / 2 <= sum) ans++;
        }
        return ans;
    }
};
