#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<ll> b(n + 1);
    for (int i = 1; i <= n; i++) cin >> b[i];

    vector<array<ll, 2>> pre(n + 1);
    pre[0] = {0, 0};

    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1];
        pre[i][i & 1] ^= b[i];
    }

    const int INF = n + 2;

    vector<int> g(n + 2, INF);

    unordered_map<ll, int> pos[2];
    pos[0].reserve(n * 2);
    pos[1].reserve(n * 2);

    for (int i = n; i >= 1; i--) {
        pos[0][pre[i][0]] = i;
        pos[1][pre[i][1]] = i;

        int p = i & 1;
        ll need = pre[i - 1][p];

        auto it = pos[p].find(need);
        if (it != pos[p].end()) {
            g[i] = it->second;
        }
    }

    vector<int> f(n + 3, INF);
    for (int i = n; i >= 1; i--) {
        f[i] = min(g[i], f[i + 1]);
    }

    int LOG = 1;
    while ((1 << LOG) <= n + 1) LOG++;

    vector<vector<int>> jump(LOG, vector<int>(n + 3, INF));

    for (int i = 1; i <= n + 1; i++) {
        if (f[i] <= n) jump[0][i] = f[i] + 1;
        else jump[0][i] = INF;
    }

    for (int k = 1; k < LOG; k++) {
        for (int i = 1; i <= n + 1; i++) {
            int mid = jump[k - 1][i];
            if (mid <= n + 1) jump[k][i] = jump[k - 1][mid];
            else jump[k][i] = INF;
        }
    }

    while (q--) {
        int L, R;
        cin >> L >> R;

        int ans = 0;
        int cur = L;

        for (int k = LOG - 1; k >= 0; k--) {
            int nxt = jump[k][cur];
            if (nxt <= R + 1) {
                ans += 1 << k;
                cur = nxt;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}