class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size(), q = queries.size();
        for (int i = 0; i < q; i++) if (queries[i][0] > queries[i][1]) swap(queries[i][0], queries[i][1]);
        vector<int> idx(n), qidx(q), ans(q);
        set<int> st;
        iota(idx.begin(), idx.end(), 0);
        iota(qidx.begin(), qidx.end(), 0);
        ranges::sort(idx, [&](int a, int b) {return heights[a] > heights[b];} );
        ranges::sort(qidx, [&](int a, int b) {return heights[queries[a][0]] > heights[queries[b][0]];} );
        
        for (int qi = 0, i = 0; qi < q; qi++) {
            int a = queries[qidx[qi]][0], b = queries[qidx[qi]][1];
            if (a == b) ans[qidx[qi]] = a;
            else if (heights[a] < heights[b]) ans[qidx[qi]] = b;
            else {
                while (i < n && heights[idx[i]] > heights[a]) st.insert(idx[i]), i++;
                auto it = st.upper_bound(b);
                if (it == st.end()) ans[qidx[qi]] = -1;
                else ans[qidx[qi]] = *it;
            }
            
        }
        return ans;
    }
};

// Solution with SegmentTree
// template<class Info>
// struct SegmentTree {
//     int n;
//     vector<Info> info;
//     SegmentTree() : n(0) {}
//     SegmentTree(int n_, Info v_ = Info()) {
//         init(n_, v_);
//     }
//     template<class T>
//     SegmentTree(vector<T> init_) {
//         init(init_);
//     }
//     void init(int n_, Info v_ = Info()) {
//         init(vector(n_, v_));
//     }
//     template<class T>
//     void init(vector<T> init_) {
//         n = init_.size();
//         info.assign(4 << __lg(n), Info());
//         function<void(int, int, int)> build = [&](int p, int l, int r) {
//             if (r - l == 1) {
//                 info[p] = init_[l];
//                 return;
//             }
//             int m = (l + r) / 2;
//             build(2 * p, l, m);
//             build(2 * p + 1, m, r);
//             pull(p);
//         };
//         build(1, 0, n);
//     }
//     void pull(int p) {
//         info[p] = info[2 * p] + info[2 * p + 1];
//     }
//     void modify(int p, int l, int r, int x, const Info &v) {
//         if (r - l == 1) {
//             info[p] = v;
//             return;
//         }
//         int m = (l + r) / 2;
//         if (x < m) {
//             modify(2 * p, l, m, x, v);
//         } else {
//             modify(2 * p + 1, m, r, x, v);
//         }
//         pull(p);
//     }
//     void modify(int p, const Info &v) {
//         modify(1, 0, n, p, v);
//     }
//     Info rangeQuery(int p, int l, int r, int x, int y) {
//         if (l >= y || r <= x) {
//             return Info();
//         }
//         if (l >= x && r <= y) {
//             return info[p];
//         }
//         int m = (l + r) / 2;
//         return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
//     }
//     Info rangeQuery(int l, int r) {
//         return rangeQuery(1, 0, n, l, r);
//     }
//     template<class F>
//     int findFirst(int p, int l, int r, int x, int y, F pred) {
//         if (l >= y || r <= x || !pred(info[p])) {
//             return -1;
//         }
//         if (r - l == 1) {
//             return l;
//         }
//         int m = (l + r) / 2;
//         int res = findFirst(2 * p, l, m, x, y, pred);
//         if (res == -1) {
//             res = findFirst(2 * p + 1, m, r, x, y, pred);
//         }
//         return res;
//     }
//     template<class F>
//     int findFirst(int l, int r, F pred) {
//         return findFirst(1, 0, n, l, r, pred);
//     }
//     template<class F>
//     int findLast(int p, int l, int r, int x, int y, F pred) {
//         if (l >= y || r <= x || !pred(info[p])) {
//             return -1;
//         }
//         if (r - l == 1) {
//             return l;
//         }
//         int m = (l + r) / 2;
//         int res = findLast(2 * p + 1, m, r, x, y, pred);
//         if (res == -1) {
//             res = findLast(2 * p, l, m, x, y, pred);
//         }
//         return res;
//     }
//     template<class F>
//     int findLast(int l, int r, F pred) {
//         return findLast(1, 0, n, l, r, pred);
//     }
// };

// struct Info {
//     int x;
// };

// Info operator+(const Info &a, const Info &b) {
//     return {max(a.x, b.x)};
// }

// class Solution {
// public:
//     vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
//         int n = heights.size();
//         vector<Info> init(n);
//         for (int i = 0; i < n; i++) init[i] = {heights[i]};
//         SegmentTree<Info> st(init);
//         vector<int> ans;
//         for (auto q : queries) {
//             int a = q[0], b = q[1];
//             if (a > b) swap(a, b);
//             if (a == b) ans.push_back(a);
//             else if (heights[a] < heights[b]) ans.push_back(b);
//             else {
//                 int c = st.findFirst(b + 1, n, [&](Info i) {
//                     return heights[a] < i.x;
//                 });
//                 if (c == n) ans.push_back(-1);
//                 else ans.push_back(c);
//             }
//         }
//         return ans;
//     }
// };
