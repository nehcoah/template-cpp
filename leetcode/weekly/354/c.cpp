// https://leetcode.cn/problems/minimum-index-of-a-valid-split/

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int x : nums) mp[x]++;
        int x = 0, cnt = 0;
        for (auto [k, v] : mp) if (cnt < v) x = k, cnt = v;
        int n = nums.size(), cur = 0;
        // cout << x << endl;
        for (int i = 0; i < n; i++) {
            if (nums[i] == x) cur++, cnt--;
            if (cur * 2 > (i + 1) && cnt * 2 > (n - i - 1)) return i;
        }
        return -1;
    }
};
