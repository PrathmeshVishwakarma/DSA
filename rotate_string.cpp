#include <iostream>
#include <string>

using namespace std;

int main() {
    string s = "abcde";
    string goal = "abced";
    string str = s + s;
    cout << str << endl;
    cout << str.find(goal);
    return 0;
}
