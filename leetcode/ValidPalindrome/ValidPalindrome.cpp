#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        if(n == 0) return true;
        int left = 0, right = n - 1;
        while(left < right) {
            while(left < right && !isalnum(s[left])) left ++;
            while(right > left && !isalnum(s[right])) right --;
            if(left < right && lowerCase(s[left]) != lowerCase(s[right])) {
                return false;
            }
            left ++;
            right --;
        }
        return true;
    }
    char lowerCase(char ch) {
        if(ch >= 'A' && ch <= 'Z') return 'a' + ch - 'A';
        else return ch;
    }
};
template <typename T>
void printV(const vector<T>& v) {
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

template <typename T>
void printVV(const vector<vector<T> >& vv) {
    for(int i = 0; i < vv.size(); i++) {
        printV(vv[i]);
    }
}


int main() {
    Solution s;
    cout << s.isPalindrome("A man, a plan, a canal: Panama") << endl; 
    cout << s.isPalindrome("1a2") << endl; 
    return 0;
}

