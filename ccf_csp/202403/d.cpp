#include "bits/stdc++.h"

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c, m, n;
    cin >> c >> m >> n;
    map<int, int> mp;
    for (int i = 0; i < m; i++) {
        int x, w;
        cin >> x >> w;
        mp[x] = w;
    }

    while (n--) {
        priority_queue<int, vector<int>, greater<>> pq;
        int p; cin >> p;
        mp[p] += 1;
        if (mp[p] == 5) {
            pq.push(p);
        }
        while (!pq.empty()) {
            int x = pq.top(); pq.pop();
            auto it = mp.find(x);
            if (it != mp.begin()) {
                prev(it)->second += 1;
                if (prev(it)->second == 5) pq.push(prev(it)->first);
            }
            if (next(it) != mp.end()) {
                next(it)->second += 1;
                if (next(it)->second == 5) pq.push(next(it)->first);
            }
            mp.erase(it);
        }
        cout << mp.size() << endl;
    }

    return 0;
}

