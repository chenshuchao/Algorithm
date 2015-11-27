#include <iostream>
#include <vector>

using namespace std;
template <typename T>
void printV(const vector<T>& v) {
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

template <typename T>
void printVV(const vector<vector<T> >& vv) {
    for(int i = 0; i < vv.size(); i++) {
        printV(vv[i]);
    }
}
class Solution {
public:
    void solve(vector<vector<char> >& board) {
        int rows = board.size();
        int cols = board.size();
        if(rows < 3 || cols < 3) return;

        vector<int> top(cols-2, rows);
        vector<int> down(cols-2, -1);
        vector<int> left(rows-2, cols);
        vector<int> right(rows-2, -1);

        for(int j = 1; j < cols-1; j ++) {
            int i = 0;
            while(i < cols && board[i][j] != 'X') i ++;
            if(i != rows) {
                top[j-1] = i;
            }
            i = rows-1;
            while(i >= 0 && board[i][j] != 'X') i --;
            if(i >= 0) {
                down[j-1] = i;
            }
        }
        for(int i = 1; i < rows-1; i ++) {
            int j = 0;
            while(j < cols && board[i][j] != 'X') j ++;
            if(j != cols) {
                left[i-1] = j;
            }
            j = cols-1;
            while(j >= 0 && board[i][j] != 'X') j --;
            if(j >= 0) {
                right[i-1] = j;
            }
        }
        for(int i = 1; i < rows-1; i ++) {
            for(int j = 1; j < cols-1; j ++) {
                if(board[i][j] == 'O' && left[i-1] < j && right[i-1] > j && top[j-1] < i && down[j-1] > i) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

int main() {

    char arr1[] = {'X', 'X', 'X', 'X'};
    char arr2[] = {'X', 'O', 'O', 'X'};
    char arr3[] = {'X', 'X', 'O', 'X'};
    char arr4[] = {'X', 'O', 'X', 'X'};
    vector<char> v1(arr1, arr1 + sizeof(arr1)/sizeof(char));
    vector<char> v2(arr2, arr2 + sizeof(arr2)/sizeof(char));
    vector<char> v3(arr3, arr3 + sizeof(arr3)/sizeof(char));
    vector<char> v4(arr4, arr4 + sizeof(arr4)/sizeof(char));
    vector<vector<char> > vv;
    vv.push_back(v1);
    vv.push_back(v2);
    vv.push_back(v3);
    vv.push_back(v4);

    printVV(vv);
    Solution s;
    s.solve(vv);
    printVV(vv);
    
    return 0;
}

