#include "bits/stdc++.h"

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using ll = long long;

void read(map<string, int> &cur) {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); ) {
        int j = i;
        while (j < s.size() && isalpha(s[j])) j += 1;
        auto t = s.substr(i, j - i);
        i = j;
        while (j < s.size() && isdigit(s[j])) j += 1;
        auto c = stoi(s.substr(i, j - i));
        i = j;
        cur[t] += c;
    }
}

void mul(vector<int> &cur, int x) {
    for (int &y : cur) {
        y *= x;
    }
}

void add(vector<int> &a, vector<int> &b) {
    for (int i = 0; i < a.size(); i++) {
        a[i] += b[i];
    }
}

void solve() {
    int n;
    cin >> n;
    vector<map<string, int>> info(n);
    for (int i = 0; i < n; i++) {
        read(info[i]);
    }
    int p = 0;
    map<string, int> mp;
    for (int i = 0; i < n; i++) {
        for (auto &[k, v] : info[i]) {
            if (mp.count(k) == 0) mp[k] = p++;
        }
    }
    vector<vector<int>> ans(p, vector<int>(n));
    for (auto &[k, v] : mp) {
        for (int i = 0; i < n; i++) {
            if (info[i].count(k)) {
                ans[v][i] += info[i][k];
            }
        }
    }
    vector<int> vis(p);
    for (int i = 0; i < n; i++) {
        vector<int> idx;
        int x = 1;
        for (int j = 0; j < p; j++) {
            if (ans[j][i] != 0 && !vis[j]) {
                idx.push_back(j);
            }
        }
        if (idx.empty()) continue;
        if (idx.size() == 1) {
            vis[idx[0]] = 1;
            continue;
        }
        for (int t : idx) {
            x = lcm(abs(ans[t][i]), x);
        }
        mul(ans[idx[0]], -x / ans[idx[0]][i]);
        for (int j = 1; j < idx.size(); j++) {
            mul(ans[idx[j]], x / ans[idx[j]][i]);
            add(ans[idx[j]], ans[idx[0]]);
        }
        vis[idx[0]] = 1;
    }

    vector<int> all_zero(n);
    int cnt = 0;
    for (int i = 0; i < p; i++) {
        cnt += equal(ans[i].begin(), ans[i].end(), all_zero.begin());
    }
    cout << (p - cnt < n ? "Y" : "N") << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while (n--) {
        solve();
    }

    return 0;
}

