class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        
        array<int, 31> bit{};
        auto check = [&]() {
            int x = 0;
            for (int i = 30; i >= 0; i--) {
                if (bit[i]) x |= 1 << i;
            }
            return x;
        };
        
        int ans = -1;
        for (int i = 0, j = 0; i < n; i++) {
            int x = nums[i];
            for (int t = 30; t >= 0; t--) {
                if (x >> t & 1) bit[t] += 1;
            }
            while (j <= i && check() >= k) {
                if (ans == -1 || ans > i - j + 1) ans = i - j + 1;
                for (int t = 30; t >= 0; t--) {
                    if (nums[j] >> t & 1) bit[t] -= 1;
                }
                j += 1;
            }
        }
        return ans;
    }
};
