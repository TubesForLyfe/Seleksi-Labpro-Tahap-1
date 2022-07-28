#include <iostream>
#include <string>
using namespace std;

int main() {
    // INPUT
    string s;
    cin >> s;
    char* result = new char[10000000];
    int idx_eff = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != 'B') {
            result[idx_eff] = s[i];
            idx_eff++;
        } else {
            if (idx_eff != 0) {
                idx_eff--;
            }
        }
    }

    // OUTPUT
    for (int i = 0; i < idx_eff; i++) {
        cout << result[i];
    }
    cout << endl;
}