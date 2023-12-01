#include "bits/stdc++.h"

using namespace std;
using ll = long long;

static unsigned long _next = 1;

/* RAND_MAX assumed to be 32767 */
int myrand(void) {
    _next = _next * 1103515245 + 12345;
    return((unsigned)(_next/65536) % 32768);
}

struct Node {
    double v, u, a, b, c, d;
} n[1000];

struct Edge {
    int y;
    double w;
    int D;
};

double I[1000][1000];
int cnt[1000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, S, P, T;
    cin >> N >> S >> P >> T;
    double dt;
    cin >> dt;
//    vector<Node> n(N);
    vector<int> r(P);
    vector<vector<Edge>> adj(N + P);
    for (int i = 0; i < N; ) {
        int rn; cin >> rn;
        double v, u, a, b, c, d;
        cin >> v >> u >> a >> b >> c >> d;
        for (int j = 0; j < rn; i++, j++) {
            n[i] = {v, u, a, b, c, d};
        }
    }
    for (int i = 0; i < P; i++) {
        cin >> r[i];
    }
    for (int i = 0; i < S; i++) {
        int s, t, D;
        double w;
        cin >> s >> t >> w >> D;
        adj[s].push_back({t, w, D});
    }

//    vector<vector<double>> I(1001, vector<double>(N));
//    vector<int> cnt(N);
    memset(I, 0, sizeof(I));
    memset(cnt, 0, sizeof(cnt));
    int mod = 1000;

    for (int t = 1; t <= T; t++) {
        for (int i = 0; i < P; i++) {
            int cur = myrand();
            if (r[i] > cur) {
                for (auto &e : adj[i + N]) {
                    I[(t + e.D) % mod][e.y] += e.w;
                }
            }
        }
        for (int i = 0; i < N; i++) {
            double nv = n[i].v + dt * (0.04 * n[i].v * n[i].v + 5 * n[i].v + 140 - n[i].u) + I[t % mod][i];
            double nu = n[i].u + dt * n[i].a * (n[i].b * n[i].v - n[i].u);
            if (nv >= 30) {
                for (auto &e : adj[i]) {
                    I[(t + e.D) % mod][e.y] += e.w;
                }
                cnt[i]++;
                n[i].v = n[i].c;
                n[i].u = nu + n[i].d;
            } else {
                n[i].v = nv;
                n[i].u = nu;
            }
        }
        memset(I[t % mod], 0, sizeof(I[t % mod]));
    }

    double mx = -numeric_limits<double>::max(), mn = numeric_limits<double>::max();
    int cmx = numeric_limits<int>::min(), cmn = numeric_limits<int>::max();
    for (int i = 0; i < N; i++) {
        mx = max(mx, n[i].v);
        mn = min(mn, n[i].v);
        cmx = max(cmx, cnt[i]);
        cmn = min(cmn, cnt[i]);
    }
    cout << fixed << setprecision(3) << mn << " " << mx << "\n";
    cout << cmn << " " << cmx << "\n";

    return 0;
}


