// https://leetcode.cn/problems/make-costs-of-paths-equal-in-a-binary-tree/description/

class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        int ans = 0;
        function<int(int)> dfs = [&](int cur){
            int idx = cur + 1;
            if (idx * 2 > n) return cost[cur];
            int left = dfs(2 * idx - 1);
            int right = dfs(2 * idx);
            ans += abs(left - right);
            return max(left, right) + cost[cur];
        };
        dfs(0);
        return ans;
    }
};
