#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    public:
    void helper(string str, int left, int right) {
        if(left <= 0 && right <=0) result.push_back(str);

        if(left > 0) helper(str+"(", left - 1, right);
        if(left < right) helper(str+")", left, right - 1); 
    }
    vector<string> generateParenthesis(int n) {
        helper("", n, n);
        return result;    
    }

    private:
    vector<string> result;
};

int main() {
    Solution s;
    vector<string> res = s.generateParenthesis(4);
    for(auto i = res.begin(); i != res.end(); ++i) {
        cout << *i << endl;
    }
}
