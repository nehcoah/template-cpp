class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1e9);
        for (int i = 0; i < n; i++) {
            int x = ((i + nums[i]) % n + n) % n;
            ans[i] = nums[x];
        }
        for (int i = 0; i < n; i++) {
            if (ans[i] == 1e9) {
                ans[i] = nums[i];
            }
        }
        return ans;
    }
};
