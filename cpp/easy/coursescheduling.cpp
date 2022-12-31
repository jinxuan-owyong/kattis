// Course Scheduling
#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int N;
    cin >> N;
    map<string, int> count;
    unordered_map<string, set<string>> enrolments;
    for (int i = 0; i < N; ++i) {
        string first, last, code;
        cin >> first >> last >> code;
        if (enrolments.find(code) == enrolments.end()) {  // no students registered
            enrolments[code] = {first + last};
            count[code] = 1;
            continue;
        }
        if (enrolments[code].find(first + last) == enrolments[code].end()) {  // course exists, name not registered
            enrolments[code].insert(first + last);
            ++count[code];
            continue;
        }  // pass if already registered
    }
    for (auto& [code, students] : count) {
        cout << code << ' ' << students << '\n';
    }
    return 0;
}
