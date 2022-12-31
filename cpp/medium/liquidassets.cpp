// Liquid Assets
#include <iostream>
#include <vector>

std::string remove_repeated_chars(std::string s) {
    std::string result;
    char prev = ' ';
    for (char c : s) {
        if (c == prev)
            continue;
        result += c;
        prev = c;
    }

    return result;
}

std::string remove_vowels(std::string s) {
    std::string result;
    char prev = ' ';
    for (auto it = s.begin(); it != s.end(); ++it) {
        // skip the first and last letter
        if (it == s.begin() || it == s.end() - 1) {
            result += *it;
            continue;
        }

        switch (*it) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            continue;
        default:
            // non-vowel/end character
            result += *it;
        }
    }

    return result;
}

template <typename T>
void print_vector(std::vector<T> v, char delim = ' ') {
    for (auto it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << delim;
    }
    std::cout << '\n';
}

int main(void) {
    int n;
    std::vector<std::string> sentence;

    // read input
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::string temp;
        std::cin >> temp;
        sentence.push_back(temp);
    }

    // process input
    for (auto it = sentence.begin(); it != sentence.end(); ++it) {
        std::string temp = *it;
        *it = remove_repeated_chars(*it);
        *it = remove_vowels(*it);
    }

    print_vector(sentence);
    return 0;
}
