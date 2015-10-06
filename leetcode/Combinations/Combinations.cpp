#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > vv;
        vector<int> v;
        if(n == 0 || k == 0) return vv;
        helper(vv, v, n, k, 0);
        return vv;
    }
    private:
    void helper(vector<vector<int> >& vv, vector<int>& v, int n, int k, int index) {
        if(k == 0) {
            vv.push_back(v);
            return;
        }
        for(int i = index+1; i <= n-k+1; i++) {
            v.push_back(i);
            helper(vv, v, n, k-1, i);
            v.pop_back();
        }
    }
};

void printVV(vector<vector<int> > vv) {
    for(int i = 0; i < vv.size(); i++) {
        for(int j = 0; j < vv[i].size(); j++) {
            cout << vv[i][j] << " ";
        }
        cout << endl;
    }
}


int main() {

    Solution s;
    vector<vector<int> > vv = s.combine(3, 1);
    printVV(vv);
    
    return 0;
}

