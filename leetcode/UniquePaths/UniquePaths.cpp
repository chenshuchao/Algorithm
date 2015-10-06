#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
    int uniquePaths(int m, int n) {
        if(m <= 0) return 0;
        if(n <= 0) return 0;

        int *matrix = new int[m*n];
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 || j == 0) {
                    matrix[i*n+j] = 1;
                } else {
                    matrix[i*n+j] = matrix[i*n+j-1] + matrix[(i-1)*n+j];
                }
            }
        }
        int res = matrix[m*n-1];
        delete[] matrix;
        return res;
    }
};

int main() {

    int m = 3, n = 1;
    Solution s;
    cout << s.uniquePaths(m, n) << endl;
    return 0;
}

