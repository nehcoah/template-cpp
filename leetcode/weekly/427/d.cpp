
template<typename T>
struct Fenwick {
    int n;
    vector<T> tree;

    Fenwick(int n = 0) {
        init(n);
    }

    void init(int sz) {
        this->n = sz + 1;
        tree.assign(sz + 2, T());
    }

    void clear() {
        tree.assign(n + 2, T());
    }

    void add(int pos, T val) {
        pos++;
        for (; pos < tree.size(); pos += pos & -pos) tree[pos] += val;
    }

    T query(int pos) {
        pos++;
        auto ans = T();
        for (; pos; pos -= pos & -pos) ans += tree[pos];
        return ans;
    }

    T query_interval(int l, int r) {
        assert(l <= r);
        return query(r) - query(l - 1);
    }

};

class Solution {
public:
    long long maxRectangleArea(vector<int>& xCoord, vector<int>& yCoord) {
        int n = xCoord.size();

        auto id = yCoord;
        sort(id.begin(), id.end());
        id.erase(unique(id.begin(), id.end()), id.end());
        Fenwick<int> t(id.size() + 1);

        vector<pair<int, int>> c(n);
        for (int i = 0; i < n; i++) {
            c[i] = {xCoord[i], yCoord[i]};
        }
        sort(c.begin(), c.end());
        t.add(lower_bound(id.begin(), id.end(), c[0].second) - id.begin(), 1);

        long long ans = -1;
        vector<array<int, 3>> pre(id.size(), {-1, -1, -1});
        for (int i = 1; i < n; i++) {
            auto [x1, y1] = c[i - 1];
            auto [x2, y2] = c[i];
            int y_id = lower_bound(id.begin(), id.end(), y2) - id.begin();
            t.add(y_id, 1);

            if (x1 != x2) continue;
            int cur = t.query_interval(lower_bound(id.begin(), id.end(), y1) - id.begin(), y_id);
            auto [x_pre, y_pre, cnt_pre] = pre[y_id];
            if (y_pre == y1 && cnt_pre + 2 == cur) {
                ans = max(ans, 1ll * (x2 - x_pre) * (y2 - y1));
            }
            pre[y_id] = {x1, y1, cur};
        }
        return ans;
    }
};
