#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<string> > partition(string s) {
        vector<string> temp;
        vector<vector<string> > res;
        helper(temp, res, s, 0);
        return res; 
    }
    void helper(vector<string>& temp, vector<vector<string> >& res, string &s, int index) {
        if(index == s.size()) {
            res.push_back(temp);
            return;
        }
        int n = s.size();
        for(int i = index; i < n; i ++) {
            int l = index, r = i;
            while(l <= r && s[l] == s[r]) {
                l ++;
                r --;
            }
            if(l >= r) {
                temp.push_back(s.substr(index, i-index+1));
                helper(temp, res, s, i+1);
                temp.pop_back();
            }
        }
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
    vector<vector<string> > res = s.partition("aab");
    printVV(res);
 
    return 0;
}

