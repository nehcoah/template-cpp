class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = __builtin_popcount(nums[i]);
        }
        for (int i = 0; i < n; ) {
            int j = i, x = a[i];
            while (j < n && a[j] == x) j++;
            sort(nums.begin() + i, nums.begin() + j);
            i = j;
        }
        return is_sorted(nums.begin(), nums.end());
    }
};

// class Solution {
// public:
//     bool canSortArray(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> a(n), idx(n);
//         for (int i = 0; i < n; i++) {
//             a[i] = __builtin_popcount(nums[i]);
//         }
//         iota(idx.begin(), idx.end(), 0);
//         ranges::sort(idx, [&](int i, int j) {return nums[i] < nums[j];});
//         for (int i = 0; i < n; i++) {
//             int t = -1;
//             for (int x = min(i, idx[i]); x <= max(i, idx[i]); x++) {
//                 if (t == -1) t = a[x];
//                 else if (t != a[x]) return false;
//             }
//         }
//         return true;
//     }
// };
