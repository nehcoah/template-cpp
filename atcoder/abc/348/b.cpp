#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
    }
    for (int i = 0; i < n; i++) {
        int cur = 0, id = -1;
        for (int j = 0; j < n; j++) {
            int d = (p[i].first - p[j].first) * (p[i].first - p[j].first) + (p[i].second - p[j].second) * (p[i].second - p[j].second);
            if (d > cur) {
                id = j, cur = d;
            }
        }
        cout << id + 1 << endl;
    }

    return 0;
}
