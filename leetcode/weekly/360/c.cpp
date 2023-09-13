// 2835
// https://leetcode.cn/problems/minimum-operations-to-form-subsequence-with-target-sum/description/
// bitmask

class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        if (sum < target) return -1;
        vector<int> a(50), b;
        for (int i = 0; i < 50; i++) {
            b.push_back(target & 1);
            target >>= 1;
        }
        for (int x : nums) {
            for (int i = 0; i < 50; i++) {
                a[i] += x & 1;
                x >>= 1;
            }
        }
        int ans = 0, cur = 0;
        for (int i = 0; i < 50; i++) {
            if (b[i] == 1) {
                if (a[i] > 0) a[i]--;
                else {
                    int j = i + 1;
                    while (a[j] == 0) a[j] = 1, j++;
                    a[j] -= 1;
                    ans += j - i;
                }
            }
            if (i < 49) a[i + 1] += a[i] / 2;
        }
        return ans;
    }
};
