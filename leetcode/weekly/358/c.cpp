// 2817
// https://leetcode.cn/problems/minimum-absolute-difference-between-elements-with-constraint/description/
// slide window

class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        set<int> s{nums[0]};
        int n = nums.size();
        int ans = INT_MAX;
        for (int i = x; i < n; i++) {
            auto it = s.lower_bound(nums[i]);
            if (it != s.end()) ans = min(ans, abs(*it - nums[i]));
            if (it != s.begin()) ans = min(ans, abs(*prev(it) - nums[i]));
            if (i - x + 1 < n) s.insert(nums[i - x + 1]);
        }
        return ans;
    }
};
