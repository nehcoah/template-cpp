class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        using ll = long long;
        
        auto get = [&](ll x, ll y) {
            ll l = 0, r = mountainHeight;
            while (l < r) {
                ll mid = (l + r + 1) >> 1;
                if (x * (1 + mid) * mid / 2 <= y) l = mid;
                else r = mid - 1;
            }
            return l;
        };

        auto check = [&](ll t) {
            ll cnt = 0;
            for (int x : workerTimes) {
                cnt += get(x, t);
                if (cnt >= mountainHeight) return true;
            }
            return false;
        };

        ll l = 0, r = 1e18;
        while (l < r) {
            ll mid = (l + r) >> 1;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};
