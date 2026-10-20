#include <bits/stdc++.h>
using namespace std;

struct Edge { int to, cap, cost; };
vector<Edge> E;
vector<vector<int>> g;

void addEdge(int u, int v, int cap, int cost) {
    g[u].push_back(E.size()); E.push_back({v, cap, cost});
    g[v].push_back(E.size()); E.push_back({u, 0, -cost});
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> roads(m);
    int mx = n;
    for (auto &r : roads) {
        cin >> r.first >> r.second;
        mx = max({mx, r.first, r.second});
    }
    int s1, s2, t;
    cin >> s1 >> s2 >> t;
    mx = max({mx, s1, s2, t});

    int V = mx + 1;                // labels may exceed N, so size by max label
    int S = 2 * V, T = 2 * V + 1;
    g.assign(2 * V + 2, {});

    auto in  = [](int v) { return 2 * v; };
    auto out = [](int v) { return 2 * v + 1; };

    for (int v = 0; v < V; v++) {
        if (v == t) addEdge(in(v), out(v), 2, 0);  // outpost: both scouts, free
        else        addEdge(in(v), out(v), 1, 1);  // normal town: used once, cost 1
    }
    for (auto &r : roads) {
        addEdge(out(r.first),  in(r.second), 1, 0);
        addEdge(out(r.second), in(r.first),  1, 0);
    }
    addEdge(S, in(s1), 1, 0);
    addEdge(S, in(s2), 1, 0);
    addEdge(out(t), T, 2, 0);

    int flow = 0, cost = 0;
    const int INF = 1e9;
    while (flow < 2) {
        vector<int> dist(g.size(), INF), pe(g.size(), -1);
        vector<bool> inq(g.size(), false);
        deque<int> q;
        dist[S] = 0; q.push_back(S);
        while (!q.empty()) {
            int u = q.front(); q.pop_front(); inq[u] = false;
            for (int id : g[u]) {
                if (E[id].cap > 0 && dist[u] + E[id].cost < dist[E[id].to]) {
                    dist[E[id].to] = dist[u] + E[id].cost;
                    pe[E[id].to] = id;
                    if (!inq[E[id].to]) { inq[E[id].to] = true; q.push_back(E[id].to); }
                }
            }
        }
        if (dist[T] == INF) break;
        // augment by 1 unit
        for (int v = T; v != S; v = E[pe[v] ^ 1].to) {
            E[pe[v]].cap--;
            E[pe[v] ^ 1].cap++;
        }
        flow++;
        cost += dist[T];
    }

    if (flow < 2) cout << "Impossible\n";
    else cout << cost << "\n";
    return 0;
}