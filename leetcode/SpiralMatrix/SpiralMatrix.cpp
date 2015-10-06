#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> v;
        int m = matrix.size();
        if(m == 0) return v;
        int n = matrix[0].size(); 
        if(n == 0) return v; 
        int pos = 0;
        while(pos < m && pos < n) {
            int i, j;

            for(j = pos; j < n; j++)
                v.push_back(matrix[pos][j]);

            if(m <= pos+1) break;
            for(i = pos+1; i < m; i++)
                v.push_back(matrix[i][n-1]);
            n--;

            if(n < pos+1) break;
            for(j = n-1; j >= pos; j--)
                v.push_back(matrix[m-1][j]);
            m--;

            if(m <= pos+1) break;
            for(i = m-1; i > pos; i--)
                v.push_back(matrix[i][pos]);

            pos ++;
        }
        return v;
    }
};

int main() {

    int arr1[] = {0, 1, 2};
    int arr2[] = {10, 11, 12};
    int arr3[] = {20, 21, 22};
    int arr4[] = {30, 31, 32};

    vector<int> v1(arr1, arr1 + sizeof(arr1)/sizeof(int));
    vector<int> v2(arr2, arr2 + sizeof(arr2)/sizeof(int));
    vector<int> v3(arr3, arr3 + sizeof(arr3)/sizeof(int));
    vector<int> v4(arr4, arr4 + sizeof(arr4)/sizeof(int));

    vector<vector<int> > vv;
    vv.push_back(v1);
    vv.push_back(v2);
    vv.push_back(v3);
    vv.push_back(v4);

    Solution s;
    vector<int> res = s.spiralOrder(vv);
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << endl;

    return 0;
}
