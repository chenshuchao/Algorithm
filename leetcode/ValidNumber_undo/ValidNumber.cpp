#include <iostream>
using namespace std;

class Solution {
    public:
    bool isNumber(string s) {
        s = trim(s);
        int n = s.size();
        if(!n) return false;

        cout << s << ":";
        bool hasDecimal = false;
        bool hasE = false;
        for(int i = 0; i < n; i++) {

            if(s[i] == ' ') {
                return false;
            }else if(isdigit(s[i])) {
                if((i >= 2 && s[i-2] == 'e' && s[i-1] == '0')) return false;
            } else if(s[i] == '.') {
                if(n == 1 || hasDecimal || (i > 0 && !isdigit(s[i-1]))) return false;
                hasDecimal = true;
            } else if(s[i] == '-' || s[i] == '+') {
                if(i == n-1 || (i != 0 && s[i-1] != 'e')) return false;
            } else if(s[i] == 'e') {
                if(hasE || i == 0 || i == n-1 || !isdigit(s[i-1])) return false;
                hasE = true;
            } else {
                return false;
            }
        }
        return true;
    }
    private:
    string trim(string s) {
        int n = s.size();
        int i = 0;
        while(i < n && s[i] == ' ') i ++;
        string s1 = s.substr(i);

        int n1 = s1.size();
        int j = n1-1;

        while(j >= 0 && s1[j] == ' ') {
            j --;
        }
        string s2 = s1.substr(0, j+1);

        return s2;
    }

};

int main() {

    Solution s;
    cout << s.isNumber("") << endl;
    cout << s.isNumber("  ") << endl;
    cout << s.isNumber("10 9") << endl;
    cout << s.isNumber(" 0    ") << endl;
    cout << endl;

    cout << s.isNumber("10e01") << endl;
    cout << s.isNumber("e1") << endl;
    cout << s.isNumber("012") << endl;
    cout << endl;

    cout << s.isNumber(".") << endl;
    cout << s.isNumber("11e.2") << endl;
    cout << s.isNumber(".1") << endl;
    cout << s.isNumber("12.") << endl;
    cout << s.isNumber("0.1") << endl;
    cout << endl;

    cout << s.isNumber("-e10") << endl;
    cout << s.isNumber("3e") << endl;
    cout << s.isNumber("10e22e1") << endl;
    cout << s.isNumber("10e0") << endl;
    cout << s.isNumber("0e1") << endl;
    cout << endl;

    cout << s.isNumber("-") << endl;
    cout << s.isNumber("2-1") << endl;
    cout << s.isNumber("10e-") << endl;
    cout << s.isNumber("-1") << endl;
    cout << s.isNumber("-10e-2") << endl;
    cout << endl;

    return 0;
}
