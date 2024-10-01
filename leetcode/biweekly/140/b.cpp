class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        sort(maximumHeight.begin(), maximumHeight.end(), greater());
        int pre = 1e9 + 1;
        long long ans = 0;
        for (int x : maximumHeight) {
            if (pre > x) {
                ans += x;
                pre = x;
            } else {
                if (pre - 1 == 0) return -1;
                ans += pre - 1;
                pre -= 1;
            }
        }
        return ans;
    }
};
