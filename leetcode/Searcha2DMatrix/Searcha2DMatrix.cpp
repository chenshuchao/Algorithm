#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        int m = matrix.size();
        if(!m) return false;
        int n = matrix[0].size();
        if(!n) return false;

        if(target < matrix[0][0] || target > matrix[m-1][n-1]) return false;
        int pos1 = 0;
        int pos2 = m-1;
        int rowMid = pos1;
        while(pos1 <= pos2) {
            rowMid = (pos1 + pos2) / 2;
            if(target > matrix[rowMid][n-1]) {
                pos1 = rowMid + 1; 
            } else if(target < matrix[rowMid][0]) {
                pos2 = rowMid - 1;
            } else {
                break;
            }
        }
        int left = 0, right = n - 1;
        while(left <= right) {
            int mid = (left + right) / 2;
            if(target == matrix[rowMid][mid]) {
                return true;
            } else if(target < matrix[rowMid][mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return false;
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

    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {10, 11, 16, 20};
    int arr3[] = {23, 30, 34, 50};
    int arr4[] = {70, 81, 92, 100};
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
    cout << s.searchMatrix(vv, 0) << endl;
    cout << s.searchMatrix(vv, 101) << endl;
    cout << s.searchMatrix(vv, 99) << endl;
    cout << s.searchMatrix(vv, 1) << endl;
    cout << s.searchMatrix(vv, 100) << endl;
    cout << s.searchMatrix(vv, 34) << endl;
    cout << s.searchMatrix(vv, 3) << endl;

    return 0;
}

