// https://leetcode.cn/problems/robot-collisions/

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = healths.size();
        int idx[n];
        iota(idx, idx + n, 0);
        sort(idx, idx + n, [&](int a, int b){return positions[a] < positions[b];});
        unordered_map<int, int> mp;
        stack<pair<int, int>> stk;
        int pre = -1;
        for (int j = 0; j < n; j++) {
            int i = idx[j], p = positions[i], h = healths[i];
            // cout << p << " " << h << " " << pre << " " << directions[i] << endl;
            if (directions[i] == 'L') {
                bool flag = false;
                while (!stk.empty()){
                    if (stk.top().second == h) {
                        flag = true;
                        stk.pop();
                        break;
                    }
                    else if (stk.top().second < h) stk.pop(), h -= 1;
                    else {
                        stk.top().second -= 1;
                        break;
                    }
                }
                if (stk.empty() && !flag) mp[p] = h;
            } else {
                stk.emplace(p, h);
            }
        }
        while (!stk.empty()){
            auto [p, h] = stk.top(); stk.pop();
            mp[p] = h;
        }
        vector<int> ans;
        for (int p : positions) if (mp.count(p)) ans.push_back(mp[p]);
        return ans;
    }
};
