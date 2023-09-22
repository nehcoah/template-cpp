// https://leetcode.cn/problems/design-graph-with-shortest-path-calculator/description/

class Graph {
    vector<vector<pair<int, int>>> adj;

    int dijkstra(vector<vector<pair<int, int>>> &g, int start, int end) {
      vector<int> dist(g.size(), INT_MAX);
      dist[start] = 0;
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
      pq.emplace(0, start);
      while (!pq.empty()) {
          auto[d, x] = pq.top();
          pq.pop();
          if (d > dist[x]) continue;
          for (auto& [y, wt] : g[x]) {
              int new_d = dist[x] + wt;
              if (new_d < dist[y]) {
                  dist[y] = new_d;
                  pq.emplace(new_d, y);
              }
          }
      }
      return dist[end] == INT_MAX ? -1 : dist[end];
  }
public:
    Graph(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        for (auto &e : edges) adj[e[0]].emplace_back(e[1], e[2]);
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].emplace_back(edge[1], edge[2]);
    }
    
    int shortestPath(int node1, int node2) {
        return dijkstra(adj, node1, node2);
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
