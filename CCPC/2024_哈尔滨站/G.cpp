#include <bits/stdc++.h>
using namespace std;
#define ve vector
using ll = long long;
using ull = unsigned long long;
using sr = string;
using db = double;
using dll = double long;
const int MOD=998244353;
const ll INF=1e18;
const int DIR[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
int T;
void solve() {
    int n, m, k;
    cin>>n>>m>>k;
    ve<ve<int>> adj(n + 1);
    ve<bool> busy(n + 1, false);
    ve<bool> intime(n + 1, false);
    for (int i = 0; i < k; i++) {
        int a;
        cin>>a;
        busy[a] = true;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int id = -1;
    for (int i = 1; i <= n; i++) {
        if (!busy[i]) {
            id = i;
            break;
        }
    }
    if (id == -1) {
        cout << "No\n";
        return;
    }
    queue<int> q;
    intime[id] = true;
    q.push(id);
    ve<pair<int, ve<int>>> op;
    ve<int> fint;
    for (int u : adj[id]) {
        if (!intime[u]) {
            fint.push_back(u);
            intime[u] = true;
        }
    }
    if (!fint.empty()) {
        op.push_back({id, fint});
        for (int p : fint) {
            if (!busy[p]) {
                q.push(p);
            }
        }
    } else {
        op.push_back({id, {}});
    }
    while (!q.empty()) {
        int init = q.front();
        q.pop();
        if (busy[init]) continue;
        ve<int> invites;
        for (int u : adj[init]) {
            if (!intime[u]) {
                invites.push_back(u);
                intime[u] = true;
            }
        }
        if (!invites.empty()) {
            op.push_back({init, invites});
            for (int p : invites) {
                if (!busy[p]) {
                    q.push(p);
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!intime[i]) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
    cout << op.size() << "\n";
    for (auto& ops : op) {
        cout << ops.first << " " << ops.second.size();
        for (int p : ops.second) {
            cout<<" "<<p;
        }
        cout<<"\n";
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    T = 1;
    while(T--) solve();
}