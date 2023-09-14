// 2815
// https://leetcode.cn/problems/max-pair-sum-in-an-array/
// 

// brute force
class Solution {
public:
    int maxSum(vector<int>& nums) {
        int ans = -1, n = nums.size();
        for (int i = 0; i < n; i++) {
            string s1 = to_string(nums[i]);
            int mx = -1;
            for (char c : s1) mx = max(mx, c - '0');
            for (int j = i + 1; j < n; j++) {
                string s2 = to_string(nums[j]);
                int cur = -1;
                for (char c : s2) cur = max(cur, c - '0');
                if (mx == cur) ans = max(ans, nums[i] + nums[j]);
            }
        }
        return ans;
    }
};

class Solution {
public:
    int maxSum(vector<int> &nums) {
        int ans = -1;
        vector<int> max_val(10, INT_MIN);
        for (int v: nums) {
            int max_d = 0;
            for (int x = v; x; x /= 10)
                max_d = max(max_d, x % 10);
            ans = max(ans, v + max_val[max_d]);
            max_val[max_d] = max(max_val[max_d], v);
        }
        return ans;
    }
};

// 作者：灵茶山艾府
// 链接：https://leetcode.cn/problems/max-pair-sum-in-an-array/solutions/2385996/yi-ci-bian-li-by-endlesscheng-6zt9/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
