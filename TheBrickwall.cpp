#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> id(n, vector<int>(n, -1));
    vector<vector<char>> tp(n, vector<char>(n, 'R'));
    int brick = 0;

    for (int r = 0; r < n; r++) {
        string s;
        cin >> s;
        int c = 0;
        size_t i = 0;
        while (i < s.size() && c < n) {
            int len = 0;
            while (i < s.size() && isdigit((unsigned char)s[i]))
                len = len * 10 + (s[i++] - '0');
            char t = s[i++];
            for (int k = 0; k < len && c < n; k++, c++) {
                id[r][c] = brick;
                tp[r][c] = t;
            }
            brick++;
        }
    }

    const int INF = 1e9;
    vector<vector<int>> dist(n, vector<int>(n, INF));
    deque<pair<int,int>> dq;

    for (int r = 0; r < n; r++)
        for (int c = 0; c < n; c++)
            if (tp[r][c] == 'S') {
                dist[r][c] = 0;
                dq.push_back({r, c});
            }

    int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};

    while (!dq.empty()) {
        auto [r, c] = dq.front();
        dq.pop_front();
        int d = dist[r][c];
        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k], nc = c + dc[k];
            if (nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
            char t = tp[nr][nc];
            if (t == 'R') continue;
            int w;
            if (id[nr][nc] == id[r][c]) w = 0;   // same brick, already broken
            else if (t == 'G') w = 1;            // new green brick
            else w = 0;                          // S or D
            if (d + w < dist[nr][nc]) {
                dist[nr][nc] = d + w;
                if (w == 0) dq.push_front({nr, nc});
                else dq.push_back({nr, nc});
            }
        }
    }

    int ans = INF;
    for (int r = 0; r < n; r++)
        for (int c = 0; c < n; c++)
            if (tp[r][c] == 'D') ans = min(ans, dist[r][c]);

    cout << (ans == INF ? -1 : ans) << "\n";
    return 0;
}