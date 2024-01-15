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

mt19937_64 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

// struct hash61 {
//     static const uint64_t md = (1LL << 61) - 1;
//     static uint64_t step;
//     static vector<uint64_t> pw;

//     uint64_t addmod(uint64_t a, uint64_t b) const {
//         a += b;
//         if (a >= md) a -= md;
//         return a;
//     }

//     uint64_t submod(uint64_t a, uint64_t b) const {
//         a += md - b;
//         if (a >= md) a -= md;
//         return a;
//     }

//     uint64_t mulmod(uint64_t a, uint64_t b) const {
//         uint64_t l1 = (uint32_t) a, h1 = a >> 32, l2 = (uint32_t) b, h2 = b >> 32;
//         uint64_t l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
//         uint64_t ret = (l & md) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
//         ret = (ret & md) + (ret >> 61);
//         ret = (ret & md) + (ret >> 61);
//         return ret - 1;
//     }

//     void ensure_pw(int sz) {
//         int cur = (int) pw.size();
//         if (cur < sz) {
//             pw.resize(sz);
//             for (int i = cur; i < sz; i++) {
//                 pw[i] = mulmod(pw[i - 1], step);
//             }
//         }
//     }

//     vector<uint64_t> pref;
//     int n;

//     template<typename T>
//     hash61(const T& s) {
//         n = (int) s.size();
//         ensure_pw(n + 1);
//         pref.resize(n + 1);
//         pref[0] = 1;
//         for (int i = 0; i < n; i++) {
//             pref[i + 1] = addmod(mulmod(pref[i], step), s[i]);
//         }
//     }

//     uint64_t get_hash(const int from, const int to) {
//         assert(0 <= from && from <= to && to <= n - 1);
//         return submod(pref[to + 1], mulmod(pref[from], pw[to - from + 1]));
//     }
    
//     uint64_t all() {
//         return get_hash(0, n - 1);
//     }
// };

// uint64_t hash61::step = (md >> 2) + rng() % (md >> 1);
// vector<uint64_t> hash61::pw = vector<uint64_t>(1, 1);

// class Solution {
// public:
//     vector<int> beautifulIndices(string s, string a, string b, int k) {
//         if (a.size() > s.size() || b.size() > s.size()) return {};
        
//         auto A = hash61(a), B = hash61(b), S = hash61(s);
//         vector<int> id;
//         for (int i = 0; i <= s.size() - b.size(); i++) {
//             if (S.get_hash(i, i + b.size() - 1) == B.all()) id.push_back(i);
//         }

//         auto check = [&](int x) {
//             auto it = lower_bound(id.begin(), id.end(), x);
//             if (it != id.end()) {
//                 if (x + k >= *it) return true;
//             }
//             if (it != id.begin()) {
//                 if (x - k <= *prev(it)) return true;
//             }
//             return false;
//         };
        
//         vector<int> ans;
//         for (int i = 0; i <= s.size() - a.size(); i++) {
//             if (S.get_hash(i, i + a.size() - 1) == A.all() && check(i)) {
//                 ans.push_back(i);
//             }
//         }
//         return ans;
//     }
// };
