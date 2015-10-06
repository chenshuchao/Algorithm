#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
    public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();

        if(len1 == 0) return len2;
        if(len2 == 0) return len1;

        int m = len1 + 1;
        int n = len2 + 1;
        int *matrix = new int[m * n];
        for(int i = 0; i < m; i++)
            matrix[i*n] = i;
        for(int j = 0; j < n; j++)
            matrix[j] = j;

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(word1[i-1] == word2[j-1]) {
                    matrix[i*n + j] = matrix[(i-1)*n + j-1];
                } else {
                    matrix[i*n+j] = min(matrix[(i-1)*n+j-1], min(matrix[(i-1)*n+j], matrix[i*n+j-1])) + 1;
                }
            }
        }

        int minDist = matrix[m*n-1];
        delete[] matrix;
        return minDist;
    }
};

int main() {

    Solution s;
    //cout << s.minDistance("", "abc") << endl;
    //cout << s.minDistance("a", "a") << endl;
    cout << s.minDistance("a", "ab") << endl;
   // cout << s.minDistance("ab", "abc") << endl;
    return 0;
}

