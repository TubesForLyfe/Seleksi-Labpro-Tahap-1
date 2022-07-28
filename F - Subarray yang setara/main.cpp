#include <iostream>
using namespace std;

int length(int first, int last) {
    return last - first + 1;
}

int main() {
    // INPUT
    int N, num, max, first_idx, last_idx;
    cin >> N;
    int* E = new int[N];
    int* count = new int[101];
    max = 0;
    for (int i = 0; i < N; i++) {
        cin >> E[i];
        count[E[i]]++;
        if (count[E[i]] == 1) {
            count[E[i] + 50] = i;
        }
        if (count[E[i]] > max) {
            max = count[E[i]];
            last_idx = i;
        } else if (count[E[i]] == max) {
            if (length(count[E[i] + 50], i) < length(count[E[last_idx] + 50], last_idx)) {
                max = count[E[i]];
                last_idx = i;
            }
        }
    }

    // OUTPUT
    cout << length(count[E[last_idx] + 50], last_idx) << endl;
}