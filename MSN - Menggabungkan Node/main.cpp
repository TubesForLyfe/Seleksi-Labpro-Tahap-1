#include <iostream>
using namespace std;

int main() {
    // INPUT
    int N;
    cin >> N;
    int** node = new int*[N];
    for (int i = 0; i < N; i++) {
        node[i] = new int[N];
    }
    for (int i = 0; i < N; i++) {
        cin >> node[0][i];
    }
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < N - i + 1; j++) {
            node[i][j] = (node[i - 1][j] + node[i - 1][j + 1]) % 10;
        }
    }

    // OUTPUT
    cout << node[N - 1][0] << endl;
}