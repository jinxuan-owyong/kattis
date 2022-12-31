// Build Dependencies
#include <bits/stdc++.h>
using namespace std;

int N, id = 0;
vector<vector<int>> adj;  // adjacency list of graph
vector<bool> visited;
vector<int> ans;
unordered_map<string, int> fileId;
unordered_map<int, string> filename;

int getId(string target) {
    if (fileId.find(target) == fileId.end()) {
        filename[id] = target;
        fileId[target] = id++;
    }
    return fileId[target];
}

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
    ans.push_back(v);
}

void topological_sort(int s) {
    visited.assign(N, false);
    ans.clear();
    dfs(s);
    reverse(ans.begin(), ans.end());
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    cin.ignore();
    adj.assign(N, {});

    for (int i = 0; i < N; ++i) {
        string file, name, deps;
        getline(cin, file);
        istringstream is(file);
        getline(is, name, ':');
        while (is >> deps) {
            adj[getId(deps)].push_back(getId(name));
        }
    }

    string required;
    cin >> required;
    topological_sort(getId(required));
    for (auto& v : ans) cout << filename[v] << '\n';

    return 0;
}
