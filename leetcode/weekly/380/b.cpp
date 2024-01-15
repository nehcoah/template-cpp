mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll = long long;

class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        if (a.size() > s.size() || b.size() > s.size()) return {};
        
        const ll mod = (1ll << 61) - 1, base = rng() % (mod - 200) + 150;
        vector<ll> pw(max(a.size(), b.size()) + 1);
        pw[0] = 1;
        for (int i = 0; i < pw.size() - 1; i++) {
            pw[i + 1] = (__int128) pw[i] * base % mod;
        }
        
        auto get = [&](string &t) {
            ll H = 0;
            for (char c : t) {
                H = ((__int128) H * base + c) % mod;
            }
            return H;
        };
        
        auto B = get(b);
        ll cur = 0;
        for (int i = 0; i < b.size(); i++) {
            cur = ((__int128) cur * base + s[i]) % mod;
        }
        vector<int> id;
        if (cur == B) id.push_back(0);
        for (int i = b.size(); i < s.size(); i++) {
            cur = ((cur - (__int128) s[i - b.size()] * pw[b.size() - 1]) % mod + mod) % mod;
            cur = ((__int128) cur * base + s[i]) % mod;
            if (cur == B) id.push_back(i - b.size() + 1);
            
        }
        
        auto check = [&](int x) {
            auto it = lower_bound(id.begin(), id.end(), x);
            if (it != id.end()) {
                if (x + k >= *it) return true;
            }
            if (it != id.begin()) {
                if (x - k <= *prev(it)) return true;
            }
            return false;
        };
        
        auto A = get(a);
        cur = 0;
        for (int i = 0; i < a.size(); i++) {
            cur = ((__int128) cur * base + s[i]) % mod;
        }
        vector<int> ans;
        if (cur == A && check(0)) ans.push_back(0);
        for (int i = a.size(); i < s.size(); i++) {
            cur = ((cur - (__int128) s[i - a.size()] * pw[a.size() - 1]) % mod + mod) % mod;
            cur = ((__int128) cur * base + s[i]) % mod;
            if (cur == A && check(i - a.size() + 1)) ans.push_back(i - a.size() + 1);
        }
        return ans;
    }
};
