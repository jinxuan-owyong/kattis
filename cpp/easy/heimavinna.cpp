// Homework
#include <bits/stdc++.h>

using namespace std;

int main(void) {
    string problems;
    getline(cin, problems);
    istringstream iss(problems);
    int count = 0;
    while (!iss.eof()) {
        string p;
        getline(iss, p, ';');
        if (p.find("-") == string::npos) {
            ++count;
        } else {
            string first, second;
            istringstream temp(p);
            getline(temp, first, '-');
            getline(temp, second);
            count += stoi(second) - stoi(first) + 1;
        }
    }
    cout << count;
    return 0;
}
