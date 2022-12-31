// 99 Problems
#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q, temp;
    cin >> N >> Q;
    multiset<int> difficulties;
    for (int i = 0; i < N; ++i) {
        cin >> temp;
        difficulties.insert(temp);
    }
    set<int> discarded;
    for (int i = 0; i < Q; ++i) {
        int T, D;
        cin >> T >> D;
        multiset<int>::iterator dit;
        if (T == 1) {
            dit = difficulties.upper_bound(D);
        }
        if (T == 2) {
            dit = difficulties.lower_bound(D);                           // returns >=
            if (dit == difficulties.end() && difficulties.size() > 0) {  // [6], Q = 7
                --dit;
            } else if (*dit > D && *dit != D) {     // dit <= D
                if (dit == difficulties.begin()) {  // [6], Q = 5
                    dit = difficulties.end();
                } else {
                    --dit;
                }
            }
        }
        if (dit != difficulties.end()) {
            cout << *dit << '\n';
            discarded.insert(*dit);
            difficulties.erase(dit);
        } else {
            cout << "-1\n";
        }
    }
    return 0;
}
