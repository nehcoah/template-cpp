vector<int> is_prime, minp, prime;
void sieve(int n) {
    is_prime.assign(n + 1, true);
    minp.assign(n + 1, 0);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            prime.push_back(i);
            minp[i] = i;
        }
        for (auto x : prime) {
            if (i * x > n) break;
            is_prime[i * x] = false;
            minp[i * x] = x;
            if (x == minp[i]) break;
        }
    }
}

vector<int> p;
map<int, int> mp;
vector<vector<pair<int, int>>> adj;

auto init = []() {
    sieve(1e4 + 1);
    int id = 0;
    for (int x = 1; x < 10000; x++) {
        if (!is_prime[x]) {
            p.push_back(x);
            mp[x] = id++;
        }
    }
    int n = p.size();
    adj.resize(n);
    for (auto [k, u] : mp) {
        // cout << k << " " << u << endl;
        auto x = to_string(k);
        for (int i = 0; i < x.size(); i++) {
            if (x[i] != '9') {
                auto y = x;
                y[i] += 1;
                if (!is_prime[stoi(y)]) {
                    int v = mp[stoi(y)];
                    adj[u].emplace_back(v, stoi(y));
                    // cout << y << " " << v << " " << stoi(x) << endl;
                }
            }
            if (x[i] != '0') {
                auto y = x;
                y[i] -= 1;
                if (!is_prime[stoi(y)] && (y[i] != '0' || i != 0)) {
                    int v = mp[stoi(y)];
                    adj[u].emplace_back(v, stoi(y));
                    // cout << y << " " << v << " " << stoi(x) << endl;
                }
            }
        }
    }
    return 0;
}();

class Solution {
public:
    int minOperations(int n, int m) {
        if (is_prime[n] || is_prime[m]) return -1;
        int s = mp[n], t = mp[m];
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> dis(p.size(), -1);
        pq.emplace(n, s);
        while (!pq.empty()) {
            auto [d, x] = pq.top(); pq.pop();
            if (dis[x] != -1) continue;
            if (x == t) return d;
            dis[x] = d;
            for (auto [y, w] : adj[x]) {
                pq.emplace(d + w, y);
            }
        }
        return -1;
    }
};
