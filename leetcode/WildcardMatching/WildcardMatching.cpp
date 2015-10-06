#include <iostream>
using namespace std;

class Solution {
    public:

    bool isMatch(string s, string p) {

        int sLen = s.size();
        int pLen = p.size();
        int i = 0;
        int j = 0;
        int last_s = -1;
        int last_p = -1;
        while(i < sLen) {
            if(j < pLen && p[j] == '*') {
                j ++;
                if(j == pLen) return true;
                last_s = i;
                last_p = j;
            } else if(j < pLen && (p[j] == '?' || s[i] == p[j])) {
                i ++;
                j ++;
            } else if(last_p > 0) {
                j = last_p;
                i = ++ last_s;
            } else {
                return false;
            }
        }

        while(j < pLen && p[j] == '*') j++;
        return j == pLen;
    }
};

int main() {

    Solution s;
    cout << s.isMatch("aa", "a") << endl;
    cout << s.isMatch("aa", "aa") << endl;
    cout << s.isMatch("aaa", "a") << endl;
    cout << s.isMatch("aa", "*") << endl;
    cout << s.isMatch("aa", "a*") << endl;
    cout << s.isMatch("ba", "?*") << endl;
    cout << s.isMatch("aab", "c*a*b") << endl;
    cout << s.isMatch("abefcdgiescdfimde", "ab*cd?i*de") << endl;
    cout << s.isMatch("", "") << endl;

    return 0;
}
