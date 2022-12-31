// Bracket Matching
#include <iostream>
#include <stack>

int main(void) {
    int n;
    std::string s;
    std::cin >> n;
    if (n == 0) {
        std::cout << "Valid";
        return 0;
    }
    std::cin >> s;
    std::stack<char> prev;

    bool valid = true;
    for (int i = 0; valid && (i < n); ++i) {
        switch (s[i]) {
        case '(':
        case '{':
        case '[':
            prev.push(s[i]);
            break;
        case ')':
            if (prev.size() > 0 && prev.top() == '(')
                prev.pop();
            else
                valid = false;
            break;
        case '}':
            if (prev.size() > 0 && prev.top() == '{')
                prev.pop();
            else
                valid = false;
            break;
        case ']':
            if (prev.size() > 0 && prev.top() == '[')
                prev.pop();
            else
                valid = false;
            break;
        }
    }

    if (prev.size() == 0 && valid)
        std::cout << "Valid";
    else
        std::cout << "Invalid";

    return 0;
}
