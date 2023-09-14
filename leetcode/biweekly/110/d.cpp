// 2809
// https://leetcode.cn/problems/minimum-time-to-make-array-sum-at-most-x/description/
// sorting, dp

class Solution {
public:
    int minimumTime(vector<int> &nums1, vector<int> &nums2, int x) {
        int n = nums1.size();
        // 对下标数组排序，避免破坏 nums1 和 nums2 的对应关系
        vector<int> ids(n);
        iota(ids.begin(), ids.end(), 0);
        sort(ids.begin(), ids.end(), [&](const int i, const int j) {
            return nums2[i] < nums2[j];
        });

        vector<int> f(n + 1);
        for (int i: ids)
            for (int j = n; j; j--)
                f[j] = max(f[j], f[j - 1] + nums1[i] + nums2[i] * j);

        int s1 = accumulate(nums1.begin(), nums1.end(), 0);
        int s2 = accumulate(nums2.begin(), nums2.end(), 0);
        for (int t = 0; t <= n; t++)
            if (s1 + s2 * t - f[t] <= x)
                return t;
        return -1;
    }
};

// 作者：灵茶山艾府
// 链接：https://leetcode.cn/problems/minimum-time-to-make-array-sum-at-most-x/solutions/2374920/jiao-ni-yi-bu-bu-si-kao-ben-ti-by-endles-2eho/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
