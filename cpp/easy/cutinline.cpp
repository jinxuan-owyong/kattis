// Cut in Line
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

template <typename T>
void print_vector(std::vector<T>& v, char delim = ' ') {
    for (auto it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << delim;
    }
    std::cout << '\n';
}

template <typename T>
auto get_pos(std::vector<T>& v, T target) {
    return std::find(v.begin(), v.end(), target);
}

int main(void) {
    int C, N;
    std::cin >> N;
    std::vector<std::string> line(N);
    for (int i = 0; i < N; ++i) std::cin >> line[i];

    std::cin >> C;
    for (int i = 0; i < C; ++i) {
        std::string action;
        std::cin >> action;
        bool is_leave = action.compare("leave") == 0;

        if (is_leave) {  // leave
            std::string name;
            std::cin >> name;
            line.erase(get_pos(line, name));
        } else {  // cut
            std::string cutting, who;
            std::cin >> cutting >> who;
            // insert the person cutting queue in front of who
            auto target = get_pos(line, who);
            line.insert(target, cutting);
        }
    }

    print_vector(line, '\n');
    return 0;
}
