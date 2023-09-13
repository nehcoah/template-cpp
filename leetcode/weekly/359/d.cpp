// 2831
// https://leetcode.cn/problems/find-the-longest-equal-subarray/description/
// slide window, binary search

class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int n = nums.size(), l = 0, r = n;
        auto check = [&](int x) {
            int mp[n + 1];
            memset(mp, 0, sizeof(mp));
            int i = 0;
            for (; i < min(x + k, n); i++) {
                if (++mp[nums[i]] >= x) return true;
            }
            for (; i < n; i++) {
                mp[nums[i - x - k]]--;
                if (++mp[nums[i]] >= x) return true;
            }
            return false;
        };
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (check(mid)) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};
