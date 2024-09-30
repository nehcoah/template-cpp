class Solution {
public:
    int maxPossibleScore(vector<int>& start, int d) {
        int n = start.size();
        sort(start.begin(), start.end());
        
        auto check = [&](int x) {
            long long pre = start[0];
            for (int i = 1; i < n; i++) {
                long long cur = pre + x;
                if (cur > start[i] + d) return false;
                pre = max(cur, (long long) start[i]);
            }
            return true;
        };
        
        long long l = 0, r = 2e9 + 1;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(mid)) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};
