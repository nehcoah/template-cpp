// 2826
// https://leetcode.cn/problems/sorting-three-groups/description/
// dp

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int f[n][3];
        memset(f, 0x3f, sizeof(f));
        f[0][0] = nums[0] == 1 ? 0 : 1;
        f[0][1] = nums[0] == 2 ? 0 : 1;
        f[0][2] = nums[0] == 3 ? 0 : 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] == 1) {
                f[i][0] = f[i - 1][0];
                f[i][1] = min(f[i - 1][0], f[i - 1][1]) + 1;
                f[i][2] = min(f[i - 1][0], min(f[i - 1][1], f[i - 1][2])) + 1;
            } else if (nums[i] == 2) {
                f[i][0] = f[i - 1][0] + 1;
                f[i][1] = min(f[i - 1][0], f[i - 1][1]);
                f[i][2] = min(f[i - 1][0], min(f[i - 1][1], f[i - 1][2])) + 1;
            } else {
                f[i][0] = f[i - 1][0] + 1;
                f[i][1] = min(f[i - 1][0], f[i - 1][1]) + 1;
                f[i][2] = min(f[i - 1][0], min(f[i - 1][1], f[i - 1][2]));
            }
        }
        return min(f[n - 1][0], min(f[n - 1][1], f[n - 1][2]));
    }
};
