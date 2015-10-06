#include<iostream>
#include<stack＞
#include<string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        int n = s.size();
        if(n < 1) return true;
        for(int i = 0; i < n; i++) {
            if(s[i] == '{' || s[i] == '[' || s[i] == '(') stk.push(s[i]);
            if(s[i] == '}' || s[i] == ']' || s[i] == ')'){
                if(stk.size() <= 0) return false;
                char ch = stk.top();
                stk.pop();
                if(s[i] == '}' && ch != '{') return false;
                if(s[i] == ']' && ch != '[') return false;
                if(s[i] == ')' && ch != '(') return false;
            }
        }
        if(stk.size()) return false;
        return true;
    }
};
int main() {
    Solution s;
    string str1 = ""; 
    string str2 = "if(hi){}";
    string str3 = "if({)}";
    string str4 = "hahah(llal{}";
    string str5 = "]";
    cout << s.isValid(str1) << endl;
    cout << s.isValid(str2) << endl;
    cout << s.isValid(str3) << endl;
    cout << s.isValid(str4) << endl;
    cout << s.isValid(str5) << endl;
    return 0;
}
