#include <iostream>
#include <vector>

using namespace std;
class NumMatrix {
 public:
  NumMatrix(vector<vector<int> > &matrix) {
    int row = matrix.size();
    if (row == 0) return;
    int col = matrix[0].size();

    sum_ = vector<vector<int> >(row+1, vector<int>(col+1, 0));
/*
    for (int i = 1; i <= col; i ++) {
      sum_[0][i] = matrix[0][i-1];
    }
    for (int i = 1; i <= row; i ++) {
      sum_[i][0] = matrix[i-1][0];
    }

*/
    for (int i = 1; i <= row; i ++) {
      for (int j = 1; j <= col; j ++) {
        sum_[i][j] = sum_[i-1][j] + sum_[i][j-1] - sum_[i-1][j-1] + matrix[i-1][j-1];
      }
    }
  }
  int sumRegion(int row1, int col1, int row2, int col2) {
    return sum_[row2+1][col2+1] - sum_[row1][col2+1] - sum_[row2+1][col1] + sum_[row1][col1];
  }
 private:
  vector<vector<int> > sum_;
};

int main() {
    int arr1[] = {3, 0, 1, 4, 2};
    int arr2[] = {5, 6, 3, 2, 1};
    int arr3[] = {1, 2, 0, 1, 5};
    int arr4[] = {4, 1, 0, 1, 7};
    int arr5[] = {1, 0, 3, 0, 5};
    vector<int> v1(arr1, arr1 + sizeof(arr1)/sizeof(int));
    vector<int> v2(arr2, arr2 + sizeof(arr2)/sizeof(int));
    vector<int> v3(arr3, arr3 + sizeof(arr3)/sizeof(int));
    vector<int> v4(arr4, arr4 + sizeof(arr4)/sizeof(int));
    vector<int> v5(arr5, arr5 + sizeof(arr5)/sizeof(int));

    vector<vector<int> > matrix;
    matrix.push_back(v1);
    matrix.push_back(v2);
    matrix.push_back(v3);
    matrix.push_back(v4);
    matrix.push_back(v5);

    NumMatrix numArray(matrix);
    cout << numArray.sumRegion(0, 0, 0, 0) << endl;
    cout << numArray.sumRegion(0, 1, 2, 3) << endl;
    cout << numArray.sumRegion(2, 1, 4, 3) << endl;
    cout << numArray.sumRegion(1, 1, 2, 2) << endl;
    cout << numArray.sumRegion(1, 2, 2, 4) << endl;
    return 0;
}

