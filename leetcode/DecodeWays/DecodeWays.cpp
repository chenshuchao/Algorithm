#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int numDecodings(string s) {
        int n = s.size();
        if(0 == n || '0' == s[0]) return 0;
        if(1 == n) return 1;
        int *ways = new int[n];
        ways[0] = 1;
        if((s[0]-'0')*10 + s[1]-'0' <= 26) {
            if(s[1] != '0') ways[1] = 2;
            else ways[1] = 1;
        } else {
            if(s[1] != '0') ways[1] = 1;
            else {
                ways[1] = 0;
                return 0;
            }
        }
        for(int i = 2; i < n; i++) {
            if(s[i-1] == '0') {
                if(s[i] == '0') {
                   return 0;
                } else {
                    ways[i] = ways[i-1];
                }
            } else {
                if(s[i] == '0') {
                    if((s[i-1]-'0') * 10 + s[i] - '0' <= 26) {
                        ways[i] = ways[i-2];
                    } else {
                        return 0;
                    }
                } else {
                    if((s[i-1]-'0') * 10 + s[i] - '0' <= 26) {
                        ways[i] = ways[i-1] + ways[i-2];
                    }
                    else {
                        ways[i] = ways[i-1];
                    }
                }
            }
        }
        int decodeWay = ways[n-1];
        delete[] ways;
        return decodeWay;
    }
};

int main() {
    
    Solution s;
    cout << s.numDecodings("012") << "Expected: "<< 0 << endl;
    cout << s.numDecodings("302") << "Expected: "<< 0 << endl;   
    cout << s.numDecodings("1260") << "Expected: "<< 0 << endl;
    cout << s.numDecodings("10") << "Expected: "<< 1 << endl;
    cout << s.numDecodings("1029") << "Expected: "<< 1 << endl;
    cout << s.numDecodings("227") << "Expected: "<< 2 << endl;
    cout << s.numDecodings("111") << "Expected: "<< 3 << endl;
    cout << s.numDecodings("1220") << "Expected: "<< 2 << endl;
    cout << s.numDecodings("1205") << "Expected: "<< 1 << endl;
    cout << s.numDecodings("1235") << "Expected: "<< 3 << endl;
    cout << s.numDecodings("1214") << "Expected: "<< 5 << endl;
    cout << s.numDecodings("4757562545844617494555774581341211511296816786586787755257741178599337186486723247528324612117156948") << "Expected: "<< 589824 << endl;
    
    return 0;
}

