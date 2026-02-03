#include <cctype>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s = "ck077";
    int largest = -1;
    int second_largest = -1;
    for (int i = 0; i < s.length(); i++) {
        if (isdigit(s[i])) {
            int current = s[i] - '0';
            if (largest == -1) {
                largest = current;
            } else {
                if (current > largest) {
                    second_largest = largest;
                    largest = current;
                }
                if (current < largest && current > second_largest) {
                    second_largest = current;
                }
            }
        }
        cout << second_largest << " " << largest << endl;
    }
}
