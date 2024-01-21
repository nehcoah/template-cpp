class Solution {
public:
    vector<long long> countOfPairs(int n, int x, int y) {
        if (x > y) swap(x, y);
        x--, y--;
        
        // x + 1 >= y 加不加这条边不影响结果
        if (x + 1 >= y) {
            vector<long long> cur(n);
            for (int i = 0; i < n - 1; i++) {
                cur[i] = (n - i - 1) * 2;
            }
            return cur;
        }
        
        // 差分
        // 从i走到j (i < j) 是否需要走 x -> y 的边？
        // 是：(i < (x + y) / 2)
        // 分界点处长度为d
        // 走到任意j位置(i < j) 分三种情况：
        // 1. i -> j
        // 2. i -> x -> y -> j (y -> j 往回走)
        // 3. i -> x -> y -> j (y -> j 往前走)
        // 否：else
        // 直接从 i -> j
        vector<long long> ans(n + 1);
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
