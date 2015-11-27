#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int len_s = s.size();
        int len_t = t.size();
        if(len_s < len_t) return 0;
        vector<vector<int> > dp(len_t+1, vector<int>(len_s+1, 0));
        for(int i = 0; i <= len_s; i ++) {
            dp[0][i] = 1;
        }
        for(int i = 1; i <= len_t; i ++) {
            for(int j = 1; j <= len_s; j ++) {
                dp[i][j] = dp[i][j-1] + (s[j-1] == t[i-1] ? dp[i-1][j-1] : 0);
            }
        }
        return dp[len_t][len_s];
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

    int arr1[] = {};
    vector<int> v1(arr1, arr1 + sizeof(arr1)/sizeof(int));

    Solution s;
    cout << s.numDistinct("rabbbit", "rabbit") << endl;
    return 0;
}

