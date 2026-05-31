#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int n;
vector<vector<int>> g;

struct Solver {
    int root;
    vector<vector<int>> ch;
    vector<int> parent;
    vector<int> mn;
    vector<char> isInternal;
    vector<int> memo;
    int lim;

    Solver(int r) : root(r) {
        ch.assign(n + 1, {});
        parent.assign(n + 1, 0);
        mn.assign(n + 1, INF);
        isInternal.assign(n + 1, 0);
        memo.assign(n + 1, -2);
        buildRootedTree();
    }

    void buildRootedTree() {
        vector<int> st;
        st.push_back(root);
        parent[root] = -1;

        while (!st.empty()) {
            int u = st.back();
            st.pop_back();

            for (int v : g[u]) {
                if (v == parent[u]) continue;
                parent[v] = u;
                ch[u].push_back(v);
                st.push_back(v);
            }
        }

        for (int u = 1; u <= n; u++) {
            sort(ch[u].begin(), ch[u].end());
            if (!ch[u].empty()) {
                isInternal[u] = 1;
                mn[u] = ch[u][0];
            }
        }
    }

    int reach(int u) {
        int &res = memo[u];
        if (res != -2) return res;

        if (!isInternal[u]) return res = -1;

        if (mn[u] < lim) {
            return res = mn[u];
        }

        int best = -1;
        for (int v : ch[u]) {
            if (isInternal[v]) {
                best = max(best, reach(v));
            }
        }
        return res = best;
    }

    vector<int> solve() {
        if (n == 1) return {1};

        vector<int> rootBatch = ch[root];
        rootBatch.push_back(root);
        sort(rootBatch.begin(), rootBatch.end());

        vector<int> suffix = rootBatch;
        lim = rootBatch[0];

        vector<vector<int>> leftGroups;

        vector<char> available(n + 1, 0);

        auto makeAvailable = [&](int u) {
            if (isInternal[u]) available[u] = 1;
        };

        for (int v : ch[root]) {
            makeAvailable(v);
        }

        while (lim > 1) {
            fill(memo.begin(), memo.end(), -2);

            int M = -1;
            for (int u = 1; u <= n; u++) {
                if (available[u]) {
                    M = max(M, reach(u));
                }
            }

            if (M == -1) break;

            struct Item {
                int key;
                int type; // 0: normal right-only, 1: terminating event
                int u;

                bool operator<(const Item &other) const {
                    if (key != other.key) return key > other.key;
                    if (type != other.type) return type > other.type;
                    return u > other.u;
                }
            };

            priority_queue<Item> pq;
            vector<char> inq(n + 1, 0);

            auto pushIfPossible = [&](int u) {
                if (!available[u] || inq[u]) return;

                if (mn[u] >= lim) {
                    // right-only batch
                    pq.push({mn[u], 0, u});
                    inq[u] = 1;
                } else if (mn[u] == M) {
                    // this is the event ending this phase
                    int key = 0;
                    for (int x : ch[u]) {
                        if (x > lim) {
                            key = x;
                            break;
                        }
                    }
                    pq.push({key, 1, u});
                    inq[u] = 1;
                }
                // mn[u] < lim && mn[u] != M is blocked in this phase
            };

            for (int u = 1; u <= n; u++) {
                if (available[u]) pushIfPossible(u);
            }

            while (true) {
                Item cur = pq.top();
                pq.pop();

                int u = cur.u;
                if (!available[u]) continue;

                available[u] = 0;

                if (mn[u] < lim) {
                    // terminating event, necessarily mn[u] == M
                    vector<int> leftPart, rightPart;

                    for (int x : ch[u]) {
                        if (x < lim) leftPart.push_back(x);
                        else if (x > lim) rightPart.push_back(x);
                    }

                    sort(leftPart.begin(), leftPart.end());
                    sort(rightPart.begin(), rightPart.end());

                    leftGroups.push_back(leftPart);
                    for (int x : rightPart) suffix.push_back(x);

                    for (int v : ch[u]) {
                        makeAvailable(v);
                        pushIfPossible(v);
                    }

                    lim = M;
                    break;
                } else {
                    // right-only batch
                    for (int x : ch[u]) suffix.push_back(x);

                    for (int v : ch[u]) {
                        makeAvailable(v);
                        pushIfPossible(v);
                    }
                }
            }
        }

        // No more left events. Everything remaining goes to the right.
        struct LastItem {
            int key, u;
            bool operator<(const LastItem &other) const {
                if (key != other.key) return key > other.key;
                return u > other.u;
            }
        };

        priority_queue<LastItem> pq;
        for (int u = 1; u <= n; u++) {
            if (available[u]) pq.push({mn[u], u});
        }

        while (!pq.empty()) {
            auto [key, u] = pq.top();
            pq.pop();

            if (!available[u]) continue;
            available[u] = 0;

            for (int x : ch[u]) suffix.push_back(x);

            for (int v : ch[u]) {
                if (isInternal[v]) {
                    available[v] = 1;
                    pq.push({mn[v], v});
                }
            }
        }

        vector<int> ans;

        for (int i = (int)leftGroups.size() - 1; i >= 0; i--) {
            for (int x : leftGroups[i]) ans.push_back(x);
        }

        for (int x : suffix) ans.push_back(x);

        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    g.assign(n + 1, {});

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    if (n == 1) {
        cout << 1 << '\n';
        return 0;
    }

    vector<int> best;

    for (int r = 1; r <= n; r++) {
        Solver solver(r);
        vector<int> cand = solver.solve();

        if (best.empty() || cand < best) {
            best = cand;
        }
    }

    for (int i = 0; i < n; i++) {
        if (i) cout << ' ';
        cout << best[i];
    }
    cout << '\n';

    return 0;
}