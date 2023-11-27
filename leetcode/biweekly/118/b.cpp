class Solution {
public:
    long long maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        using ll = long long;
        ranges::sort(hBars);
        ranges::sort(vBars);
        ll h = 1, v = 1, cnt = 1;
        for (int i = 0; i < hBars.size() - 1; i++) {
            if (hBars[i] + 1 == hBars[i + 1]) cnt++;
            else h = max(h, cnt + 1), cnt = 1;
        }
        h = max(h, cnt + 1);
        cnt = 1;
        for (int i = 0; i < vBars.size() - 1; i++) {
            if (vBars[i] + 1 == vBars[i + 1]) cnt++;
            else v = max(v, cnt + 1), cnt = 1;
        }
        v = max(v, cnt + 1);
        // cout << h << " " << v << endl;
        ll ans = min(h, v);
        return ans * ans;
    }
};
