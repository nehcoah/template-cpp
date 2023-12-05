#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(12);

    int n, m, r;
    cin >> n >> m >> r;

    vector<int> O(n);
    vector<vector<int>> p(m, vector<int>(n));
    vector<int> po(m);
    for (int i = 0; i < n; i++) {
        cin >> O[i];
    }
    for (int i = 0; i < m; i++) {
        int cur = 0;
        for (int j = 0; j < n; j++) {
            cin >> p[i][j];
            cur += (p[i][j] - O[j]) * (p[i][j] - O[j]);
        }
        po[i] = cur;
    }

    vector<vector<double>> dis(m, vector<double>(m));
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            double oa = sqrt(po[i]), ob = sqrt(po[j]);
            int cur = 0;
            for (int x = 0; x < n; x++) cur += (p[i][x] - p[j][x]) * (p[i][x] - p[j][x]);
            double ab = sqrt(cur);

            double P = (oa + ob + ab) / 2;
            double area = sqrt(P * (P - oa) * (P - ob) * (P - ab));
            double h = area * 2 / ab;
            
            if (h > r || po[j] + cur < po[i] || po[i] + cur < po[j]) {
                dis[i][j] = dis[j][i] = ab;
            } else {
                double aoc = acos(r / oa), bod = acos(r / ob), aob = acos((oa * oa + ob * ob - ab * ab) / (2 * oa * ob));
                double cd = r * (aob - aoc - bod);
                double ac = sqrt(po[i] - r * r), bd = sqrt(po[j] - r * r);
                dis[i][j] = dis[j][i] = ac + cd + bd;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        double ans = 0;
        for (int j = 0; j < m; j++) {
            ans += dis[i][j];
        }
        cout << ans << "\n";
    }

    return 0;
}

