#include <iostream>
#include <set>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<string> st = {};
        for (int i=0; i<s.length()-k+1;i++){
            string sub_string =  s.substr(i, k);
            st.insert(sub_string);
        }
        if (st.size() == pow(2, k)){
            return true;
        }
        return false; 
    }
};
int main(){
    string s = "00110110";
    int k = 2;
    Solution soln;
    cout << soln.hasAllCodes(s, k);
    return 0;
}
