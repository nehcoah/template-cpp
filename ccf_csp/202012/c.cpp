#include "bits/stdc++.h"

using namespace std;
using ll = long long;

struct Node {
    int type = 0;
    ll cur_size = 0, dir_size = 0;
    ll cur_limit = 0, dir_limit = 0;
    unordered_map<string, Node*> nxt;
    Node *pa;
    Node(int _t, ll cs, ll ds, ll cl, ll dl): type(_t), cur_size(cs), dir_size(ds), cur_limit(cl), dir_limit(dl), nxt(), pa(nullptr) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Node *root = new Node(0, 0, 0, 0, 0);

    auto get_dir = [&](string& s) {
        vector<string> d;
        stringstream io(s);
        while (getline(io, s, '/')) {
            if (s == "") continue;
            d.push_back(s);
        }
        return d;
    };

    vector<pair<Node*, string>> rb;
    auto rollback = [&]() {
        for (int i = rb.size() - 1; i >= 0; i--) {
            rb[i].first->pa->nxt.erase(rb[i].second);
        }
    };

    // C <file path> <file size>
    // 创建普通文件的指令有两个参数，是空格分隔的字符串和一个正整数，分别表示需要创建的普通文件的路径和文件的大小。
    // 对于该指令，若路径所指的文件已经存在，且也是普通文件的，则替换这个文件；
    // 若路径所指文件已经存在，但是目录文件的，则该指令不能执行成功。
    // 当路径中的任何目录不存在时，应当尝试创建这些目录；
    // 若要创建的目录文件与已有的同一双亲目录下的孩子文件中的普通文件名称重复，则该指令不能执行成功。
    // 另外，还需要确定在该指令的执行是否会使该文件系统的配额变为不满足（检查所有父节点），如果会发生这样的情况，则认为该指令不能执行成功，反之则认为该指令能执行成功。

    auto C = [&]() {
        string s;
        ll sz;
        cin >> s >> sz;
        auto d = get_dir(s);
        rb.resize(0);

        auto cur = root;
        for (int i = 0; i < d.size() - 1; i++) {
            if (cur->nxt.count(d[i]) == 0) {
                cur->nxt[d[i]] = new Node(0, 0, 0, 0, 0);
                cur->nxt[d[i]]->pa = cur;
                rb.emplace_back(cur->nxt[d[i]], d[i]);
            }
            if (cur->nxt[d[i]]->type == 1) {
                rollback();
                return "N";
            }
            cur = cur->nxt[d[i]];
        }
        if (cur->nxt.count(d.back())) {
            if (cur->nxt[d.back()]->type == 0) {
                rollback();
                return "N";
            }
        }
        ll diff = cur->nxt.count(d.back()) ? sz - cur->nxt[d.back()]->cur_size : sz;
        auto c = cur;
        if (cur->cur_limit && cur->cur_size + diff > cur->cur_limit) {
            rollback();
            return "N";
        }
        while (c != nullptr) {
            if (c->dir_limit && c->dir_size + diff > c->dir_limit) {
                rollback();
                return "N";
            }
            c = c->pa;
        }
        if (cur->nxt.count(d.back())) {
            cur->nxt[d.back()]->cur_size = sz;
            cur->nxt[d.back()]->dir_size = sz;
        } else {
            cur->nxt[d.back()] = new Node(1, sz, sz, 0, 0);
            cur->nxt[d.back()]->pa = cur;
        }
        cur->cur_size += diff;
        cur->dir_size += diff;
        c = cur->pa;
        while (c != nullptr) {
            c->dir_size += diff;
            c = c->pa;
        }
        return "Y";
    };

    // R <file path>
    // 移除文件的指令有一个参数，是字符串，表示要移除的文件的路径。
    // 若该路径所指的文件不存在，则不进行任何操作。
    // 若该路径所指的文件是目录，则移除该目录及其所有后代文件。
    // 在上述过程中被移除的目录（如果有）上设置的配额值也被移除。
    // 该指令始终认为能执行成功。

    auto R = [&]() {
        string s;
        cin >> s;
        auto d = get_dir(s);

        auto cur = root;
        for (int i = 0; i < d.size(); i++) {
            if (cur->nxt.count(d[i]) == 0) {
                return "Y";
            }
            cur = cur->nxt[d[i]];
        }
        if (cur->type == 1) {
            cur->pa->cur_size -= cur->cur_size;
        }
        ll diff = cur->dir_size;
        auto c = cur->pa;
        c->nxt.erase(d.back());
        while (c != nullptr) {
            c->dir_size -= diff;
            c = c->pa;
        }
        return "Y";
    };

    // Q <file path> <LD> <LR>
    // 设置配额值的指令有三个参数，是空格分隔的字符串和两个非负整数，分别表示需要设置配额值的目录的路径、目录配额和后代配额。
    // 该指令表示对所指的目录文件，分别设置目录配额和后代配额。
    // 若路径所指的文件不存在，或者不是目录文件，则该指令执行不成功。
    // 若在该目录上已经设置了配额，则将原配额值替换为指定的配额值。
    // 特别地，若配额值为0，则表示不对该项配额进行限制。
    // 若在应用新的配额值后，该文件系统配额变为不满足，那么该指令执行不成功。

    auto Q = [&]() {
        string s;
        ll ld, lr;
        cin >> s >> ld >> lr;
        auto d = get_dir(s);

        auto cur = root;
        for (int i = 0; i < d.size(); i++) {
            if (cur->nxt.count(d[i]) == 0 || cur->nxt[d[i]]->type == 1) {
                return "N";
            }
            cur = cur->nxt[d[i]];
        }
        bool good = true;
        if (ld && cur->cur_size > ld) good = false;
        if (lr && cur->dir_size > lr) good = false;
        if (!good) return "N";
        cur->cur_limit = ld;
        cur->dir_limit = lr;
        return "Y";
    };

    int n;
    cin >> n;
    for (int z = 0; z < n; z++) {
        char c;
        cin >> c;
        if (c == 'C') {
            cout << C() << "\n";
        } else if (c == 'R') {
            cout << R() << "\n";
        } else {
            cout << Q() << "\n";
        }
    }

    return 0;
}

