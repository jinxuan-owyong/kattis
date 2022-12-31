// Sort of Sorting
#include <iostream>
#include <vector>

template <typename T>
void print_vector(std::vector<T> v, char delim = ' ') {
    for (auto it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << delim;
    }
    std::cout << '\n';
}

// [A-Za-z] ranges from 65 to 122
// Shift first character by 3 digits (multiply 1000)
int get_string_score(std::string& s) {
    return (int)s[0] * 1000 + (int)s[1];
}

void bubbleSort(std::vector<std::string>& a) {  // the standard version
    int N = a.size();
    for (; N > 0; --N)                     // N iterations
        for (int i = 0; i < N - 1; ++i) {  // except the last, O(N)
            int s1 = get_string_score(a[i]);
            int s2 = get_string_score(a[i + 1]);
            if (s1 > s2)                    // not alphabetically sorted
                std::swap(a[i], a[i + 1]);  // swap in O(1)
        }
}

int main(void) {
    int n;
    while (n != 0) {
        // read input
        std::cin >> n;
        std::vector<std::string> names(n, "");
        for (int i = 0; i < n; ++i) std::cin >> names[i];
        bubbleSort(names);
        print_vector(names, '\n');
    }

    return 0;
}
