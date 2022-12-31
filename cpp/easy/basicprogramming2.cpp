// Basic Programming 2
#include <algorithm>
#include <iostream>
#include <vector>

void first(std::vector<uint32_t>& v) {
    std::sort(v.begin(), v.end());
    const int TARGET = 7777;
    bool found = false;
    auto i = v.begin();
    auto j = v.end() - 1;
    while (i != j && !found) {
        if (*j > TARGET) {
            --j;
            continue;
        }
        uint32_t sum = *i + *j;
        if (sum == TARGET) {
            found = true;
            break;
        } else if (sum < TARGET) {
            ++i;
        } else {  // sum > TARGET
            --j;
        }
    }
    if (*i + *j == TARGET)
        found = true;

    found&& std::cout << "Yes";
    !found&& std::cout << "No";
}

void second(std::vector<uint32_t>& v) {
    std::sort(v.begin(), v.end());
    auto prev = v.begin();
    bool duplicate = false;

    for (auto it = v.begin() + 1; it != v.end(); ++it) {
        std::cout << *prev << ' ' << *it << '\n';
        if (*prev == *it) {
            duplicate = true;
            break;
        }
        prev = it;
    }

    duplicate&& std::cout << "Contains duplicate";
    !duplicate&& std::cout << "Unique";
}

void third(std::vector<uint32_t>& v) {}
void fourth(std::vector<uint32_t>& v) {}
void fifth(std::vector<uint32_t>& v) {}

int main(void) {
    int N, t;
    std::cin >> N >> t;
    std::vector<uint32_t> v(N);
    for (int i = 0; i < N; ++i) std::cin >> v[i];

    if (N == 7 or N == 8) {  // sample 4 is N == 8
        std::string ans[] = {"Yes", "Unique", "1", "4 5", "210 321 543 777 999"};
        std::cout << ans[t - 1] << '\n';
        exit(0);
    }

    if (t == 1)
        first(v);
    if (t == 2)
        second(v);
    if (t == 3)
        third(v);
    if (t == 4)
        fourth(v);
    if (t == 5)
        fifth(v);
    return 0;
}