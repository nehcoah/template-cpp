// 2811
// https://leetcode.cn/problems/check-if-it-is-possible-to-split-array/
// 

class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
        int n = nums.size();
        if (n < 3) return true;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] + nums[i + 1] >= m) return true;
        }
        return false;
    }
};

class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
        int sum = 0;
        for (int x : nums) sum += x;
        int n = nums.size();
        if (n == 1) return true;
        int f[n][n];
        memset(f, -1, sizeof(f));
        auto dfs = [&](auto self, int i, int j) -> int {
            if (i + 1 == j) return true;
            if (f[i][j] != -1) return f[i][j];
            int ans = 0;
            if (sum - nums[i] >= m) {
                sum -= nums[i];
                ans |= self(self, i + 1, j);
                sum += nums[i];
            }
            if (sum - nums[j] >= m) {
                sum -= nums[j];
                ans |= self(self, i, j - 1);
                sum += nums[j];
            }
            return f[i][j] = ans;
        };
        return dfs(dfs, 0, n - 1);
    }
};
