#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
    bool exist(vector<vector<char> >& board, string word) {
        int len = word.size();
        if(!len) return true;
        int m = board.size();
        if(!m) return false;
        int n = board[0].size();
        if(!n) return false;

        vector< vector<int> > mask(m, vector<int>(n, 0));
        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == word[0]) {
                    for(int k = 0; k < m; k++)
                        for(int t = 0; t < n; t++)
                            mask[k][t] = 0;
                    //vector<vector<int> > isUsed = mask;
                    if (dfs_search(board, i, j, mask, word, 0)) return true;
                }
            }
        }
        return false;
    }
    bool dfs_search(vector<vector<char> >& board, int row, int col, vector<vector<int> >& isUsed, string word, int index) {

        if(isUsed[row][col] == 0 && board[row][col] == word[index]) {
            isUsed[row][col] = 1;
            if(index == word.size() - 1) return true;
            index ++;

            if((row > 0 && dfs_search(board, row-1, col, isUsed, word, index)) ||
                (row+1 < board.size() && dfs_search(board, row+1, col, isUsed, word, index)) ||
                (col > 0 &&  dfs_search(board, row, col-1, isUsed ,word, index)) ||
                (col+1 < board[row].size() && dfs_search(board, row, col+1, isUsed ,word, index))) {
                    return true;
                }
            isUsed[row][col] = 0;
        }

        return false;
    }
};

void printVV(vector<vector<char> > vv) {
    for(int i = 0; i < vv.size(); i++) {
        for(int j = 0; j < vv[i].size(); j++) {
            cout << vv[i][j] << " ";
        }
        cout << endl;
    }
}


int main() {
/*
    char arr1[] = "ABCE";
    char arr2[] = "SFCS";
    char arr3[] = "ADEE";
    char arr4[] = {};
    
    vector<char> v1(arr1, arr1 + sizeof(arr1)/sizeof(char));
    vector<char> v2(arr2, arr2 + sizeof(arr2)/sizeof(char));
    vector<char> v3(arr3, arr3 + sizeof(arr3)/sizeof(char));
    vector<char> v4(arr4, arr4 + sizeof(arr4)/sizeof(char));
*/
    char arr1[] = "aaa";
    char arr2[] = "abb";
    char arr3[] = "abb";
    char arr4[] = "bbb";
    char arr5[] = "bbb";
    char arr6[] = "aaa";
    char arr7[] = "bbb";
    char arr8[] = "abb";
    char arr9[] = "aab";
    char arr10[] = "aba";

    vector<char> v1(arr1, arr1 + sizeof(arr1)/sizeof(char));
    vector<char> v2(arr2, arr2 + sizeof(arr2)/sizeof(char));
    vector<char> v3(arr3, arr3 + sizeof(arr3)/sizeof(char));
    vector<char> v4(arr4, arr4 + sizeof(arr4)/sizeof(char));
    vector<char> v5(arr5, arr5 + sizeof(arr5)/sizeof(char));
    vector<char> v6(arr6, arr6 + sizeof(arr6)/sizeof(char));
    vector<char> v7(arr7, arr7 + sizeof(arr7)/sizeof(char));
    vector<char> v8(arr8, arr8 + sizeof(arr8)/sizeof(char));
    vector<char> v9(arr9, arr9 + sizeof(arr9)/sizeof(char));
    vector<char> v10(arr10, arr10 + sizeof(arr10)/sizeof(char));
    vector<vector<char> > vv;
    vv.push_back(v1);
    vv.push_back(v2);
    vv.push_back(v3);
    vv.push_back(v4);
    vv.push_back(v5);
    vv.push_back(v6);
    vv.push_back(v7);
    vv.push_back(v8);
    vv.push_back(v9);
    vv.push_back(v10);

    printVV(vv);

    Solution s;
/*
    cout << s.exist(vv, "ABCCED") << endl;
    cout << s.exist(vv, "SEE") << endl;
    cout << s.exist(vv, "ABCB") << endl;
 */   
    cout << s.exist(vv, "aabaaaabbb") << endl;
    return 0;
}

