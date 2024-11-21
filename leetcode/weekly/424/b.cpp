class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> d(n + 1);
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            d[l] += 1, d[r + 1] -= 1;
        }

        for (int i = 0; i < n; i++) {
            if (i > 0) d[i] += d[i - 1];
            if (nums[i] > d[i]) return false;
        }
        return true;
    }
};
