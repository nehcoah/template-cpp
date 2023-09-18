// https://leetcode.cn/problems/semi-ordered-permutation/

class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int ans = 0, n = nums.size(), mx = -1, mn = -1;
        for (int i = 0; i < n; i++){
            if (nums[i] == 1) mn = i;
            if (nums[i] == n) mx = i;
        }
        return mn + (n - mx - 1) - (mn > mx);
    }
};
