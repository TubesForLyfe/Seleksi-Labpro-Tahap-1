#include <iostream>
using namespace std;

int main() {
    // INPUT
    int N, num, result;
    cin >> N;
    int* numbers = new int[N + 1];
    for (int i = 0; i < N + 1; i++) {
        cin >> num;
        if (numbers[num] == 1) {
            result = num;
            break;
        }
        numbers[num] = 1;
    }

    // OUTPUT
    cout << result << endl;
}