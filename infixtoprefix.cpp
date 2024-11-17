#include <iostream>
#include<stack>
using namespace std;

bool isOperator(char c) {
    return (!isalpha(c) && !isdigit(c) && c != '(' && c != ')');
}

int getPriority(char C) {
    if (C == '+' || C == '-') return 1;
    if (C == '*' || C == '/') return 2;
    if (C == '^') return 3;
    return 0;
}

string infixToPostfix(string infix) {
    infix = '(' + infix + ')';
    int l = infix.size();
    stack<char> char_stack;
    string output;

    for (int i = 0; i < l; i++) {

        if (isalpha(infix[i]) || isdigit(infix[i])) {
            output += infix[i];
        }
        else if (infix[i] == '(') {
            char_stack.push('(');
        }
        else if (infix[i] == ')') {
            while (char_stack.top() != '(') {
                output += char_stack.top();
                char_stack.pop();
            }
            char_stack.pop();
        }
        else {
            while (!char_stack.empty() && getPriority(infix[i]) <= getPriority(char_stack.top())) {
                output += char_stack.top();
                char_stack.pop();
            }
            char_stack.push(infix[i]);
        }
    }

    while (!char_stack.empty()) {
        output += char_stack.top();
        char_stack.pop();
    }
    return output;
}

string infixToPrefix(string infix) {
    int l = infix.size();

    reverse(infix.begin(), infix.end());

    for (int i = 0; i < l; i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        } else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }

    string prefix = infixToPostfix(infix);
    reverse(prefix.begin(), prefix.end());

    return prefix;
}

int main() {
    string s = "x+y*z/w+u";
    cout << infixToPrefix(s) << endl;
    return 0;
}
