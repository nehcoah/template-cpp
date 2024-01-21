class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        if (x > y) swap(x, y);
        x--, y--;
        if (x + 1 >= y) {
            vector<int> cur(n);
            for (int i = 0; i < n - 1; i++) {
                cur[i] = (n - i - 1) * 2;
            }
            return cur;
        }
        vector<int> ans(n + 1);
        for (int i = 0; i < n; i++) {
            if (i <= x) {
                int d = x - i + (y - x + 1) / 2;
                ans[0]++, ans[n - i - 1 - (y - x) + 1]--;
                ans[x - i]++, ans[d]--;
                ans[x - i + 1]++, ans[(y - x) % 2 ? d - 1 : d]--;
            } else if (i < (x + y) / 2) {
                int d = (y - x + 1) / 2;
                ans[0]++, ans[d]--;
                ans[i - x + 1]++, ans[(y - x) % 2 ? d - 1 : d]--;
                ans[i - x]++, ans[i - x + n - y]--;
            } else {
                ans[0]++, ans[n - i - 1]--;
            }
        }
        for (int i = 0; i < n; i++) {
            ans[i + 1] += ans[i];
        }
        for (int i = 0; i < n; i++) {
            ans[i] *= 2;
        }
        ans.pop_back();
        return ans;
    }
};
