// Weak Vertices
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int N;
    while (cin >> N) {
        if (N == -1)
            break;
        vector<vector<int>> adj_matrix(N, vector<int>(N));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> adj_matrix[i][j];
            }
        }
        for (int i = 0; i < N; ++i) {
            bool weak = true;
            for (int j = 0; j < N && weak; ++j) {
                for (int k = 0; k < N && weak; ++k) {
                    if (i == j || j == k || i == k)
                        continue;
                    if (adj_matrix[i][j] == adj_matrix[j][k] &&
                        adj_matrix[j][k] == adj_matrix[i][k] &&
                        adj_matrix[k][i] == 1) {
                        weak = false;
                    }
                }
            }
            if (weak)
                cout << i << ' ';
        }
        cout << '\n';
    }
    return 0;
}
