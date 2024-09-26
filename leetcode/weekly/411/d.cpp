class Solution {
public:
    vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> pre(n);
        vector<long long> sum(n + 1);
        int cnt0 = 0, cnt1 = 0;
        for (int i = 0, l = 0; i < n; i++) {
            (s[i] == '0' ? cnt0 : cnt1) += 1;
            while (cnt0 > k && cnt1 > k) {
                (s[l] == '0' ? cnt0 : cnt1) -= 1;
                l += 1;
            }
            pre[i] = l;
            sum[i + 1] = sum[i] + i - l + 1;
        }
        
        vector<long long> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            int l = queries[i][0], r = queries[i][1];
            int p = lower_bound(pre.begin() + l, pre.begin() + r + 1, l) - pre.begin();
            ans[i] = sum[r + 1] - sum[p] + 1ll * (p - l + 1) * (p - l) / 2;
        }
        return ans;
    }
};
