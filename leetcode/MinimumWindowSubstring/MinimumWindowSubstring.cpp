#include <iostream>
#include <string>
using namespace std;

class Solution {
    public:
    string minWindow(string s, string t) {
        int n = s.size();
        int t = t.size();
        if(n == 0 || t == 0) return "";

        
        for(int i = 0; i < n; i++) {
        
        }
    }
};

int main() {

    Solution s;
    cout << s.minWindow("ADOBECODEBANC", "ABC") << endl;
    return 0;
}

