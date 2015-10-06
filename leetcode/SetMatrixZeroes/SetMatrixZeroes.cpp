#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    void setZeroes(vector<vector<int> >& matrix) {
        int m = matrix.size();
        if(!m) return;
        int n = matrix[0].size();
        if(!n) return;

        bool lastRowZero = false;
        bool curRowZero = false;
        for(int i = 0; i < m; i++) {
            lastRowZero = curRowZero;
            curRowZero = false;
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0) {
                    curRowZero = true;
                    for(int k = i; k >= 0; k--)
                        matrix[k][j] = 0;
                    continue;
                }
                if(i > 0 && matrix[i-1][j] == 0) matrix[i][j] = 0;
            }
            if(i > 0 && lastRowZero) {
                for(int j = 0; j < n; j++) matrix[i-1][j] = 0;
            }
            if(i == m-1 && curRowZero) {
                for(int j = 0; j < n; j++) matrix[i][j] = 0; 
            }
        }
    }
};

void printvv(vector<vector<int> >& vv) {
    for(int i = 0; i < vv.size(); i++) {
        for(int j = 0; j < vv[i].size(); j++) {
            cout << vv[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {

    int arr1[] = {1, 1, 1, 0};
    int arr2[] = {1, 1, 1, 1};
    int arr3[] = {1, 0, 0, 1};
    int arr4[] = {1, 1, 1, 1};
    vector<int> v1(arr1, arr1 + sizeof(arr1)/sizeof(int));
    vector<int> v2(arr2, arr2 + sizeof(arr2)/sizeof(int));
    vector<int> v3(arr3, arr3 + sizeof(arr3)/sizeof(int));
    vector<int> v4(arr4, arr4 + sizeof(arr4)/sizeof(int));

    vector<vector<int> > vv;
    vv.push_back(v1);
    vv.push_back(v2);
    vv.push_back(v3);
    vv.push_back(v4);
   
    printvv(vv);

    Solution s;
    s.setZeroes(vv);

    printvv(vv);
    
    return 0;
}

