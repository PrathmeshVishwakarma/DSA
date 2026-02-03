#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    stack<char> stk;
    string str = "(()())(())(()(()))";
    string result = "";
    for (char i : str) {
        if (i == '(') {
            stk.push(i);
        } else if (i == ')' && stk.top() == '(') {
            str += "()";
        } else {
        }
    }
}
