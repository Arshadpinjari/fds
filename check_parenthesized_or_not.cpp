#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isWellParenthesized(const string& expression) {
    stack<char> s;
    for (char ch : expression) {
        if (ch == '(' || ch == '{' || ch == '[') s.push(ch);
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty() || (ch == ')' && s.top() != '(') || (ch == '}' && s.top() != '{') || (ch == ']' && s.top() != '['))
                return false;
            s.pop();
        }
    }
    return s.empty();
}

int main() {
    string expression;
    cout << "Enter an expression: ";
    getline(cin, expression);

    cout << (isWellParenthesized(expression) ? "Well-parenthesized" : "Not well-parenthesized") << endl;

    return 0;
}
