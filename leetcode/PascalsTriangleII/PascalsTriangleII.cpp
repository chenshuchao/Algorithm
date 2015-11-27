#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> v;
        if(rowIndex < 0) return v;
        for(int i = 0; i <= rowIndex; i ++) {
            v.push_back(1);
            for(int j = v.size()-2; j > 0; j --) {
                v[j] = v[j] + v[j-1];
            }   
        }   
        return v;
    }
};

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

int main() {

    Solution s;
    printV(s.getRow(3)); 
    return 0;
}

