#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    if (m <= 10000 && k <= 2000) {
        vector<int> c(m + 1), id(m + 1), op(m + 1);
        for (int i = 0; i < k; i++) {
            int o; cin >> o;
            if (o == 0) {
                int no, l, r, x;
                cin >> no >> l >> r >> x;
                for (int z = l; z <= r; z++) {
                    if (op[z] && id[z] != no) {
                        cout << (z == l ? -1 : z - 1) << "\n";
                        break;
                    }
                    op[z] = true;
                    id[z] = no;
                    c[z] = x;
                    if (z == r) cout << r << "\n";
                }
            } else if (o == 1) {
                int no, l, r;
                cin >> no >> l >> r;
                bool good = true;
                for (int z = l; z <= r; z++) {
                    if (!op[z] || id[z] != no) {
                        good = false;
                        break;
                    }
                }
                if (!good) {
                    cout << "FAIL\n";
                } else {
                    for (int z = l; z <= r; z++) {
                        op[z] = false;
                    }
                    cout << "OK\n";
                }
            } else if (o == 2) {
                int no, l, r;
                cin >> no >> l >> r;
                bool good = true;
                for (int z = l; z <= r; z++) {
                    if (op[z] || id[z] != no) {
                        good = false;
                        break;
                    }
                }
                if (!good) {
                    cout << "FAIL\n";
                } else {
                    for (int z = l; z <= r; z++) {
                        op[z] = true;
                    }
                    cout << "OK\n";
                }
            } else {
                int p;
                cin >> p;
                if (op[p]) cout << id[p] << " " << c[p] << "\n";
                else cout << "0 0\n";
            }
        }
    } 
//    else if (n == 1) {
//
//    } else {
//        set<pair<int, int>> s;
//        map<pair<int, int>, pair<int, int>> id;
//        for (int i = 0; i < k; i++) {
//            int o; cin >> o;
//            if (o == 0) {
//                int no, l, r, x;
//                cin >> no >> l >> r >> x;
//                if (s.empty()) {
//                    s.emplace(l, r);
//                    id[{l, r}] = {no, x};
//                    cout << r << "\n";
//                    continue;
//                }
//                auto it = s.lower_bound({l, -1});
//                if (it->first == l && id[*it].first != no) {
//                    cout << -1 << "\n";
//                    continue;
//                }
//                if (it != s.begin()) {
//                    auto pit = prev(it);
//                    if (pit->second >= l) {
//                        if (id[*pit].first != no) {
//                            cout << -1 << "\n";
//                            continue;
//                        } else {
//                            id[{pit->first, l - 1}] = id[*pit];
//                            id.erase(*pit);
//                            s.emplace(pit->first, l - 1);
//                            s.erase(pit);
//                        }
//                    }
//                }
//                while (it != s.end()) {
//                    if (it->first > r) {
//                        s.emplace(l, r);
//                        id[{l, r}] = {no, x};
//                        cout << r << "\n";
//                        break;
//                    }
//                    auto p = id[*it];
//                    if (p.first != no) {
//                        s.emplace(l, it->first - 1);
//                        id[{l, it->first - 1}] = {no, x};
//                        cout << it->first - 1 << "\n";
//                        break;
//                    } else {
//                        if (p.second > r) {
//                            id[{r + 1, it->second}] = id[*it];
//                            s.emplace(r + 1, it->second);
//                            id[{l, r}] = {no, x};
//                            s.emplace(l, r);
//                            id.erase(id.find(*it));
//                            s.erase(it);
//                            cout << r << "\n";
//                            break;
//                        }
//                        id.erase(id.find(*it));
//                        it = s.erase(it);
//                    }
//                }
//            } else if (o == 3) {
//                int p;
//                cin >> p;
//                auto it = id.upper_bound({p, -1});
//                if (it == id.begin()) {
//                    cout << "0 0\n";
//                } else {
//                    it = prev(it);
//                    if (p > it->first.second) cout << "0 0\n";
//                    else cout << it->second.first << " " << it->second.second << "\n";
//                }
//            }
//        }
//    }

    return 0;
}


