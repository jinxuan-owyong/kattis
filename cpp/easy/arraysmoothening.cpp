// Array Smoothening
#include <iostream>
#include <queue>
#include <unordered_map>

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, K;
    std::cin >> N >> K;
    std::unordered_map<int, int> count;

    for (int i = 0; i < N; ++i) {
        int el;
        std::cin >> el;
        if (count.find(el) == count.end()) {  // not in countay
            count.insert(std::pair(el, 1));
        } else {  // already exists
            ++count[el];
        }
    }

    auto cmp = [](std::pair<int, int> a, std::pair<int, int> b) {
        if (a.second == b.second) {
            return a.first > b.first;  // sort by value, smaller has priority
        }
        return a.second < b.second;  // sort by number of occurrences, larger has priority
    };
    // binary max heap
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)>
        values(cmp);
    for (auto& p : count) values.push(p);

    // remove elements 1 by 1, the smaller value will be on top
    if (K != 0) {
        for (int i = 0; i < K; ++i) {
            auto el = values.top();
            values.pop();
            values.push(std::pair(el.first, el.second - 1));
        }
    }

    // output maximum occurrence
    std::cout << values.top().second;
    return 0;
}
