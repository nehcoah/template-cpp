// https://leetcode.cn/problems/count-the-number-of-complete-components/description/

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n), size(n, 1), cnt(n, 0);
        iota(parent.begin(), parent.end(), 0);
        function<int(int)> find = [&](int x) {
            return parent[x] == x ? x : parent[x] = find(parent[x]);
        };
        for (auto &e : edges) {
            int x = find(e[0]), y = find(e[1]);
            if (x != y) {
                parent[x] = y;
                size[y] += size[x];
                cnt[y] += cnt[x] + 1;
            } else cnt[x] += 1;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (find(i) == i) if (size[i] * (size[i] - 1) / 2 == cnt[i]) ans++;
        }
        return ans;
    }
};
