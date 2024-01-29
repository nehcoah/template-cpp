class Solution {
public:
    int minOrAfterOperations(vector<int>& nums, int k) {
        int ans = 0, mask = 0;
        for (int i = 29; i >= 0; i--) {
            mask |= 1 << i;
            int cur = -1, cnt = 0;
            for (int x : nums) {
                cur &= x & mask;
                if (cur) cnt++;
                else cur = -1;
            }
            if (cnt > k) {
                ans |= 1 << i;
                mask ^= 1 << i;
            }
        }
        return ans;
    }
};
