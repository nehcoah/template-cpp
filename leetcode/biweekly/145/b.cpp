class Solution {
public:
    int findMinimumTime(vector<int>& strength, int K) {
        int n = strength.size(), ans = 1e9;
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        do {
            int x = 1, cnt = 0;
            for (int i : order) {
                int cur = strength[i];
                cnt += (cur + x - 1) / x;
                x += K;
            }
            ans = min(ans, cnt);
        } while (next_permutation(order.begin(), order.end()));
        return ans;
    }
};
