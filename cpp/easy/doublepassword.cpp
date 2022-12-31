// Double Password
#include <iostream>
#include <vector>

// Let n be the nunmber of matching digits in corresponding positions
// The element at index n of num_sequences gives the number of distinct
// four-digit sequences that will log the programmer into the system.
const std::vector<int> num_sequences = {16, 8, 4, 2, 1};

/**
 * @brief Compare the nunmber of matching characters in corresponding positions
 * among two strings
 *
 * @param a The first string
 * @param b The second string
 * @return int The number of matching characters
 */
int compare_chars(std::string a, std::string b) {
    if (a.size() != b.size())
        return -1;

    auto ait = a.begin();
    auto bit = b.begin();
    int n_matching = 0;

    do {
        if (*ait == *bit)
            ++n_matching;
        ++ait;
        ++bit;
    } while (ait != a.end());

    return n_matching;
}

int main(void) {
    std::string first, second;
    std::cin >> first;
    std::cin >> second;

    int n = compare_chars(first, second);
    std::cout << num_sequences[n];

    return 0;
}