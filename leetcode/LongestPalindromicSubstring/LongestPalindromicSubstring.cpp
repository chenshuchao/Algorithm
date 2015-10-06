#include<iostream>
#include<string>

using namespace std;

class Solution {

    public:
    
    string findPalindrome(string s,int left, int right) {
            int size = s.size();
            if(size <= 1) return s;
 
            while(left >= 0 && right < size && s[left] == s[right]) {
                        left --;
                        right ++;
                    }
            return s.substr(left + 1,right - left - 1);
    
        }
    string longestPalindrome(string s) {
            int size = s.size();
            if(size <= 1) return s;
            
            string longestStr = "";
            string tempStr = "";
            int longestLength = 0;
            int tempLength = 0;
            for(int i = 0; i < size; i++) {
                        tempStr = findPalindrome(s,i,i);
                        tempLength = tempStr.size();
                        if (longestLength < tempLength) {
                                        longestStr = tempStr;
                                        longestLength = tempLength;
                                    }
            
                        tempStr = findPalindrome(s,i,i+1);
                        tempLength = tempStr.size();
                        if(longestLength < tempLength) {
                                        longestStr = tempStr;
                                        longestLength = tempLength;
                                    }
                    }
    
            return longestStr;
        }
};

int main() {
    Solution s;
    string str1 = "1233211";
    string str2 = "";
    string str3 = "3";
    string str4 = "absshua";
    string str5 = "aa";
    string str6 = "abccba";
    string str7 = "abb";
    cout << str1 << " : " << s.longestPalindrome(str1) << endl;
    cout << str2 << " : " << s.longestPalindrome(str2) << endl;
    cout << str3 << " : " << s.longestPalindrome(str3) << endl;
    cout << str4 << " : " << s.longestPalindrome(str4) << endl;
    cout << str5 << " : " << s.longestPalindrome(str5) << endl;
    cout << str6 << " : " << s.longestPalindrome(str6) << endl;
    cout << str7 << " : " << s.longestPalindrome(str7) << endl;

    return 0;
}
