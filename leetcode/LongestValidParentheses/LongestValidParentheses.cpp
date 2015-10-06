#include <iostream>
#include <stack>
using namespace std;

class Solution {
    public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        stk.push(-1);
        int maxSum = 0;
        for(int i = 0, len = s.length(); i < len; i++) {
            int t = stk.top();
            if(t != -1 && s[i] == ')' && s[t] == '('){
                stk.pop();
                maxSum = max(maxSum, i - stk.top());
            } else {
                stk.push(i);
            }
        }
        return maxSum;
    }
};

int main() {
    
    Solution s;
    printf("%d\n", s.longestValidParentheses("()()"));
    return 0;
}

