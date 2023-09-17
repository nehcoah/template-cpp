// https://leetcode.cn/problems/maximum-number-of-alloys/

class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        int ans = 0;
        for (int i = 0; i < k; i++) {
            auto check = [&](int x) {
                long long cur = budget;
                for (int j = 0; j < n; j++) {
                    cur -= max(0LL, x * (long long)composition[i][j] - stock[j]) * cost[j];
                    if (cur < 0) return false;
                }
                return cur >= 0;
            };
            int l = 0, r = 1e9;
            while (l < r) {
                int mid = l + r + 1 >> 1;
                if (check(mid)) l = mid;
                else r = mid - 1;
            }
            ans = max(ans, l);
        }
        return ans;
    }
};
