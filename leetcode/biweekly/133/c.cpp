class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), cnt = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] ^ cnt == 0) {
                ans += 1, cnt = (cnt + 1) % 2;
            }
        }
        return ans;
    }
};
