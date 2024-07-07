template<class Info>
struct SegmentTree {
    int n;
    vector<Info> info;
    SegmentTree() : n(0) {}
    SegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }
    template<class T>
    SegmentTree(vector<T> init_) {
        init(init_);
    }
    void init(int n_, Info v_ = Info()) {
        init(vector(n_, v_));
    }
    template<class T>
    void init(vector<T> init_) {
        n = init_.size();
        info.assign(4 << int(log2(n)), Info());
        function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                info[p] = init_[l];
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m, r);
            pull(p);
        };
        build(1, 0, n);
    }
    void pull(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        if (x < m) {
            modify(2 * p, l, m, x, v);
        } else {
            modify(2 * p + 1, m, r, x, v);
        }
        pull(p);
    }
    void modify(int p, const Info &v) {
        modify(1, 0, n, p, v);
    }
    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return Info();
        }
        if (l >= x && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
    }
    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n, l, r);
    }
    template<class F>
    int findFirst(int p, int l, int r, int x, int y, F pred) {
        if (l >= y || r <= x || !pred(info[p])) {
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        int m = (l + r) / 2;
        int res = findFirst(2 * p, l, m, x, y, pred);
        if (res == -1) {
            res = findFirst(2 * p + 1, m, r, x, y, pred);
        }
        return res;
    }
    template<class F>
    int findFirst(int l, int r, F pred) {
        return findFirst(1, 0, n, l, r, pred);
    }
    template<class F>
    int findLast(int p, int l, int r, int x, int y, F pred) {
        if (l >= y || r <= x || !pred(info[p])) {
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        int m = (l + r) / 2;
        int res = findLast(2 * p + 1, m, r, x, y, pred);
        if (res == -1) {
            res = findLast(2 * p, l, m, x, y, pred);
        }
        return res;
    }
    template<class F>
    int findLast(int l, int r, F pred) {
        return findLast(1, 0, n, l, r, pred);
    }
};

struct Info {
    int x = (1ll << 32) - 1;
};

Info operator+(Info a, Info b) {
    return {a.x & b.x};
}

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<Info> init(n);
        for (int i = 0; i < n; i++) {
            init[i] = {nums[i]};
        }
        SegmentTree<Info> t(init);
        
        auto check = [&](int x) {
            if (nums[x] < k) return 0;
            if (t.rangeQuery(x, n).x > k) return 0;
            int l = x, r = n - 1;
            while (l < r) {
                int mid = (l + r) >> 1;
                if (t.rangeQuery(x, mid + 1).x > k) l = mid + 1;
                else r = mid;
            }
            int L = x, R = n - 1;
            while (L < R) {
                int mid = (L + R + 1) >> 1;
                if (t.rangeQuery(x, mid + 1).x >= k) L = mid;
                else R = mid - 1;
            }
            return L - l + 1;
        };
        
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += check(i);
        }
        return ans;
    }
};

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector f(n, vector<int>(30, -1));
        for (int i = 0; i < 30; i++) {
            for (int j = 0; j < n; j++) {
                if ((nums[j] >> i & 1) == 0) f[j][i] = j;
                else if (j > 0) f[j][i] = f[j - 1][i];
            }
        }

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            vector<int> idx;
            for (int j = 0; j < 30; j++) {
                if (f[i][j] >= 0) idx.push_back(f[i][j]);
            }
            sort(idx.begin(), idx.end());
            idx.erase(unique(idx.begin(), idx.end()), idx.end());
            reverse(idx.begin(), idx.end());
            int t = nums[i];
            for (int j = 0; j < idx.size(); j++) {
                t &= nums[idx[j]];
                if (t == k) {
                    if (j + 1 == idx.size()) ans += idx[j] + 1;
                    else ans += idx[j] - idx[j + 1];
                }
            }
        }
        return ans;
    }
};
