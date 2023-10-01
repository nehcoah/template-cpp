class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        int ans = 0, n = nums.size();
        if (sum <= target) ans += target / sum * n;
        target %= sum;
        if (target == 0) return ans;
        
        for (int i = 0; i < n; i++) nums.push_back(nums[i]);
        long long l = 0, r = 0, cur = 0, mn = 2 * n;
        for (; r < 2 * n; r++) {
            cur += nums[r];
            while (l < r && cur > target) cur -= nums[l++];
            if (cur == target) mn = min(mn, r - l + 1);
        }
        if (mn == 2 * n) return -1;
        else return ans + mn;
    }
};
