class Solution {
public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        int n = damage.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            int ti = (health[i] + power - 1) / power, tj = (health[j] + power - 1) / power;
            return 1ll * ti * damage[j] < 1ll * tj * damage[i];
        });
        
        long long t = 0, ans = 0;
        for (int x : idx) {
            long long cur = (health[x] + power - 1) / power;
            ans += (cur + t) * damage[x];
            t += cur;
        }
        return ans;
    }
};
