#include <bits/stdc++.h>
using namespace std;

struct Cmd {
    int a, b;
    string d;
};

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<Cmd> cmds(n);
    for (auto &c : cmds) cin >> c.a >> c.b >> c.d;

    int q;
    cin >> q;

    sort(cmds.begin(), cmds.end(), [](const Cmd &x, const Cmd &y) {
        return x.a != y.a ? x.a < y.a : x.b < y.b;
    });

    map<pair<int,int>, int> grid;   // position -> cube
    unordered_map<int, pair<int,int>> pos; // cube -> position

    auto place = [&](int cube, pair<int,int> p) {
        auto it = grid.find(p);
        if (it != grid.end()) pos.erase(it->second);   // replaced cube disappears
        auto old = pos.find(cube);
        if (old != pos.end()) grid.erase(old->second); // cube moved
        grid[p] = cube;
        pos[cube] = p;
    };

    auto delta = [](const string &d) -> pair<int,int> {
        if (d == "top" || d == "up") return {0, 1};
        if (d == "down")             return {0, -1};
        if (d == "left")             return {-1, 0};
        return {1, 0}; // right
    };

    if (n > 0) place(cmds[0].a, {0, 0}); // root

    vector<bool> done(n, false);
    int remaining = n;
    while (remaining > 0) {
        bool progress = false;
        for (int i = 0; i < n; i++) {
            if (done[i]) continue;
            auto it = pos.find(cmds[i].a);
            if (it == pos.end()) continue; // parent not placed yet, defer
            auto dl = delta(cmds[i].d);
            place(cmds[i].b, {it->second.first + dl.first,
                              it->second.second + dl.second});
            done[i] = true;
            remaining--;
            progress = true;
        }
        if (!progress) break; // safety: disconnected input
    }

    auto it = pos.find(q);
    if (it == pos.end()) {
        cout << "-1 -1 -1 -1\n";
        return 0;
    }

    int x = it->second.first, y = it->second.second;
    auto get = [&](int dx, int dy) {
        auto f = grid.find({x + dx, y + dy});
        return f == grid.end() ? -1 : f->second;
    };

    cout << get(0, 1) << " " << get(0, -1) << " "
         << get(-1, 0) << " " << get(1, 0) << "\n";
    return 0;
}