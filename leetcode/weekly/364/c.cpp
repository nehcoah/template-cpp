// https://leetcode.cn/problems/beautiful-towers-ii/

class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        vector<long long> pre(n + 1), suf(n + 1);
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && maxHeights[stk.top()] >= maxHeights[i]) stk.pop();
            if (stk.empty()) pre[i + 1] = (long long)maxHeights[i] * (i + 1);
            else pre[i + 1] = pre[stk.top() + 1] + (long long)(i - stk.top()) * maxHeights[i];
            stk.push(i);
        }
        while (!stk.empty()) stk.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && maxHeights[stk.top()] >= maxHeights[i]) stk.pop();
            if (stk.empty()) suf[i] = (long long)maxHeights[i] * (n - i);
            else suf[i] = suf[stk.top()] + (long long)(stk.top() - i) * maxHeights[i];
            stk.push(i);
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, pre[i + 1] + suf[i] - maxHeights[i]);
        }
        return ans;
    }
};
