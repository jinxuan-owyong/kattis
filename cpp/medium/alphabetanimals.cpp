// Alphabet Animals
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string target, next;
    int n;
    cin >> target >> n;

    unordered_map<char, list<string>> words;
    for (int i = 0; i < n; ++i) {
        cin >> next;
        if (words.find(next[0]) != words.end()) {
            words[next[0]].push_back(next);
        } else {
            list<string> temp = {next};
            words[next[0]] = temp;
        }
    }

    char req = *(target.end() - 1);
    if (words.find(req) == words.end()) {  // no words to play
        cout << '?';
        return 0;
    }

    bool printed = false;
    for (auto& next : words[req]) {  // find word that eliminates next player
        char req_next = *(next.end() - 1);
        if (words.find(req_next) == words.end() ||  // req != req_next
            (req == req_next && words[req].size() == 1)) {
            cout << next + "!";
            printed = true;
            break;
        }
    }

    if (!printed) {
        cout << words[req].front();
    }

    return 0;
}
