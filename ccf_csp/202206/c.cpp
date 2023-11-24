#include "bits/stdc++.h"

using namespace std;
using ll = long long;

struct Info {
    unordered_set<string> op, repo, name, u, g;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;
    unordered_map<string, Info> skill;
    unordered_map<string, unordered_set<string>> group;

    for (int i = 0; i < n; i++) {
        string usr; cin >> usr;
        int nv; cin >> nv;
        for (int j = 0; j < nv; j++) {
            string s; cin >> s;
            skill[usr].op.insert(s);
        }
        int no; cin >> no;
        for (int j = 0; j < no; j++) {
            string s; cin >> s;
            skill[usr].repo.insert(s);
        }
        int nn; cin >> nn;
        for (int j = 0; j < nn; j++) {
            string s; cin >> s;
            skill[usr].name.insert(s);
        }
    }

    for (int i = 0; i < m; i++) {
        string usr; cin >> usr;
        int ns; cin >> ns;
        for (int j = 0; j < ns; j++) {
            string s, t;
            cin >> s >> t;
            if (s == "u") {
                skill[usr].u.insert(t);
                skill[t].u.insert(usr);
            } else {
                skill[usr].g.insert(t);
                group[t].insert(usr);
            }
        }
    }

    auto check = [&](const string &usr, string &op, string &repo, string &name) {
        auto &cur = skill[usr];
        bool o = false, r = false;
        if (cur.op.count("*") || cur.op.count(op)) o = true;
        if (!o) return false;
        if (cur.repo.count("*") || cur.repo.count(repo)) r = true;
        if (!r) return false;
        if (cur.name.empty() || cur.name.count(name)) return true;
        return false;
    };

    for (int i = 0; i < q; i++) {
        string usr; cin >> usr;
        int ng; cin >> ng;
        unordered_set<string> p{usr};
        for (int j = 0; j < ng; j++) {
            string s; cin >> s;
            for (auto &a : group[s]) p.insert(a);
        }
        for (auto &a : skill[usr].u) p.insert(a);
        for (auto &g : skill[usr].g) {
            for (auto &a : group[g]) p.insert(a);
        }
        string op, repo, name;
        cin >> op >> repo >> name;
        bool good = false;
        for (auto &a : p) good |= check(a, op, repo, name);
        cout << good << "\n";
    }

    return 0;
}


