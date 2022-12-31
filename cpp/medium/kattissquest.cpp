// Kattis's Quest
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    map<int, priority_queue<int>> quests;

    while (N--) {
        string inst;
        cin >> inst;
        if (inst == "add") {
            int E, G;
            cin >> E >> G;
            if (quests.find(E) != quests.end()) {
                quests[E].push(G);
            } else {
                priority_queue<int> pq;
                pq.push(G);
                quests[E] = pq;
            }
        }
        if (inst == "query") {
            int X;
            long long gold = 0;
            cin >> X;
            while (true) {
                auto it = quests.upper_bound(X);
                if (it == quests.begin())  // insufficient energy
                    break;
                --it;
                gold += it->second.top();  // gold earned
                it->second.pop();
                X -= it->first;  // energy consumed
                if (it->second.size() == 0)
                    quests.erase(it);
            }
            cout << gold << '\n';
        }
    }
    return 0;
}
