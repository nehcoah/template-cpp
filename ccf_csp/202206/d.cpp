#include "bits/stdc++.h"

using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> m;
    map<pair<int, int>, pair<double, int>> info;
    map<int, set<int>> px, py;
    unordered_map<int, array<int, 5>> mirror;
    vector<int> dirx{1, 0, -1, 0}, diry{0, 1, 0, -1};

    for (int i = 0; i < m; i++) {
        int o;
        cin >> o;
        if (o == 1) {
            int x1, y1, x2, y2, d;
            double a;
            cin >> x1 >> y1 >> x2 >> y2 >> a;
            if (x1 > x2) swap(x1, x2), swap(y1, y2);
            d = 1ll * (x2 - x1) * (y2 - y1) > 0 ? 1 : -1;
            for (int x = x1 + 1, y = y1 + d, c = 0; c < x2 - x1 - 1; x++, y += d, c++) {
                info[{x, y}] = {a, d};
                px[x].insert(y);
                py[y].insert(x);
            }
            mirror[i] = {x1, y1, x2, y2, d};
        } else if (o == 2) {
            int k;
            cin >> k;
            auto &cur = mirror[k - 1];
            int x1 = cur[0], y1 = cur[1], x2 = cur[2], y2 = cur[3], d = cur[4];
            for (int x = x1 + 1, y = y1 + d, c = 0; c < x2 - x1 - 1; x++, y += d, c++) {
                info.erase({x, y});
                px[x].erase(y);
                py[y].erase(x);
            }
        } else {
            int x, y, d, t;
            double I;
            cin >> x >> y >> d >> I >> t;
            int dx = dirx[d], dy = diry[d];
            while (I >= 1) {
                if (dx == 0) {
                    if (dy == 1) {
                        auto it = px[x].upper_bound(y);
                        if (it == px[x].end() || *it - y > t) {
                            cout << x << " " << y + t << " " << int(I) << "\n";
                            break;
                        }
                        auto cur = info[{x, *it}];
                        t -= *it - y;
                        I *= cur.first;
                        y = *it;
                        swap(dx, dy);
                        dx *= cur.second, dy *= cur.second;
                    } else {
                        auto it = px[x].lower_bound(y);
                        if (it == px[x].begin() || y - *prev(it) > t) {
                            cout << x << " " << y - t << " " << int(I) << "\n";
                            break;
                        }
                        it = prev(it);
                        auto cur = info[{x, *it}];
                        t -= y - *it;
                        I *= cur.first;
                        y = *it;
                        swap(dx, dy);
                        dx *= cur.second, dy *= cur.second;
                    }
                } else {
                    if (dx == 1) {
                        auto it = py[y].upper_bound(x);
                        if (it == py[y].end() || *it - x > t) {
                            cout << x + t << " " << y << " " << int(I) << "\n";
                            break;
                        }
                        auto cur = info[{*it, y}];
                        t -= *it - x;
                        I *= cur.first;
                        x = *it;
                        swap(dx, dy);
                        dx *= cur.second, dy *= cur.second;
                    } else {
                        auto it = py[y].lower_bound(x);
                        if (it == py[y].begin() || x - *prev(it) > t) {
                            cout << x - t << " " << y << " " << int(I) << "\n";
                            break;
                        }
                        it = prev(it);
                        auto cur = info[{*it, y}];
                        t -= x - *it;
                        I *= cur.first;
                        x = *it;
                        swap(dx, dy);
                        dx *= cur.second, dy *= cur.second;
                    }
                }
            }
            if (I < 1) cout << "0 0 0\n";
        }
    }

    return 0;
}


