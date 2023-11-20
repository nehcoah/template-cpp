#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int mod = 1e9 + 7;
    int n, m, idx = 0;
    cin >> n >> m;
    string s, t;
    getline(cin, s);
    getline(cin, s);

    vector<int> l, r, type, k;
    stack<int> stk;
    stringstream io(s);
    while (getline(io, t, ' ')) {
        if (t == "*" || t == "+" || t == "-") {
            int rs = stk.top(); stk.pop();
            int ls = stk.top(); stk.pop();
            l.push_back(ls);
            r.push_back(rs);
            type.push_back(-1);
            k.push_back(t[0]);
            stk.push(idx++);
        } else if (t[0] == 'x') {
            int c = stoi(t.substr(1));
            l.push_back(-1);
            r.push_back(-1);
            type.push_back(-2);
            k.push_back(c);
            stk.push(idx++);
        } else {
            int c = stoi(t);
            l.push_back(-1);
            r.push_back(-1);
            type.push_back(-3);
            k.push_back(c);
            stk.push(idx++);
        }
    }
    int root = stk.top();

    int p;
    vector<int> d(n);
    function<pair<ll, ll>(int, int)> dfs = [&](int x, int p) -> pair<ll, ll> {
        if (type[x] == -1) {
            auto ls = dfs(l[x], p);
            auto rs = dfs(r[x], p);
            ll a, b;
            if (k[x] == '+') {
                a = ((ls.first + rs.first) % mod + mod) % mod;
                b = ((ls.second + rs.second) % mod + mod) % mod;
            } else if (k[x] == '-') {
                a = ((ls.first - rs.first) % mod + mod) % mod;
                b = ((ls.second - rs.second) % mod + mod) % mod;
            } else {
                a = ((ls.first * rs.first) % mod + mod) % mod;
                b = ((ls.first * rs.second % mod + ls.second * rs.first % mod) % mod + mod) % mod;
            }
            return {a, b};
        } else if (type[x] == -2) {
            return {d[k[x] - 1], p == k[x]};
        } else {
            return {k[x], 0};
        }
    };
    for (int i = 0; i < m; i++) {
        cin >> p;
        for (int j = 0; j < n; j++) cin >> d[j];
        cout << dfs(root, p).second << "\n";
    }

    return 0;
}


