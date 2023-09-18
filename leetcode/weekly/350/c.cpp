// https://leetcode.cn/problems/special-permutations/

class Solution {
    const int mod = 1e9 + 7;
public:
    int specialPerm(vector<int>& nums) {
        int n = nums.size(), memo[n][1 << n];
        memset(memo, -1, sizeof(memo));
        function<int(int, int)> dfs = [&](int i, int mask){
            if (mask == (1 << n) - 1) return 1;
            if (memo[i][mask] != -1) return memo[i][mask];
            int ans = 0;
            for (int j = 0; j < n; j++){
                if ((mask & (1 << j)) == 0){
                    int x = nums[j];
                    if (x % nums[i] == 0 || nums[i] % x == 0){
                        ans = (ans + dfs(j, mask | (1 << j))) % mod;
                    }
                }
            }
            return memo[i][mask] = ans;
        };
        int ans = 0;
        for (int i = 0; i < n; i++) ans = (ans + dfs(i, 1 << i)) % mod;
        return ans;
    }
};
