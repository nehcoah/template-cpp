class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const int mod = 1e9 + 7;
        
        vector<int> cnt(31);
        for (int x : nums) {
            for (int i = 0; i < 31; i++) {
                cnt[i] += (x >> i) & 1;
            }
        }
        long long ans = 0;
        for (int j = 0; j < k; j++) {
            long long cur = 0;
            for (int i = 30; i >= 0; i--) {
                cur <<= 1;
                if (cnt[i] > 0) cur |= 1, cnt[i]--;
            }
            ans = (ans + cur * cur) % mod;
        }
        return ans;
    }
};
