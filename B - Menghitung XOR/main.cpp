#include <iostream>
using namespace std;

long QuickXOR(long n) {
    if (n % 4 == 0) {
        return n;
    } else if (n % 4 == 1) {
        return 1;
    } else if (n % 4 == 2) {
        return n + 1;
    } else {
        return 0;
    }
}

int main() {
    // INPUT
    int Q;
    cin >> Q;
    long* L = new long[Q];
    long* R = new long[Q];
    for (int i = 0; i < Q; i++) {
        cin >> L[i] >> R[i];
    }

    // OUTPUT
    for (int i = 0; i < Q; i++) {
        long result = 0;
        while (L[i] <= R[i] && L[i] % 4 != 0) {
            result ^= L[i];
            L[i]++;
        }
        if (L[i] % 4 == 0) {
            result ^= QuickXOR(R[i]);
        }
        cout << result << endl;
    }
}