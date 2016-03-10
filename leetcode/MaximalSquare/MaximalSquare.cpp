#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maximalSquare(vector<vector<char> >& matrix) {
    int row = matrix.size();
    if (row == 0) return 0;
    int col = matrix[0].size();
    if (col == 0) return 0;
    vector<vector<int> > dp(row+1, vector<int>(col+1, 0));
    int max_area = 0;
    for (int i = 1; i <= row; i ++) {
      for (int j = 1; j <= col; j ++) {
        if (matrix[i-1][j-1] == '1') {
          dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
          if (dp[i][j] > max_area) max_area = dp[i][j];
        }
      }
    }
    return max_area * max_area;
  }
};

int main() {
    char arr1[] = {'1', '0', '0', '0', '1'};
    char arr2[] = {'1', '0', '1', '1', '0'};
    char arr3[] = {'1', '1', '1', '1', '0'};
    char arr4[] = {'1', '0', '1', '0', '0'};
    char arr5[] = {'1', '0', '1', '0', '1'};
    vector<char> v1(arr1, arr1 + sizeof(arr1)/sizeof(char));
    vector<char> v2(arr2, arr2 + sizeof(arr2)/sizeof(char));
    vector<char> v3(arr3, arr3 + sizeof(arr3)/sizeof(char));
    vector<char> v4(arr4, arr4 + sizeof(arr4)/sizeof(char));
    vector<char> v5(arr5, arr5 + sizeof(arr5)/sizeof(char));

    vector<vector<char> > matrix;
    matrix.push_back(v1);
    matrix.push_back(v2);
    matrix.push_back(v3);
    matrix.push_back(v4);
    matrix.push_back(v5);

    Solution s;
    cout << s.maximalSquare(matrix) << endl;
    
    return 0;
}

