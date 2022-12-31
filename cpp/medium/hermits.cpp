// Hermits
#include <climits>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main(void) {
    int N, M;
    cin >> N;
    vector<int> weights(N + 1);
    for (int i = 1; i < N + 1; ++i) cin >> weights[i];
    cin >> M;
    vector<list<int>> adj_list(N + 1, list<int>());
    for (int i = 0; i < M; ++i) {
        int e1, e2;
        cin >> e1 >> e2;
        adj_list[e1].push_back(e2);
        adj_list[e2].push_back(e1);
    }

    int num_people = INT_MAX;
    int street = INT_MAX;
    for (int i = 1; i < N + 1; ++i) {
        int sum = weights[i];
        for (auto& st : adj_list[i]) {
            sum += weights[st];
        }
        if (sum < num_people) {
            num_people = sum;
            street = i;
        } else if (sum == num_people && i < street) {
            street = i;
        }
    }
    cout << street;
    return 0;
}
