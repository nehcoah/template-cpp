// https://leetcode.cn/problems/count-zero-request-servers/

class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](auto& a, auto& b){return a[1] < b[1];});
        int qn = queries.size(), m = logs.size(), l = 0, r = 0;
        int idx[qn];
        iota(idx, idx + qn, 0);
        sort(idx, idx + qn, [&](int a, int b){return queries[a] < queries[b];});
        vector<int> ans(qn);
        unordered_map<int, int> mp;
        for (int i : idx){
            int q = queries[i];
            while (r < m && logs[r][1] <= q) mp[logs[r][0]]++, r++;
            while (l < m && logs[l][1] < q - x) {
                if (--mp[logs[l][0]] == 0) mp.erase(logs[l][0]);
                l++;
            }
            ans[i] = n - mp.size();
        }
        return ans;
    }
};
