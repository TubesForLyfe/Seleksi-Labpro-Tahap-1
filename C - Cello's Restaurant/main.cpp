#include <iostream>
using namespace std;

void increment(int** inc, int *elmt, int idx_eff, int *row_eff) {
    for (int i = *row_eff; i >= 0; i--) {
        if (idx_eff == inc[i][0]) {
            *elmt += inc[i][1];
            inc[i][0]--;
            if (inc[i][0] == -1) {
                (*row_eff)--;
            }
        }
    }
}

int main() {
    // INPUT
    int Q, Op, X, Y;
    cin >> Q;
    int* tumpukan = new int[100000];
    int* result = new int[Q];
    int** increase = new int*[50000];
    for (int i = 0; i < 50000; i++) {
        increase[i] = new int[2];
    }
    int inc_row = -1;
    int idx_eff = -1;
    for (int i = 0; i < Q; i++) {
        cin >> Op;
        if (Op == 1) {
            idx_eff++;
            cin >> tumpukan[idx_eff];
            result[i] = tumpukan[idx_eff];
        } else if (Op == 2) {
            cin >> Y >> X;
            Y--;
            if (Y == idx_eff) {
                tumpukan[idx_eff] += X;
                Y--;
            }
            inc_row++;
            increase[inc_row][0] = Y;
            increase[inc_row][1] = X;
            result[i] = tumpukan[idx_eff];
        } else if (Op == 0) {
            idx_eff--;
            increment(increase, &tumpukan[idx_eff], idx_eff, &inc_row);
            if (idx_eff == -1) {
                result[i] = 0;
            } else {
                result[i] = tumpukan[idx_eff];
            }
        }
    }

    // OUTPUT
    for (int i = 0; i < Q; i++) {
        if (result[i] == 0) {
            cout << "EMPTY";
        } else {
            cout << result[i];
        }

        if (i == Q - 1) {
            cout << endl;
        } else {
            cout << " ";
        }
    }
}