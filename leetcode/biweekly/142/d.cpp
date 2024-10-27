class Solution {
public:
    int possibleStringCount(string word, int k) {
        const int mod = 1e9 + 7;
        vector<int> nums;
        for (int i = 0; i < word.size(); ) {
            int j = i;
            while (j < word.size() && word[j] == word[i]) j += 1;
            nums.push_back(j - i);
            i = j;
        }

        long long ans = 1;
        for (int x : nums) {
            ans = ans * x % mod;
        }
        if (nums.size() >= k) return ans;

        vector<vector<long long>> f(nums.size() + 1, vector<long long>(k));
        vector<vector<long long>> sum(nums.size() + 1, vector<long long>(k));
        f[0][0] = 1;
        for (int i = 0; i < k; i++) sum[0][i] = 1;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < k - 1; j++) {
                long long v = 0;
                int t = j - nums[i];
                if (t >= 0) v = sum[i][t];
                f[i + 1][j + 1] = (sum[i][j] - v + mod) % mod;
            }
            for (int j = 0; j < k - 1; j++) sum[i + 1][j + 1] = (sum[i + 1][j] + f[i + 1][j + 1]) % mod;
        }
        return ((ans - sum[nums.size()][k - 1]) % mod + mod) % mod;
    }
};
