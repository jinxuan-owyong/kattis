// Laptop Stickers
#include <iostream>
#include <sstream>
#include <vector>

const char STICKER_NONE = '_';
const char STICKER_FIRST = 'a';

template <typename T>
void print_2d_vector(
    std::vector<std::vector<T>>& v2d) {
    for (auto& v : v2d) {
        for (auto& e : v) {
            std::cout << e;
        }
        std::cout << '\n';
    }
}

class Sticker {
public:
    int length;
    int height;
    int col;
    int row;
    int id;

    Sticker(int l, int h, int a, int b) {
        length = l;
        height = h;
        col = a;
        row = b;
    }
};

/**
 * @brief Convert the string containing the sticker data into Sticker instance
 *
 * @param s String containing sticker data
 * @return Sticker instance containing sticker data
 */
Sticker process_sticker_string(std::string s) {
    std::stringstream ss;
    ss << s;
    int l, h, a, b;
    ss >> l;
    ss >> h;
    ss >> a;
    ss >> b;
    Sticker st = Sticker(l, h, a, b);
    return st;
}

/**
 * @brief Place a sticker on the laptop lid
 *
 * @param lid 2D vector containing the state of the current laptop lid
 * @param st The sticker instance to be placed
 * @param laptop_l The length of the laptop
 * @param laptop_h The height of the laptop
 */
void place_sticker(
    std::vector<std::vector<char>>& lid,
    Sticker& st,
    int laptop_l,
    int laptop_h) {
    int& y = st.row;
    int& x = st.col;

    for (int i = 0; i < st.height; ++i) {
        for (int j = 0; j < st.length; ++j) {
            // sticker overflows laptop lid
            if (i + y >= laptop_h || j + x >= laptop_l)
                continue;

            // paste sticker
            lid[i + y][j + x] = STICKER_FIRST + st.id;
        }
    }
}

/**
 * @brief Fill the laptop lid with the stickers
 *
 * @param stickers Vector containing sticker instances
 * @param laptop_l The length of the laptop
 * @param laptop_h The height of the laptop
 * @return std::vector<std::vector<char>> 2D vector of the state of the lid
 */
std::vector<std::vector<char>> fill_laptop_lid(
    std::vector<Sticker>& stickers,
    int laptop_l,
    int laptop_h) {
    std::vector<std::vector<char>> lid(
        laptop_h,
        std::vector<char>(laptop_l, STICKER_NONE));

    for (Sticker& s : stickers) {
        place_sticker(lid, s, laptop_l, laptop_h);
    }

    return lid;
}

int main(void) {
    int l, h, k;
    std::cin >> l;
    std::cin >> h;
    std::cin >> k;
    std::cin.ignore();

    std::vector<Sticker> stickers;
    for (int i = 0; i < k; ++i) {
        std::string temp;
        std::getline(std::cin, temp);
        Sticker st = process_sticker_string(temp);
        st.id = i;
        stickers.push_back(st);
    }

    auto laptop = fill_laptop_lid(stickers, l, h);
    print_2d_vector(laptop);
    return 0;
}
