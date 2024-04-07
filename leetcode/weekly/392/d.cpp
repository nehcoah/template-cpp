struct UnionFind {
    vector<int> parent, size, cost;
    int cnt;

    UnionFind(int n) {
        parent.resize(n);
        size.resize(n, 1);
        cost.resize(n, 0x3fffffff);
        cnt = n;
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x){
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    bool merge(int x, int y, int w) {
        x = find(x), y = find(y);
        if (x == y) {
            cost[x] &= w;
            return false;
        }
        if (size[x] > size[y]) {
            parent[y] = x;
            size[x] += size[y];
            cost[x] &= cost[y] & w;
        } else {
            parent[x] = y;
            size[y] += size[x];
            cost[y] &= cost[x] & w;
        }
        --cnt;
        return true;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        UnionFind uf(n);
        for (auto &e : edges) {
            uf.merge(e[0], e[1], e[2]);
        }
        vector<int> ans;
        for (auto &q : query) {
            int x = q[0], y = q[1];
            if (x == y) ans.push_back(0);
            else {
                x = uf.find(x), y = uf.find(y);
                if (x != y) ans.push_back(-1);
                else ans.push_back(uf.cost[x]);    
            }
        }
        return ans;
    }
};
