// Cookie Selection
// Two multisets, 0.18s
#include <bits/stdc++.h>
using namespace std;

class MedianSet {
private:
    multiset<int> left, right;
    static auto front(multiset<int>& m) { return m.begin(); }
    static auto back(multiset<int>& m) { return --m.end(); }
    static int extractFront(multiset<int>& m) {
        auto it = front(m);
        int x = *it;
        m.erase(it);
        return x;
    }
    static int extractBack(multiset<int>& m) {
        auto it = back(m);
        int x = *it;
        m.erase(it);
        return x;
    }

public:
    int size() { return left.size() + right.size(); }
    int extractMid() {
        int mid = extractFront(right);
        if (size() % 2 == 1) {
            // shift last element of left to right
            right.insert(extractBack(left));
        }
        return mid;
    }
    void insert(int x) {
        // determine if x belongs to the left or right set
        int mid = *front(right);
        if (size() % 2 == 0) {  // case 1: sets are balanced
            if (x >= mid) {
                right.insert(x);
            } else {
                left.insert(x);
                right.insert(extractBack(left));
            }
        } else {  // right set has one more element than left
            if (x >= mid) {
                right.insert(x);
                left.insert(extractFront(right));
            } else {
                left.insert(x);
            }
        }
    }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    MedianSet cookies;
    string s;
    while (getline(cin, s)) {
        if (s == "#") {
            cout << cookies.extractMid() << '\n';
        } else {
            cookies.insert(stoi(s));
        }
    }
    return 0;
}

// // Cookie Selection
// // Ordered statistics tree, 0.21s
// #include <bits/extc++.h>
// #include <bits/stdc++.h>
// using namespace __gnu_pbds;
// using namespace std;

// int main(void) {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> cookies;
//     string s;
//     while (getline(cin, s)) {
//         if (s != "#") {
//             cookies.insert(stoi(s));
//             continue;
//         }
//         auto it = cookies.find_by_order(cookies.size() / 2.0f);  // 0-based indexing
//         cout << *it << '\n';
//         cookies.erase(it);
//     }
// }
