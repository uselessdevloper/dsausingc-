#include <bits/stdc++.h>
using namespace std;

int n, m, T;
bool allowedC[27][26][26], viable[27][26][26], vis[26][26];
char g[26][26];
int cnt = 0;
string found, cur;
const int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};

void dfs(int t, int r, int c) {
    if (cnt >= 2) return;
    vis[r][c] = true;
    cur.push_back(g[r][c]);
    if (t == T) {
        cnt++;
        found = cur;
    } else {
        for (int k = 0; k < 4 && cnt < 2; k++) {
            int nr = r + dr[k], nc = c + dc[k];
            if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
            if (vis[nr][nc] || !viable[t + 1][nr][nc]) continue;
            dfs(t + 1, nr, nc);
        }
    }
    cur.pop_back();
    vis[r][c] = false;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> g[i][j];

    int I;
    cin >> T >> I;

    for (int t = 1; t <= T; t++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) allowedC[t][i][j] = true;

    while (I--) {
        int t, x1, y1, x2, y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        if (t < 1 || t > T) continue;
        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);
        for (int i = max(x1, 1); i <= min(x2, n); i++)
            for (int j = max(y1, 1); j <= min(y2, m); j++)
                allowedC[t][i - 1][j - 1] = false;
    }

    // forward pass
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) viable[1][i][j] = allowedC[1][i][j];
    for (int t = 2; t <= T; t++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                bool ok = false;
                if (allowedC[t][i][j])
                    for (int k = 0; k < 4 && !ok; k++) {
                        int a = i + dr[k], b = j + dc[k];
                        if (a >= 0 && b >= 0 && a < n && b < m && viable[t - 1][a][b]) ok = true;
                    }
                viable[t][i][j] = ok;
            }
    // backward pass
    for (int t = T - 1; t >= 1; t--)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                bool ok = false;
                if (viable[t][i][j])
                    for (int k = 0; k < 4 && !ok; k++) {
                        int a = i + dr[k], b = j + dc[k];
                        if (a >= 0 && b >= 0 && a < n && b < m && viable[t + 1][a][b]) ok = true;
                    }
                viable[t][i][j] = ok;
            }

    for (int i = 0; i < n && cnt < 2; i++)
        for (int j = 0; j < m && cnt < 2; j++)
            if (viable[1][i][j]) dfs(1, i, j);

    if (cnt == 1) cout << found << "\n";
    else cout << "Not enough clues\n";
    return 0;
}