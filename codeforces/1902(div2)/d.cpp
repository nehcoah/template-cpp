#include "bits/stdc++.h"

using namespace std;
using ll = long long;

struct Point {
    int x = 0, y = 0;
};

Point operator+(const Point &a, const Point &b) {
    return {a.x + b.x, a.y + b.y};
}

Point operator-(const Point &a, const Point &b) {
    return {a.x - b.x, a.y - b.y};
}

bool operator<(const Point &a, const Point &b) {
    return a.x == b.x ? a.y < b.y : a.x < b.x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    vector<Point> p(n + 1);
    for (int i = 0; i < n; i++) {
        p[i + 1] = p[i];
        if (s[i] == 'L') p[i + 1].x -= 1;
        else if (s[i] == 'R') p[i + 1].x += 1;
        else if (s[i] == 'U') p[i + 1].y += 1;
        else p[i + 1].y -= 1;
    }

    map<Point, vector<int>> mp;
    for (int i = 0; i <= n; i++) {
        mp[p[i]].push_back(i);
    }

    auto check = [&](Point cur, int l, int r) {
        if (mp.count(cur) == 0) return false;
        auto it = lower_bound(mp[cur].begin(), mp[cur].end(), l);
        return it != mp[cur].end() && *it <= r;
    };

    for (int i = 0; i < q; i++) {
        int x, y, l, r;
        cin >> x >> y >> l >> r;
        l--;
        bool ok = check({x, y}, 0, l);
        ok |= check({x, y}, r, n);
        ok |= check(p[l] + p[r] - Point{x, y}, l, r);
        cout << (ok ? "YES" : "NO") << endl;
    }

    return 0;
}

