#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int totalNQueens(int n) {
        if(n == 0) return 0;
        vector<bool> col(n, true);
        vector<bool> toRightDown(2*n-1, true);
        vector<bool> toLeftDown(2*n-1, true);
        int count = 0;
        dfs(0, col, toRightDown, toLeftDown, count); 
        return count;
    }
    void dfs(int i, vector<bool> &col, vector<bool> &toRightDown, vector<bool> &toLeftDown, int &count) {
        int n = col.size();
        if(i == n) {
            count ++;
            return;
        }
        for(int j = 0; j < n; j ++) {
            if(col[j] && toRightDown[i+(n-1-j)] && toLeftDown[i+j]) {
                col[j] = toRightDown[i+(n-1-j)] = toLeftDown[i+j] = false;
                dfs(i+1, col, toRightDown, toLeftDown, count);
                col[j] = toRightDown[i+(n-1-j)] = toLeftDown[i+j] = true;
            }
        }
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
    cout << s.totalNQueens(2) << endl;
    cout << s.totalNQueens(4) << endl;
    cout << s.totalNQueens(8) << endl;
    return 0;
}

