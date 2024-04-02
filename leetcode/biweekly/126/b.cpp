class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        long long sum = accumulate(nums.begin(), nums.end(), 0ll);
        vector<long long> ans;
        vector<int> vis(n), idx(n);
        iota(idx.begin(), idx.end(), 0);
        stable_sort(idx.begin(), idx.end(), [&](int a, int b) {
            return nums[a] < nums[b];
        });
        int i = 0;
        for (auto &q : queries) {
            int id = q[0], k = q[1];
            if (!vis[q[0]]) vis[q[0]] = 1, sum -= nums[q[0]];
            for (int j = 0; j < k && i < n; i++) {
                if (!vis[idx[i]]) vis[idx[i]] = 1, sum -= nums[idx[i]], j += 1;
            }
            ans.push_back(sum);
        }
        return ans;
    }
};
