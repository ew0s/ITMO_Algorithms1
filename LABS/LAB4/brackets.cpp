#include <iostream>
#include <string>
using namespace std;

int main() {
    freopen("brackets.in", "r", stdin);
    freopen("brackets.out", "w", stdout);
    ios_base::sync_with_stdio(false);

    string s;
    char stack[10000];

    while(cin >> s) {

        bool correct = true;
        int i = 0;
        int top = -1;

        while (s[i] != '\n' && s[i] != '\0') {

            if (s[i] == '(' || s[i] == '[') {
                top++;
                stack[top] = s[i];
            } else if (s[i] == ')' && stack[top] == '(') {
                top--;
            } else if (s[i] == ']' && stack[top] == '[') {
                top--;
            } else {
                correct = false;
                break;
            }

            i++;
        }

        if (correct && top == -1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}