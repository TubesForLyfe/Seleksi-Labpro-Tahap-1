#include <iostream>
using namespace std;

int main() {
    // INPUT
    int N, num;
    cin >> N;
    bool subsequence = false;
    int** E = new int*[51];
    for (int i = 0; i < 51; i++) {
        E[i] = new int[2];
    }
    for (int i = 1; i < N + 1; i++) {
        cin >> num;
        if (E[num][0] == 1 && E[num][1] != i - 1) {
            subsequence = true;
            break;
        }
        E[num][0] = 1;
        if (E[num][1] == 0) {
            E[num][1] = i;
        }
    }

    // OUTPUT
    if (subsequence) {
        cout << 'Y';
    } else {
        cout << 'N';
    }
    cout << endl;
}