class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        vector<int> cnt(31);
        for (int x : nums) {
            for (int i = 31; i >= 0; i--) {
                if (x >> i & 1) cnt[i]++;
            }
        }
        int ans = 0;
        for (int i = 0; i < 31; i++) {
            if (cnt[i] >= k) ans |= 1 << i;
        }
        return ans;
    }
};
