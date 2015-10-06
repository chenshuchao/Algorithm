#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char> >& matrix) {
        int m = matrix.size();
        if(!m) return 0;
        int n = matrix[0].size();
        if(!n) return 0;
       
        vector<int> height(n, 0);
        vector<int> left(n, 0);
        vector<int> right(n, n); 
        int area = 0;
        for(int i = 0; i < m; i ++) {
            int curLeft = 0, curRight = n;

            for(int j = 0; j < n; j ++) {
                if(matrix[i][j] == '1') {
                    height[j] ++;
                } else {
                    height[j] = 0;
                }
            }
            for(int j = 0; j < n; j ++) {
                if(matrix[i][j] == '1') {
                    left[j] = max(left[j], curLeft);
                } else {
                    left[j] = 0;
                    curLeft = j + 1;
                }
            }
            for(int j = n-1; j >= 0; j --){
                if(matrix[i][j] == '1') {
                    right[j] = min(right[j], curRight);
                } else {
                    right[j] = n;
                    curRight = j;
                }
            }
            for(int j = 0; j < n; j ++) 
                area = max(area, height[j] * (right[j] - left[j]));
        }
        return area;
    }
};

void printVector(vector<char> v) {
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}
void printVV(vector<vector<char> > vv) {
    for(int i = 0; i < vv.size(); i++) {
        for(int j = 0; j < vv[i].size(); j++) {
            cout << vv[i][j] << " ";
        }
        cout << endl;
    }
}


int main() {

    char arr1[] = "0110";
    char arr2[] = "0111";
    char arr3[] = "1001";
    char arr4[] = "1011";
    
    vector<char> v1(arr1, arr1 + sizeof(arr1)/sizeof(char));
    vector<char> v2(arr2, arr2 + sizeof(arr2)/sizeof(char));
    vector<char> v3(arr3, arr3 + sizeof(arr3)/sizeof(char));
    vector<char> v4(arr4, arr4 + sizeof(arr4)/sizeof(char));
    vector<vector<char> > vv;
    vv.push_back(v1);
    vv.push_back(v2);
    vv.push_back(v3);
    vv.push_back(v4);

    Solution s;
    cout << s.maximalRectangle(vv) << endl;
    
    return 0;
}

