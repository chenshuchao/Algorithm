#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        if(n <= 1) return 0;
        vector<int> cut(n+1, 0);
        for(int i = 0; i <= n; i ++) {
            cut[i] = i - 1;
        }
        for(int i = 0; i < n; i ++) {
            for(int j = 0; i-j >= 0 && i+j < n && s[i-j] == s[i+j]; j ++) {
                cut[i+j+1] = min(cut[i+j+1], cut[i-j] + 1);
            }
            for(int j = 0; i-j >= 0 && i+j+1 < n && s[i-j] == s[i+j+1]; j ++) {
                cut[i+j+2] = min(cut[i+j+2], cut[i-j] + 1);
            }
        }
        return cut[n];
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
    cout << s.minCut("") << endl;
    cout << s.minCut("a") << endl;
    cout << s.minCut("aab") << endl;
    cout << s.minCut("abb") << endl;
    cout << s.minCut("fifgbeajcacehiicccfecbfhhgfiiecdcjjffbghdidbhbdbfbfjccgbbdcjheccfbhafehieabbdfeigbiaggchaeghaijfbjhi") << endl;
    return 0;
}

