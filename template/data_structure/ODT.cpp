struct Node {
    int l, r;
    mutable int v;
    Node(const int &_l, const int &_r, const int &_v): l(_l), r(_r), v(_v) {}
    bool operator < (const Node &rhs) const {
        return l < rhs.l;
    }
};

struct ODT {
    set<Node> odt;
    int n;

    ODT(int _n): n(_n) {}
    ODT(Node &init) {
        n = init.r;
        odt.insert(init);
    }

    auto split(int x) {
        if (x > n) return odt.end();
        auto it = --odt.upper_bound(Node(x, 0, 0));
        if (it->l == x) return it;
        int l = it->l, r = it->r, v = it->v;
        odt.erase(it);
        odt.insert(Node(l, x - 1, v));
        return odt.insert(Node(x, r, v)).first;
    }

    void assign(int l, int r, int v) {
        auto itr = split(r + 1), itl = split(l);
        odt.erase(itl, itr);
        odt.insert(Node(l, r, v));
    }

    void _op(int l, int r) {
        auto itr = split(r + 1), itl = split(l);
        for (auto it = itl; it != itr; it++) {
            // op here
        }
        // odt.erase(itl, itr);
        // odt.insert(Node(l, r, _value));
    }
};
