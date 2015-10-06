#include <iostream>
#include <string>

using namespace std;

class Solution {

    public:
    string countAndSay(int n) {
        if(n <= 0) return "";
        string curStr = "1";
        for(int i = 0; i < n - 1; i++) {
           curStr = getNext(curStr); 
        }
        return curStr;
    }

    private:
    string getNext(string s) {
        int size = s.size();
        int j = 1;
        string res = "";
        for(int i = 1; i < size; i++) {
            if(s[i] == s[i-1]) j++;
            else {
               res = res + char(j + int('0')) + s[i-1];
               j = 1;
            }
        }
        res = res + char(j + int('0')) + s[size-1];
        return res;
    }
};

int main() {

    Solution s;
    cout << s.countAndSay(0) << endl;
    cout << s.countAndSay(1) << endl;
    cout << s.countAndSay(2) << endl;
    cout << s.countAndSay(3) << endl;
    cout << s.countAndSay(4) << endl;
    cout << s.countAndSay(5) << endl;
    cout << s.countAndSay(6) << endl;
    cout << s.countAndSay(7) << endl;
    cout << s.countAndSay(8) << endl;

    return 0;
}

