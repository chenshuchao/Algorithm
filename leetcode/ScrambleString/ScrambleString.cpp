#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1 == s2) return true;

        int len1 = s1.size();
        int len2 = s2.size();
        if(len1 != len2) return false;
        
        int ch[256] = {0};
        for(int i = 0; i < len1; i ++) {
            ch[s1[i]] ++;
            ch[s2[i]] --;
        }
        for(int i = 0; i < 256; i ++) {
            if(ch[i] != 0) return false;
        }
        for(int i = 1; i < len1; i ++) {
            if(isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) {
                return true;
            }
            if(isScramble(s1.substr(0, i), s2.substr(len1-i)) && isScramble(s1.substr(i), s2.substr(0, len1-i))) {
                return true;
            }
        }
        return false;
    }
};

int main() {

    Solution s;
    cout << s.isScramble("abc", "bca") << endl; 

    return 0;
}

