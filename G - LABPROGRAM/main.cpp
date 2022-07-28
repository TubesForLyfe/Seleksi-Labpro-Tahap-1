#include <iostream>
#include <string>
using namespace std;

int main() {
    // INPUT
    string s;
    int* LABPROGRAM = new int[8];
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'L') {
            LABPROGRAM[0]++;
        } else if (s[i] == 'A') {
            LABPROGRAM[1]++;
        } else if (s[i] == 'B') {
            LABPROGRAM[2]++;
        } else if (s[i] == 'P') {
            LABPROGRAM[3]++;
        } else if (s[i] == 'R') {
            LABPROGRAM[4]++;
        } else if (s[i] == 'O') {
            LABPROGRAM[5]++;
        } else if (s[i] == 'G') {
            LABPROGRAM[6]++;
        } else if (s[i] == 'M') {
            LABPROGRAM[7]++;
        }
    }

    // OUTPUT
    int min = LABPROGRAM[0];
    for (int i = 1; i < 8; i++) {
        if (i == 4 || i == 1) {
            if (LABPROGRAM[i] / 2 < min) {
                min = LABPROGRAM[i] / 2;
            }
        } else {
            if (LABPROGRAM[i] < min) {
                min = LABPROGRAM[i];
            }
        }
    }
    cout << min << endl;
}