#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > vv;
        if(numRows == 0) return vv;
        vv.push_back(vector<int>(1,1));
        for(int i = 2; i <= numRows; i ++) {
            vector<int> v(i, 0);
            v[0] = vv[i-2][0];
            v[i-1] = vv[i-2][i-2];
            for(int j = 1; j < vv[i-2].size(); j ++) {
                v[j] = vv[i-2][j-1] + vv[i-2][j];
            }
            vv.push_back(v);
        }
        return vv;
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
    printVV(s.generate(5)); 
    return 0;
}

