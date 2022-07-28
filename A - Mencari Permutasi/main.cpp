#include <iostream>
using namespace std;

int faktorial(int i) {
    int result = 1;
    while (i > 1) {
        result *= i;
        i--;
    }
    return result;
}

void swap(int* N, int i, int j) {
    while (j > i) {
        int temp = N[j];
        N[j] = N[j - 1];
        N[j - 1] = temp;
        j--;
    }
}

int main() {
    // INPUT
    int Q;
    cin >> Q;
    int* N = new int[Q];
    int* M = new int[Q];
    for (int i = 0; i < Q; i++) {
        cin >> N[i] >> M[i];
    }

    // OUTPUT
    for (int i = 0; i < Q; i++) {
        int* number = new int[N[i]];
        for (int j = 1; j <= N[i]; j++) {
            number[j - 1] = j;
        }

        while (M[i] > 1) {
            int faktorial_num = 1;
            while (faktorial(faktorial_num + 1) < M[i]) {
                faktorial_num++;
            }
            int idx_dif = (M[i] -1) / faktorial(faktorial_num);
            swap(number, N[i] - faktorial_num - 1, N[i] - faktorial_num - 1 + idx_dif);
            M[i] -= faktorial(faktorial_num) * idx_dif;
        }

        for (int j = 0; j < N[i]; j++) {
            cout << number[j];
        }
        cout << endl;
    }
}