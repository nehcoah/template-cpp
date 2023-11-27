class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> f(n);
        for (int i = 0; i < n; i++) f[i] = {nums[i], i};
        ranges::sort(f);
        vector<int> ans(n);
        for (int i = 0; i < n; ) {
            int j = i + 1;
            vector<int> idx{f[j - 1].second};
            while (j < n && f[j].first <= f[j - 1].first + limit) {
                idx.push_back(f[j].second);
                j++;
            }
            ranges::sort(idx);
            for (int k = i; k < j; k++) {
                ans[idx[k - i]] = f[k].first;
            }
            i = j;
        }
        return ans;
    }
};
