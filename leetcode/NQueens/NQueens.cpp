#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > vv;
        vector<string> v;
        helper(vv, v, n);
        return vv; 
    }
    void helper(vector<vector<string> > &vv, vector<string> &v, int n) {
        int len = v.size();
        if(len == n) {
            vv.push_back(v);
            return;
        }
        string s(n, '.');
        for(int i = 0; i < n; i ++) {
            bool flag = false;
            for(int j = 0; j < len; j ++) {
                if(v[j][i] == 'Q') {
                    flag = true;
                    break;
                }
            }
            if(flag) continue;
            for(int j = len-1, k = i+1; j >= 0 && k < n; j --, k ++) {
                if(v[j][k] == 'Q') {
                    flag = true;
                    break;
                }
            }
            if(flag) continue;
            for(int j = len-1, k = i-1; j >= 0 && k >= 0; j --, k --) {
                if(v[j][k] == 'Q') {
                    flag = true;
                    break;
                }
            }
            if(flag) continue;
            s[i] = 'Q';
            v.push_back(s);
            helper(vv, v, n);
            v.pop_back();
            s[i] = '.';
        }
    }
};

template <typename T>
void printV(const vector<T>& v) {
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << endl;
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
    vector<vector<string> > res = s.solveNQueens(0);
    printVV(res);

    return 0;
}

