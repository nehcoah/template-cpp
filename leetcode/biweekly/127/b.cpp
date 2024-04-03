class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int n = possible.size();
        vector<int> sum(n + 1);
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + (possible[i] == 1 ? 1 : -1);
        }
        for (int i = 1; i < n; i++) {
            int l = sum[i], r = sum.back() - sum[i];
            if (l > r) return i;
        }
        return -1;
    }
};
