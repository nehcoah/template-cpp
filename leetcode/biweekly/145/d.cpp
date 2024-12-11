struct UnionFind {
    vector<int> f, siz;
    int cnt;

    UnionFind() {}
    UnionFind(int n) {
        init(n);
    }

    void init(int n) {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
        cnt = n;
    }

    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        cnt -= 1;
        return true;
    }

    int size(int x) {
        return siz[find(x)];
    }
};

class Solution {
public:
    int countComponents(vector<int>& nums, int threshold) {
        int n = nums.size();
        UnionFind uf(threshold + 1);
        for (int i : nums) {
            for (int x = i; x <= threshold; x += i) {
                uf.merge(i, x);
            }
        }

        unordered_set<int> st;
        for (int x : nums) {
            if (x <= threshold) st.insert(uf.find(x));
            else st.insert(x);
        }
        return st.size();
    }
};
