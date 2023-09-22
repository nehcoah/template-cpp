// https://leetcode.cn/problems/sliding-subarray-beauty/

class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int cnt[101], n = nums.size();
        memset(cnt, 0, sizeof(cnt));
        auto check = [&]() {
            int cur = 0;
            for (int i = 0; i < 50; i++) {
                cur += cnt[i];
                if (cur >= x) return i - 50;
            }
            return 0;
        };
        for (int i = 0; i < k; i++) cnt[nums[i] + 50]++;
        vector<int> ans{check()};
        for (int i = k; i < n; i++) {
            cnt[nums[i] + 50]++;
            cnt[nums[i - k] + 50]--;
            ans.push_back(check());
        }
        return ans;
    }
};
