// Single source shortest path, safe path
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int INF = 1e9;
vector<vii> AL;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    cin >> TC;
    while (TC--) {
        int V;
        cin >> V;
        AL.assign(V, vii());
        for (int i = 0; i < V; ++i) {
            int X, v, w;
            cin >> X;
            while (X--) {
                cin >> v >> w;
                AL[i].emplace_back(v, w);
            }
        }

        int Q, s, t, k;
        cin >> Q;
        while (Q--) {
            cin >> s >> t >> k;
            // Bellman-Ford Algorithm
            vi dist(V, INF);  // INF = 1e9 here
            dist[s] = 0;
            vi prev = dist;
            for (int x = 1; x < k; ++x) {      // length
                for (int i = 0; i < V; ++i) {  // total O(V*E)
                    if (prev[i] == INF)
                        continue;
                    bool modified = false;         // optimization
                    for (int u = 0; u < V; ++u) {  // these two loops = O(E)
                        if (prev[u] == INF)        // important check
                            continue;
                        for (auto &[v, w] : AL[u]) {  // C++17 style
                            if (prev[u] + w >= dist[v])
                                continue;           // not improving, skip
                            dist[v] = prev[u] + w;  // relax operation
                            modified = true;        // optimization
                        }
                    }
                    if (!modified)
                        break;  // optimization
                }
                prev = dist;
            }

            if (dist[t] == INF)
                cout << "-1\n";
            else if (k == 1)  // implies s == t, dist[t] != INF
                cout << "0\n";
            else
                cout << dist[t] << '\n';
        }
    }
    return 0;
}
