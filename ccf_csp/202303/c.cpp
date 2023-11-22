#include "bits/stdc++.h"

using namespace std;
using ll = long long;

struct Node {
    int val, sign;
    Node *l = nullptr, *r = nullptr;
    Node(int v, int si): val(v), sign(si) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    map<int, map<int, bitset<2501>>> avp;
    map<int, bitset<2501>> ap;
    vector<int> dn(n);

    for (int i = 0; i < n; i++) {
        int q;
        cin >> dn[i] >> q;
        for (int j = 0; j < q; j++) {
            int a, b; cin >> a >> b;
            avp[a][b].set(i);
            ap[a].set(i);
        }
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;

        function<pair<Node*, int>(int)> build = [&](int p) -> pair<Node*, int> {
            while (s[p] == '(' || s[p] == ')') p++;
            if (s[p] == '&' || s[p] == '|') {
                Node* cur = new Node(s[p], 1);
                auto ls = build(p + 2);
                cur->l = ls.first;
                auto rs = build(ls.second + 1);
                cur->r = rs.first;
                return {cur, rs.second};
            } else {
                int j = p;
                while (isdigit(s[j])) j++;
                int attr = stoi(s.substr(p, j - p));
                char c = s[j++];
                p = j;
                while (isdigit(s[j])) j++;
                int val = stoi(s.substr(p, j - p));
                Node* cur = new Node(c, 1);
                cur->l = new Node(attr, 0);
                cur->r = new Node(val, 0);
                return {cur, j + 1};
            }
        };
        auto node = build(0).first;

        function<pair<bitset<2501>, int>(Node*)> dfs = [&](Node* root) -> pair<bitset<2501>, int> {
            if (root == nullptr) return {{}, 0};
            auto ls = dfs(root->l);
            auto rs = dfs(root->r);
            if (root->sign) {
                if (root->val == '&') return {ls.first & rs.first, 0};
                else if (root->val == '|') return {ls.first | rs.first, 0};
                else if (root->val == ':') {
                    int attr = ls.second, val = rs.second;
                    if (avp.count(attr) && avp[attr].count(val)) return {avp[attr][val], 0};
                    else return {{}, 0};
                } else {
                    int attr = ls.second, val = rs.second;
                    auto all = ap[attr], equal = avp[attr][val];
                    return {all ^ equal, 0};
                }
            } else return {{}, root->val};
        };
        auto ans = dfs(node).first;
        vector<int> cur;
        for (int j = 0; j < n; j++) {
            if (ans.test(j)) cur.push_back(dn[j]);
        }
        sort(cur.begin(), cur.end());
        for (int x : cur) cout << x << " ";
        cout << "\n";
    }

    return 0;
}


