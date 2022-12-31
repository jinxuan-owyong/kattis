// Building Highways
// Minimum Spanning Tree, with large V and E
// Alternatively, since input is a complete graph,
// connect all vertices to the one with smallest A
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

class UnionFind {  // OOP style
private:
    vi p, rank, setSize;  // vi p is the key part
    int numSets;

public:
    UnionFind(int N) {
        p.assign(N, 0);
        for (int i = 0; i < N; ++i) p[i] = i;
        rank.assign(N, 0);     // optional speedup
        setSize.assign(N, 1);  // optional feature
        numSets = N;           // optional feature
    }

    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

    int numDisjointSets() { return numSets; }             // optional
    int sizeOfSet(int i) { return setSize[findSet(i)]; }  // optional

    void unionSet(int i, int j) {
        if (isSameSet(i, j))
            return;                          // i and j are in same set
        int x = findSet(i), y = findSet(j);  // find both rep items
        if (rank[x] > rank[y])
            swap(x, y);  // keep x 'shorter' than y
        p[x] = y;        // set x under y
        if (rank[x] == rank[y])
            ++rank[y];             // optional speedup
        setSize[y] += setSize[x];  // combine set sizes at y
        --numSets;                 // a union reduces numSets
    }
};

struct City {
    int v, a;
    City() : v(-1), a(-1) {}
    City(int v_, int a_) {
        v = v_;
        a = a_;
    }
    bool operator<(City& c) {
        if (a == c.a)
            return v < c.v;
        return a < c.a;
    }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<City> levels(N);  // problematic levels
    UnionFind cities(N);
    for (int i = 0; i < N; ++i) {  // O(N)
        int p;
        cin >> p;
        levels[i] = {i, p};
    }
    // sort problematic levels to get the smallest first
    sort(levels.begin(), levels.end());

    // find MST using Kruskal's Algorithm
    ll sum = 0;
    // access edges as required instead of generating large edge list
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < i; ++j) {  // invariant i != j
            auto& [vi, ai] = levels[i];
            auto& [vj, aj] = levels[j];
            if (cities.isSameSet(vi, vj))
                break;  // since cycle exists and vj will never be part of the MST
            cities.unionSet(vi, vj);
            sum += ai + aj;
        }
    }

    cout << sum << '\n';
    return 0;
}
