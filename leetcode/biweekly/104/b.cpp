// https://leetcode.cn/problems/sum-in-a-matrix/

class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        for (auto& n : nums) sort(n.begin(), n.end(), greater<>());
        int ans = 0, m = nums.size(), n = nums[0].size();
        for (int i = 0; i < n; i++) {
            int mx = -1;
            for (int j = 0; j < m; j++){
                mx = max(mx, nums[j][i]);
            }
            ans += mx;
        }
        return ans;
    }
};
