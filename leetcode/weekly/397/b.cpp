class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int ans = -1e9, n = energy.size();
        for (int i = 0; i < k; i++) {
            int cur = 0;
            for (int j = i; j < n; j += k) {
                if (cur < 0) cur = 0;
                cur += energy[j];
            }
            ans = max(ans, cur);
        }
        return ans;
    }
};
