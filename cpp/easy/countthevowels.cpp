// Count the Vowels
#include <iostream>
#include <string>

/**
 * @brief Convert a character to lowercase
 *
 * @param c The character to be converted
 * @return char Lowercase of c if not already lowercase,
 * returns c if input is not [a-zA-Z]
 */
char to_lower_case(char& c) {
    if (c >= 'a' && c <= 'z')  // already lower case
        return c;

    if (c < 'A' || c > 'Z')  // invalid input
        return c;

    return c ^ 0x20;  // convert c to lower case
}

bool is_vowel(char c) {
    return (
        c == 'a' ||
        c == 'e' ||
        c == 'i' ||
        c == 'o' ||
        c == 'u');
}

int main(void) {
    std::string s;
    std::getline(std::cin, s);

    int count = 0;
    for (auto& c : s) {
        if (is_vowel(to_lower_case(c)))
            ++count;
    }

    std::cout << count;
    return 0;
}