#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    // INPUT
    long N;
    string s;
    cin >> N;
    long* result = new long[N];
    for (long i = 0; i < N; i++) {
        cin >> s;
        stack<char> kurung;
        for (size_t j = 0; j < s.length(); j++) {
            if (kurung.empty()) {
                kurung.push(s[j]);
            }
            else if ((kurung.top()=='('&& s[j]==')')  ||  (kurung.top()=='{' && s[j]=='}')  ||  (kurung.top()=='[' && s[j]==']')) {
                kurung.pop();
            }
            else {
                kurung.push(s[j]);
            }
        }

        if (kurung.empty()) {
            result[i] = 1;
        } else {
            result[i] = 0;
        }
    }

    // OUTPUT
    for (long i = 0; i < N; i++) {
        cout << result[i] << endl;
    }
}