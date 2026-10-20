#include <bits/stdc++.h>
using namespace std;

static bool readLine(string &s) {
    while (getline(cin, s)) {
        for (char &ch : s) if (ch == ',' || ch == '\r') ch = ' ';
        if (s.find_first_not_of(' ') != string::npos) return true; // skip blank lines
    }
    return false;
}

int main() {
    string line;
    readLine(line);
    int n = stoi(line);

    map<string, set<string>> adj;
    for (int i = 0; i < n; i++) {
        readLine(line);
        stringstream ss(line);
        string src, x;
        ss >> src;
        adj[src];                       // make sure the node exists
        while (ss >> x) {
            adj[src].insert(x);
            adj[x].insert(src);         // connections are bidirectional
        }
    }

    readLine(line);
    int q = stoi(line);
    vector<array<string, 3>> queries(q);
    for (int i = 0; i < q; i++) {
        readLine(line);
        stringstream ss(line);
        ss >> queries[i][0] >> queries[i][1] >> queries[i][2];
    }

    readLine(line);
    int r = stoi(line);
    map<string, set<string>> restrictedFor;
    for (int i = 0; i < r; i++) {
        readLine(line);
        stringstream ss(line);
        string src, x;
        ss >> src;
        while (ss >> x) restrictedFor[src].insert(x);
    }

    // Queries are processed in order, because connect/disconnect change the graph.
    for (auto &qu : queries) {
        const string &a = qu[0], &op = qu[1], &b = qu[2];
        if (op == "connects") {
            adj[a].insert(b);
            adj[b].insert(a);
        } else if (op == "disconnects") {
            adj[a].erase(b);
            adj[b].erase(a);
        } else { // "to"
            const set<string> &blocked = restrictedFor[a];
            bool ok = false;
            if (a == b) {
                ok = true;
            } else if (!blocked.count(b)) {
                set<string> vis{a};
                queue<string> bq;
                bq.push(a);
                while (!bq.empty() && !ok) {
                    string u = bq.front(); bq.pop();
                    for (const string &v : adj[u]) {
                        if (vis.count(v) || blocked.count(v)) continue;
                        if (v == b) { ok = true; break; }
                        vis.insert(v);
                        bq.push(v);
                    }
                }
            }
            cout << (ok ? "yes" : "no") << "\n";
        }
    }
    return 0;
}