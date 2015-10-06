#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char> >& board) {
        int row[9][9] = {0};
        int col[9][9] = {0};
        int arr[3][3][9] = {0};
        int num;
        for(int r = 0; r < 9; r++) {
            for(int c = 0; c < 9; c++) {
                if(board[r][c] != '.') {
                    num = board[r][c] - '1';
                    if(row[r][num] ++) return false;
                    if(col[c][num] ++) return false;
                    if(arr[r/3][c/3][num] ++) return false;
                }
            }
        }
        return true;
    }
};

void printVector(vector<int> v) {
    for(int i = 0; i < v.size(); i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}
int main() {
  
    int arr[] = {0, 1, 2, 3, 5};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(int));
    printVector(v);
    
    Solution s;
    return 0;
}

