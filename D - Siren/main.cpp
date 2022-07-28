#include <iostream>
#include <string>
using namespace std;

int main() {
    // INPUT
    string s;
    cin >> s;
    int even_count = 0;
    int odd_count = 0;
    for (int i = 0; i < s.size(); i++) {
        if (i % 2 == 0) {
            if (s[i] == '0') {
                odd_count++;
            } else {
                even_count++;
            }
        } else {
            if (s[i] == '1') {
                odd_count++;
            } else {
                even_count++;
            }
        }
    }
    
    // OUTPUT
    if (odd_count < even_count) {
        cout << odd_count;
    } else {
        cout << even_count;
    }
    cout << endl;
}