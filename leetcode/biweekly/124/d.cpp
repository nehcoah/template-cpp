class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        int n = nums.size(), mx = *max_element(nums.begin(), nums.end());
        vector<int> cnt(mx + 5), f(mx + 5);
        for (int x : nums) {
            cnt[x]++;
        }
        vector<int> l, r, g;
        for (int i = 1, pre = -1, ok = 0; i < mx + 5; i++) {
            if (cnt[i] != 0) {
                if (pre == -1) pre = i;
                if (cnt[i] > 1) ok = 1;
            } else {
                if (pre == -1) continue;
                l.push_back(pre);
                r.push_back(i - 1);
                g.push_back(ok);
                pre = -1, ok = 0;
            }
        }
        int ans = 0;
        for (int i = l.size() - 1; i >= 0; i--) {
            int cur = r[i] - l[i] + 1 + g[i];
            f[l[i]] = cur;
            if (i < l.size() - 1) {
                if (r[i] + 2 == l[i + 1]) {
                    (g[i] ? f[l[i]] : f[l[i] + 1]) = cur + f[l[i + 1]];
                }
            }
        }
        return *max_element(f.begin(), f.end());
    }
};
