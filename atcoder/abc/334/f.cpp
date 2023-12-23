#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    int sx, sy;
    cin >> sx >> sy;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    vector<double> dis(n), d(n);
    for (int i = 0; i < n; i++) {
        dis[i] = hypot(sx - x[i], sy - y[i]);
    }
    double sum = dis[0] + dis.back();
    for (int i = 1; i < n; i++) {
        d[i] = hypot(x[i] - x[i - 1], y[i] - y[i - 1]);
        sum += d[i];
        d[i] = dis[i - 1] + dis[i] - d[i];
    }
    deque<int> dq{0};
    vector<double> f(n + 1);
    for (int i = 1; i <= n; i++) {
        while (!dq.empty() && dq.front() < i - k) dq.pop_front();
        f[i] = f[dq.front()] + d[i];
        while (!dq.empty() && f[dq.back()] > f[i]) dq.pop_back();
        dq.push_back(i);
    }
    cout << fixed << setprecision(15) << sum + f.back() << endl;

    return 0;
}

