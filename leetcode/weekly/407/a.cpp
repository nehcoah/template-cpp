class Solution {
public:
    int minChanges(int n, int k) {
        int ans = 0;
        for (int i = 30; i >= 0; i--) {
            if (n >> i & 1) {
                if ((k >> i & 1) == 0) ans += 1;
            } else {
                if (k >> i & 1) return -1;
            }
        }
        return ans;
    }
};
