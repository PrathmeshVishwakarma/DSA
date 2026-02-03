#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    stack<char> stk;
    string str = "()[]{}";
    for (char i : str) {
        if (i == '(' || i == '{' || i == '[') {
            stk.push(i);
        } else { // closing bracket
            if (stk.empty())
                return false;

            if (i == ')' && stk.top() != '(')
                return false;
            if (i == ']' && stk.top() != '[')
                return false;
            if (i == '}' && stk.top() != '{')
                return false;

            stk.pop(); // remove the opening bracket
        }
    }
    return stk.empty(); // should be empty by the end of operations}
}
