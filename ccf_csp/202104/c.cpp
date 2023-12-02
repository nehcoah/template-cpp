// 本来写了priority_queue优化的，但是一直70分
// 看了一下大伙的，我真不知道为什么1s能跑完1e8，甚至评测只跑了100ms

#include "bits/stdc++.h"

using namespace std;
using ll = long long;

// 处于待分配和占用状态的 IP 地址拥有一个大于零的过期时刻。
// 在到达该过期时刻时，若该地址的状态是待分配，则该地址的状态会自动变为未分配，且占用者清空，过期时刻清零；
// 否则该地址的状态会由占用自动变为过期，且过期时刻清零。
// 处于未分配和过期状态的 IP 地址过期时刻为零，即没有过期时刻。

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, Td, Tmx, Tmn, n;
    string H;
    cin >> N >> Td >> Tmx >> Tmn >> H >> n;

    vector<ll> state(N + 1), d(N + 1);
    vector<string> host(N + 1);
//    unordered_map<string, unordered_set<ll>> occ;
//    unordered_map<string, unordered_set<ll>> namely;

//    priority_queue<ll> no, odate;
//    priority_queue<pair<ll, ll>> pq;
//    for (int i = 1; i <= N; i++) {
//        no.push(-i);
//    }

    for (int i = 0; i < n; i++) {
        ll t, ip, od;
        string s, e, type;
        cin >> t >> s >> e >> type >> ip >> od;
        if (type != "DIS" && type != "REQ") continue;
        if (e != H && e != "*" && type != "REQ") continue;
        if (e == "*" && type != "DIS") continue;
        if (e == H && type == "DIS") continue;

//        while (!pq.empty() && -pq.top().first <= t) {
//            auto pt = pq.top();
//            pq.pop();
//            if (d[pt.second] != -pt.first) pq.emplace(-d[pt.second], pt.second);
//            else {
//                if (state[pt.second] == 1) {
//                    state[pt.second] = 0;
//                    host[pt.second] = "";
//                    d[pt.second] = 0;
//                    no.push(-pt.second);
//                } else {
//                    odate.push(-pt.second);
//                    occ[host[pt.second]].erase(pt.second);
//                    if (occ[host[pt.second]].empty()) occ.erase(host[pt.second]);
//                    state[pt.second] = 3;
//                    d[pt.second] = 0;
//                }
//            }
//        }
        for (int j = 1; j <= N; j++) {
            if (d[j] && d[j] <= t) {
                if (state[j] == 1) {
                    state[j] = 0;
                    host[j] = "";
                    d[j] = 0;
                } else {
                    state[j] = 3;
                    d[j] = 0;
                }
            }
        }

        if (type == "DIS") {
            ll choose = -1;
            for (int j = 1; j <= N; j++) {
                if (host[j] == s) {
                    choose = j;
                    break;
                }
            }
            if (choose == -1) {
                for (int j = 1; j <= N; j++) {
                    if (state[j] == 0) {
                        choose = j;
                        break;
                    }
                }
            }
            if (choose == -1) {
                for (int j = 1; j <= N; j++) {
                    if (state[j] == 3) {
                        choose = j;
                        break;
                    }
                }
            }
//            if (occ.count(s)) choose = *occ[s].begin();
//            else if (!no.empty()) {
//                choose = -no.top();
//                no.pop();
//            } else if (!odate.empty()) {
//                while (!odate.empty()) {
//                    ll x = -odate.top();
//                    odate.pop();
//                    if (d[x] == 0) {
//                        choose = x;
//                        break;
//                    }
//                }
//            } else continue;
            if (choose == -1) continue;
            state[choose] = 1;
//            occ[s].insert(choose);
            if (od == 0) {
                d[choose] = t + Td;
            } else {
                ll x = od - t;
                if (x > Tmx) d[choose] = t + Tmx;
                else if (x < Tmn) d[choose] = t + Tmn;
                else d[choose] = od;
            }
//            pq.emplace(-d[choose], choose);
//            namely[s].insert(choose);
            host[choose] = s;
            cout << H << " " << s << " OFR " << choose << " " << d[choose] << "\n";
        } else {
            if (e == H) {
                if (ip > N || ip < 1 || host[ip] != s) {
                    cout << H << " " << s << " NAK " << ip << " 0\n";
                    continue;
                }
                state[ip] = 2;
                if (od == 0) {
                    d[ip] = t + Td;
                } else {
                    ll x = od - t;
                    if (x > Tmx) d[ip] = t + Tmx;
                    else if (x < Tmn) d[ip] = t + Tmn;
                    else d[ip] = od;
                }
//                occ[s].insert(ip);
//                pq.emplace(-d[ip], ip);
                cout << H << " " << s << " ACK " << ip << " " << d[ip] << "\n";
            } else {
//                for (auto it = namely[s].begin(); it != namely[s].end(); ) {
//                    ll x = *it;
//                    if (host[x] != s) {
//                        it = namely[s].erase(it);
//                        continue;
//                    }
//                    if (state[x] == 1) {
//                        state[x] = 0;
//                        d[x] = 0;
//                        host[x] = "";
//                        no.push(-x);
//                    }
//                    it++;
//                }
                for (int j = 1; j <= N; j++) {
                    if (host[j] == s && state[j] == 1) {
                        state[j] = 0;
                        d[j] = 0;
                        host[j] = "";
                    }
                }
            }
        }
    }

    return 0;
}


