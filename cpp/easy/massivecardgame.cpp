// Massive Card Game
#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
bool valid_index(std::vector<T>& v, int i) {
    return i >= 0 && i < (int)v.size();
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // read cards input
    int32_t N;
    std::cin >> N;
    std::vector<int32_t> cards(N);
    for (int32_t i = 0; i < N; ++i) {  // O(n)
        std::cin >> cards[i];
    }
    std::sort(cards.begin(), cards.end());  // O(n log n)

    int32_t Q;
    std::cin >> Q;

    // process queries
    for (int32_t i = 0; i < Q; ++i) {  // O(q log n)++
        int32_t l, r;
        std::cin >> l >> r;

        int32_t nearest_l = std::lower_bound(cards.begin(), cards.end(), l) - cards.begin();  // O(n log n)++
        int32_t nearest_r = std::upper_bound(cards.begin(), cards.end(), r) - cards.begin();  // O(n log n)++
        if (valid_index(cards, nearest_l) && cards[nearest_l] > l)
            --nearest_l;
        if (valid_index(cards, nearest_r - 1) && cards[nearest_r - 1] == r)
            --nearest_r;

        int32_t output = nearest_r - nearest_l + 1;
        bool extra_l = nearest_l < 0 || (valid_index(cards, nearest_l) && cards[nearest_l] < l);
        bool extra_r = nearest_r >= (int32_t)cards.size() || (valid_index(cards, nearest_r) && cards[nearest_r] > r);
        extra_l && --output;
        extra_r && --output;

        std::cout << output << '\n';
    }

    return 0;
}
