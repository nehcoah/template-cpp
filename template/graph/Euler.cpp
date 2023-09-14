//
// Created by Nehcoah on 2023/9/14.
//

#include <vector>
#include <unordered_map>
#include <iostream>
#include <set>

using namespace std;

// 通过图中所有边恰好一次且行遍所有顶点的通路称为欧拉通路；
// 通过图中所有边恰好一次且行遍所有顶点的回路称为欧拉回路；
// 具有欧拉回路的无向图称为欧拉图；
// 具有欧拉通路但不具有欧拉回路的无向图称为半欧拉图。


// Euler Path
// Hierholzer Algorithm
// Leetcode.332
// https://leetcode.cn/problems/reconstruct-itinerary/solutions/389885/zhong-xin-an-pai-xing-cheng-by-leetcode-solution/
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> mp;
        for (auto &t : tickets) {
            mp[t[0]].emplace(t[1]);
        }
        vector<string> ans;

        auto dfs = [&](auto self, const string &cur) -> void {
            while (mp.count(cur) && mp[cur].size() > 0) {
                string tmp = *mp[cur].begin();
                mp[cur].erase(mp[cur].begin());
                self(self, move(tmp));
            }
            ans.emplace_back(cur);
        };

        dfs(dfs, "JFK");
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
