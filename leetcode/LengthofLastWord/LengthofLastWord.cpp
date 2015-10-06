#include <iostream>

using namespace std;

class Solution {
    public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int pos = n - 1;
        while(pos >= 0 && s[pos] == ' ') pos --;

        int num = 0;
        while(pos >= 0 && s[pos] != ' ') {
           num ++;
           pos --;
        }
        return num;
    }
};

int main() {
    Solution s;
    cout << s.lengthOfLastWord("Hello World") << endl;
    cout << s.lengthOfLastWord("Hello World  ") << endl;
    cout << s.lengthOfLastWord("  ") << endl;
    cout << s.lengthOfLastWord("") << endl;
    return 0;
}

