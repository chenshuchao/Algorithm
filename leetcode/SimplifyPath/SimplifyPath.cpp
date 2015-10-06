#include <iostream>
#include <deque>
#include <string>
using namespace std;

class Solution {
    public:
    string simplifyPath(string path) {
        int n = path.size();
        if(n == 0) return "/";

        deque<string> dq;
        if(path[0] != '/') return "";

        int left = 0;
        while(left < n) {
            int right = left+1;
            while(right < n && path[right] != '/') {
                right ++;
            }
            string word = path.substr(left+1, right - left -1);
            word = trim(word);
            if(word != "." && word != "") {
                if(word == "..") {
                    if(!dq.empty()) dq.pop_back();
                } else {
                    dq.push_back(word);
                }
            }
            left = right;
        }
        string simple = "";
        while(!dq.empty()) {
            simple += '/' + dq.front();
            dq.pop_front();
        }
        if(simple.empty()) simple = "/";

        return simple;
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
    cout << s.simplifyPath("") << endl;
    cout << s.simplifyPath("/") << endl;
    cout << s.simplifyPath("///") << endl;
    cout << s.simplifyPath("/./") << endl;
    cout << s.simplifyPath("/..") << endl;
    cout << s.simplifyPath("/a/./b/../../c/") << endl;
    cout << s.simplifyPath("/home/") << endl;
    cout << s.simplifyPath("/a/././b/../shuchao") << endl;

    return 0;
}

