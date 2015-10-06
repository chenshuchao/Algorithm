#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > vv;
        for(int i = 0; i < n; i++) {
            vector<int> v(n, 0);
            vv.push_back(v);
        }
        int row = n, col = n;
        int pos = 0;
        int countNum = 1;
        while(pos < row && pos < col) {
            int i = pos;
            int j = pos;

            for(; j < col; j++) {
                vv[pos][j] = countNum ++;
            }
            if(row - 1 <= pos) break;
            for(i = pos+1; i < row; i++){
                vv[i][col-1] = countNum ++;
            }
            col --;
            
            if(col - 1 < pos) break;
            for(j = col-1; j >= pos; j--) {
                vv[row-1][j] = countNum ++;
            }
            row --;

            if(row - 1 <= pos) break;
            for(i = row-1; i > pos; i--) {
                vv[i][pos] = countNum ++;
            }
            pos ++;
        }
        return vv;
    }
};


int main() {

    Solution s;
    vector<vector<int> > vv = s.generateMatrix(0);
    for(int i = 0; i < vv.size(); i++) {
        for(int j = 0; j < vv[i].size(); j++)
            cout << vv[i][j] << " ";
        cout << endl;
    }
    return 0;
}
