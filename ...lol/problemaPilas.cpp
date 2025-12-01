#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isBalanced(const string& expression) {
    stack<char> stack;

    for (char c : expression) {
        if (c == '(' || c == '[' || c == '{') {
            stack.push(c);
        }
        else if (c == ')' || c == ']' || c == '}') {
            if(stack.empty()) {
                return false;
            }
                char top = stack.top();
                stack.pop();
                
                if (c == ')' && top != '(') return false;
                if (c == ']' && top != '[') return false;
                if (c == '}' && top != '{') return false;
            

        }
    }

    return stack.empty();
}

int main() {
    string expression; 
    cout << "Ingrese un expresion" << endl;
    cin >> expression;

    if (isBalanced(expression)) {
        cout << "La expresion esta balanceada";
    } else {
        cout << "La expresion no esta balanceada";
    }

    cout << endl;
    return 0;
}