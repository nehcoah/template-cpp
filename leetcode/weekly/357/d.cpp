// 2813
// https://leetcode.cn/problems/maximum-elegance-of-a-k-length-subsequence/
// sorting, greedy

class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        sort(items.begin(), items.end(), greater<>());
        long long ans = 0, tp = 0;
        unordered_set<int> s;
        stack<int> stk;
        for (int i = 0; i < k; i++) {
            int p = items[i][0], c = items[i][1];
            if (s.count(c)) stk.push(p);
            else s.insert(c);
            tp += p;
        }
        ans = tp + s.size() * s.size();
        cout << ans << endl;
        int n = items.size();
        for (int i = k; i < n && !stk.empty(); i++) {
            int p = items[i][0], c = items[i][1];
            if (s.count(c)) continue;
            tp -= stk.top(); stk.pop();
            s.insert(c);
            tp += p;
            ans = max(ans, tp + (long long)s.size() * (long long)s.size());
        }
        return ans;
    }
};
