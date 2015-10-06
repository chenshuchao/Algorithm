#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int minPathSum(vector<vector<int> > &grid) {
            int m = grid.size();
            if(m == 0) return 0;
            int n = grid[0].size();
            if(n == 0) return 0;

            int *matrix = new int[m*n];
            matrix[0] = grid[0][0];
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    if(i == 0 && j == 0) continue;

                    if(i == 0) {
                        matrix[i*n+j] = matrix[i*n+j-1] + grid[i][j];
                    } else if(j == 0) {
                        matrix[i*n+j] = matrix[(i-1)*n+j] + grid[i][j];
                    } else {
                        matrix[i*n+j] = min(matrix[i*n+j-1], matrix[(i-1)*n+j]) + grid[i][j];
                    }
                    
                }
            }
            int minSum = matrix[m*n-1];
            delete[] matrix;
            return minSum;
        }
    private:
        int min(int x, int y) {
            return x < y ? x : y;
        }
};

int main() {

    int arr1[] = {0, 0, 0};
    int arr2[] = {0, 1, 1};
    int arr3[] = {0, 0, 0};

    vector<int> v1(arr1, arr1 + sizeof(arr1)/sizeof(int));
    vector<int> v2(arr2, arr2 + sizeof(arr2)/sizeof(int));
    vector<int> v3(arr3, arr3 + sizeof(arr3)/sizeof(int));

    vector<vector<int> > vv;
    vv.push_back(v1);
    vv.push_back(v2);
    vv.push_back(v3);
    

    Solution s;
    cout << s.minPathSum(vv) << endl;
    return 0;
}

