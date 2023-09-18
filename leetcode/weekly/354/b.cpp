// https://leetcode.cn/problems/maximum-beauty-of-an-array-after-applying-operation/

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = -1, r = 0, ans = 0;
        for (; r < n; ) {
            l++;
            while (l > 0 && nums[l] == nums[l - 1]) l++;
            while (r < n && nums[r] <= nums[l] + 2 * k) r++;
            // cout << l << " " << r << endl;
            ans = max(ans, r - l);
        }
        ans = max(ans, r - l);
        return ans;
    }
};
