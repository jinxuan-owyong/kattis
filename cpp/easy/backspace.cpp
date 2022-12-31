// Backspace
#include <deque>
#include <iostream>

int main(void) {
    std::string input;
    std::cin >> input;
    std::deque<char> intended;

    for (auto& c : input) {
        // not backspace
        if (c != '<') {
            intended.push_back(c);
            continue;
        }
        // backspace
        if (intended.size() == 0) {
            continue;
        } else {
            intended.pop_back();
        }
    }

    for (auto& c : intended) {
        std::cout << c;
    }

    return 0;
}
