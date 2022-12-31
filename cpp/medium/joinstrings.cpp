// Join Strings
#include <iostream>
#include <list>
#include <vector>

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;
    std::vector<std::list<std::string>> collection;
    collection.push_back({""});  // 1-based indexing
    for (int i = 0; i < N; ++i) {
        std::string temp;
        std::cin >> temp;
        collection.push_back({temp});
    }

    for (int i = 1; i < N; ++i) {  // iterate (N - 1) times
        int a, b;
        std::cin >> a >> b;
        auto ait = collection.begin() + a;
        auto bit = collection.begin() + b;
        ait->splice(ait->end(), *bit);
    }

    for (auto& l : collection) {  // output result
        for (auto& s : l) {
            std::cout << s;
        }
    }

    return 0;
}
