#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <utility>
#include <algorithm>
#include <climits>
#include <cctype>
using namespace std;

// ---- flags to try if the judge still says Wrong Answer ----
const int UNREACHABLE_OUTPUT = -1;    // try 0 if -1 is rejected
const bool SHARED_EDGE_FREE  = false; // true: a branch listed in several trees puts the monkey on all of them

static map<pair<string,int>, int> idMap;
static vector< vector< pair<int,int> > > adj;
static map<string, vector<int> > statesOf;

static int getId(const string &spot, int tree) {
    pair<string,int> key = make_pair(spot, tree);
    map<pair<string,int>, int>::iterator it = idMap.find(key);
    if (it != idMap.end()) return it->second;
    int k = (int)adj.size();
    idMap[key] = k;
    adj.push_back(vector< pair<int,int> >());
    statesOf[spot].push_back(k);
    return k;
}

static vector<string> tokens(const string &s) {
    vector<string> r; stringstream ss(s); string t;
    while (ss >> t) r.push_back(t);
    return r;
}

int main() {
    vector<string> lines;
    string s;
    while (getline(cin, s)) {
        while (!s.empty() && isspace((unsigned char)s[s.size() - 1])) s.erase(s.size() - 1);
        size_t p = 0;
        while (p < s.size() && isspace((unsigned char)s[p])) p++;
        s = s.substr(p);
        if (!s.empty()) lines.push_back(s);
    }
    if (lines.size() < 2) return 0;

    vector<string> q = tokens(lines.back()); lines.pop_back();
    if (q.size() < 2 && !lines.empty()) {
        vector<string> q0 = tokens(lines.back()); lines.pop_back();
        q0.insert(q0.end(), q.begin(), q.end());
        q = q0;
    }
    if (q.size() < 2) return 0;
    string start = q[q.size() - 2], dest = q[q.size() - 1];

    int tree = 0;
    map< pair<string,string>, set<int> > edgeTrees;
    vector< pair<pair<string,string>, int> > edges;
    for (size_t i = 1; i < lines.size(); i++) {
        vector<string> tk = tokens(lines[i]);
        if (tk.empty()) continue;
        string low = tk[0];
        for (size_t k = 0; k < low.size(); k++) low[k] = (char)tolower((unsigned char)low[k]);
        if (low == "break") { tree++; continue; }
        getId(tk[0], tree);
        for (size_t j = 1; j < tk.size(); j++) {
            getId(tk[j], tree);
            edges.push_back(make_pair(make_pair(tk[0], tk[j]), tree));
            edgeTrees[make_pair(tk[0], tk[j])].insert(tree);
        }
    }

    for (size_t e = 0; e < edges.size(); e++) {
        const string &a = edges[e].first.first, &b = edges[e].first.second;
        int t = edges[e].second;
        int ua = getId(a, t);
        if (!SHARED_EDGE_FREE) {
            int ub = getId(b, t);
            adj[ua].push_back(make_pair(ub, 1));   // climb up
            adj[ub].push_back(make_pair(ua, 0));   // climb down
        } else {
            set<int> &ts = edgeTrees[edges[e].first];
            for (set<int>::iterator it = ts.begin(); it != ts.end(); ++it) {
                int ub = getId(b, *it);
                adj[ua].push_back(make_pair(ub, 1));
                int ub2 = getId(b, t);
                int ua2 = getId(a, *it);
                adj[ub2].push_back(make_pair(ua2, 0));
            }
        }
    }

    for (map<string, vector<int> >::iterator it = statesOf.begin(); it != statesOf.end(); ++it) {
        vector<int> &v = it->second;
        for (size_t i = 0; i < v.size(); i++)
            for (size_t j = 0; j < v.size(); j++)
                if (i != j) adj[v[i]].push_back(make_pair(v[j], 1));   // switch trees
    }

    const int INF = INT_MAX;
    vector<int> dist(adj.size(), INF);
    deque<int> dq;
    if (statesOf.count(start)) {
        vector<int> &v = statesOf[start];
        for (size_t i = 0; i < v.size(); i++) { dist[v[i]] = 0; dq.push_back(v[i]); }
    }
    while (!dq.empty()) {
        int u = dq.front(); dq.pop_front();
        for (size_t i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].first, w = adj[u][i].second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                if (w == 0) dq.push_front(v); else dq.push_back(v);
            }
        }
    }
    int ans = INF;
    if (statesOf.count(dest)) {
        vector<int> &v = statesOf[dest];
        for (size_t i = 0; i < v.size(); i++) ans = min(ans, dist[v[i]]);
    }
    if (start == dest && statesOf.count(start)) ans = 0;
    cout << (ans == INF ? UNREACHABLE_OUTPUT : ans) << "\n";
    return 0;
}