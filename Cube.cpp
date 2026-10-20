#include <bits/stdc++.h>
using namespace std;

struct V { int x, y, z; bool operator<(const V& o) const { return tie(x,y,z) < tie(o.x,o.y,o.z); } };
struct St { V p, n; };

static V rot(V v, int axis, int k) {
    while (k--) {
        if (axis == 0)      { int y = -v.z, z = v.y;  v.y = y; v.z = z; }
        else if (axis == 1) { int x = v.z,  z = -v.x; v.x = x; v.z = z; }
        else                { int x = -v.y, y = v.x;  v.x = x; v.y = y; }
    }
    return v;
}

static string canon(const string& s) {
    int m[128]; memset(m, -1, sizeof m);
    int cnt = 0; string out(24, 0);
    for (int i = 0; i < 24; i++) {
        if (m[(int)s[i]] < 0) m[(int)s[i]] = cnt++;
        out[i] = 'A' + m[(int)s[i]];
    }
    return out;
}

int main() {
    // Sticker geometry: index 1..24 -> (cubie position, face normal); x: L-,R+  y: D-,U+  z: B-,F+
    V U{0,1,0}, D{0,-1,0}, F{0,0,1}, B{0,0,-1}, L{-1,0,0}, R{1,0,0};
    St st[24] = {
        {{-1,1,-1},U},{{1,1,-1},U},{{-1,1,1},U},{{1,1,1},U},          // 1-4   Top
        {{-1,1,1},F},{{1,1,1},F},{{-1,-1,1},F},{{1,-1,1},F},          // 5-8   Front
        {{-1,-1,1},D},{{1,-1,1},D},{{-1,-1,-1},D},{{1,-1,-1},D},      // 9-12  Down
        {{-1,-1,-1},B},{{1,-1,-1},B},{{-1,1,-1},B},{{1,1,-1},B},      // 13-16 Back
        {{-1,1,-1},L},{{-1,1,1},L},{{-1,-1,-1},L},{{-1,-1,1},L},      // 17-20 Left
        {{1,1,1},R},{{1,1,-1},R},{{1,-1,1},R},{{1,-1,-1},R}          // 21-24 Right
    };
    map<pair<V,V>, int> lookup;
    auto key = [](const V& a, const V& b) { return make_pair(a, b); };
    for (int i = 0; i < 24; i++) lookup[key(st[i].p, st[i].n)] = i;

    // 18 moves: 3 axes x 2 layers x {90, 180, 270}
    vector<array<int,24>> moves;
    for (int axis = 0; axis < 3; axis++)
        for (int layer = -1; layer <= 1; layer += 2)
            for (int k = 1; k <= 3; k++) {
                array<int,24> perm;
                for (int i = 0; i < 24; i++) {
                    int c = axis == 0 ? st[i].p.x : axis == 1 ? st[i].p.y : st[i].p.z;
                    perm[i] = (c == layer) ? lookup[key(rot(st[i].p, axis, k), rot(st[i].n, axis, k))] : i;
                }
                moves.push_back(perm);
            }

    // BFS (depth <= 4) from the solved cube over colour-pattern canonical states
    string solved;
    for (int i = 0; i < 24; i++) solved += char('A' + i / 4);
    unordered_set<string> seen{solved};
    vector<string> frontier{solved};
    for (int d = 0; d < 4; d++) {
        vector<string> nxt;
        for (auto& s : frontier)
            for (auto& m : moves) {
                string t(24, 0);
                for (int i = 0; i < 24; i++) t[m[i]] = s[i];
                t = canon(t);
                if (seen.insert(t).second) nxt.push_back(t);
            }
        frontier = move(nxt);
    }

    // Input
    string c;
    for (int i = 0; i < 24; i++) { char ch; cin >> ch; c += ch; }

    int corners[8][3] = {{3,5,18},{4,6,21},{7,9,20},{8,10,23},
                         {1,15,17},{2,16,22},{11,13,19},{12,14,24}};
    string ans;
    for (auto& cr : corners) {
        int a = cr[0]-1, b = cr[1]-1, d = cr[2]-1;
        int cyc[2][3] = {{a,b,d},{a,d,b}};
        for (auto& q : cyc) {
            string t = c;
            t[q[0]] = c[q[1]]; t[q[1]] = c[q[2]]; t[q[2]] = c[q[0]];
            if (seen.count(canon(t))) {
                ans = string{c[a], c[b], c[d]};
                sort(ans.begin(), ans.end());
                cout << ans << "\n";
                return 0;
            }
        }
    }
    return 0;
}